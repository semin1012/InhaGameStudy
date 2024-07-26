import pygame
import random
import sys

# 초기화
pygame.init()

# 화면 설정
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("픽셀 좀비 슈팅 게임")

# 색상 정의
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GRAY = (128, 128, 128)

# 프레임 설정
clock = pygame.time.Clock()
FPS = 60

# 폰트 설정
font = pygame.font.Font(None, 36)
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((30, 30))
        self.image.fill(WHITE)
        self.rect = self.image.get_rect()
        self.rect.center = (WIDTH // 2, HEIGHT // 2)
        self.speed = 5
        self.health = 100
        self.current_weapon = 0
        self.weapons = [
            {"name": "AK-47", "ammo": 30, "damage": 10},
            {"name": "MP5", "ammo": 25, "damage": 8},
            {"name": "Glock", "ammo": 15, "damage": 5},
            {"name": "Remington 870", "ammo": 8, "damage": 20},
            {"name": "Barrett M82A1", "ammo": 5, "damage": 50},
            {"name": "M72 LAW", "ammo": 1, "damage": 100},
            {"name": "GAU-17/A", "ammo": 100, "damage": 5},
        ]

    def move(self, dx, dy):
        self.rect.x += dx * self.speed
        self.rect.y += dy * self.speed
        self.rect.clamp_ip(screen.get_rect())

    def shoot(self):
        if self.weapons[self.current_weapon]["ammo"] > 0:
            self.weapons[self.current_weapon]["ammo"] -= 1
            return Bullet(self.rect.centerx, self.rect.centery, self.current_weapon)
        return None

    def switch_weapon(self, direction):
        self.current_weapon = (self.current_weapon + direction) % len(self.weapons)

class Zombie(pygame.sprite.Sprite):
    def __init__(self, is_devil):
        super().__init__()
        self.is_devil = is_devil
        self.image = pygame.Surface((20, 20))
        self.image.fill(RED if is_devil else GRAY)
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(0, WIDTH - self.rect.width)
        self.rect.y = random.randint(0, HEIGHT - self.rect.height)
        self.speed = 2 if is_devil else 1

    def move_towards_player(self, player):
        dx, dy = player.rect.x - self.rect.x, player.rect.y - self.rect.y
        dist = max(abs(dx), abs(dy))
        dx, dy = dx / dist, dy / dist
        self.rect.x += dx * self.speed
        self.rect.y += dy * self.speed

class Bullet(pygame.sprite.Sprite):
    def __init__(self, x, y, weapon_type):
        super().__init__()
        self.image = pygame.Surface((5, 5))
        self.image.fill(WHITE)
        self.rect = self.image.get_rect()
        self.rect.center = (x, y)
        self.speed = 10
        self.weapon_type = weapon_type

    def update(self):
        self.rect.y -= self.speed
        if self.rect.bottom < 0:
            self.kill()

class Item(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((15, 15))
        self.image.fill(RED)
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(0, WIDTH - self.rect.width)
        self.rect.y = random.randint(0, HEIGHT - self.rect.height)
def main():
    player = Player()
    all_sprites = pygame.sprite.Group(player)
    zombies = pygame.sprite.Group()
    bullets = pygame.sprite.Group()
    items = pygame.sprite.Group()

    zombie_spawn_timer = 0
    item_spawn_timer = 0

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    bullet = player.shoot()
                    if bullet:
                        bullets.add(bullet)
                        all_sprites.add(bullet)
                elif event.key == pygame.K_q:
                    player.switch_weapon(-1)
                elif event.key == pygame.K_e:
                    player.switch_weapon(1)

        keys = pygame.key.get_pressed()
        dx = keys[pygame.K_d] - keys[pygame.K_a]
        dy = keys[pygame.K_s] - keys[pygame.K_w]
        player.move(dx, dy)

        zombie_spawn_timer += 1
        if zombie_spawn_timer >= 60:
            zombie_spawn_timer = 0
            is_devil = random.random() < 0.2
            zombie = Zombie(is_devil)
            zombies.add(zombie)
            all_sprites.add(zombie)

        item_spawn_timer += 1
        if item_spawn_timer >= 300:
            item_spawn_timer = 0
            item = Item()
            items.add(item)
            all_sprites.add(item)

        for zombie in zombies:
            zombie.move_towards_player(player)

        # 충돌 감지
        for bullet in bullets:
            zombie_hit = pygame.sprite.spritecollide(bullet, zombies, True)
            if zombie_hit:
                bullet.kill()
                for zombie in zombie_hit:
                    if zombie.is_devil:
                        player.health += 10
                    else:
                        player.health += 5

        zombie_collisions = pygame.sprite.spritecollide(player, zombies, False)
        for zombie in zombie_collisions:
            player.health -= 4 if zombie.is_devil else 1
            if player.health <= 0:
                running = False

        item_collisions = pygame.sprite.spritecollide(player, items, True)
        for item in item_collisions:
            player.health = min(player.health + 20, 100)
            player.weapons[player.current_weapon]["ammo"] += 10

        all_sprites.update()

        # 화면 그리기
        screen.fill(BLACK)
        all_sprites.draw(screen)

        # HUD 표시
        health_text = font.render(f"체력: {player.health}", True, WHITE)
        weapon_text = font.render(f"무기: {player.weapons[player.current_weapon]['name']} ({player.weapons[player.current_weapon]['ammo']})", True, WHITE)
        screen.blit(health_text, (10, 10))
        screen.blit(weapon_text, (10, 50))

        pygame.display.flip()
        clock.tick(FPS)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()