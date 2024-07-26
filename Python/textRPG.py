import random
import os

# 캐릭터 클래스
class Character:
    def __init__(self, name, hp, attack):
        self.name = name
        self.max_hp = hp
        self.hp = hp
        self.attack = attack

    def is_alive(self):
        return self.hp > 0

    def reset_hp(self):
        self.hp = self.max_hp

# 플레이어 클래스
class Player(Character):
    def __init__(self, name):
        super().__init__(name, 100, 10)
        self.level = 1
        self.exp = 0
        self.skills = {
            "기본 공격": 1.0,
            "강한 공격": 1.5
        }

    def level_up(self):
        self.level += 1
        self.max_hp += 20
        self.hp = self.max_hp
        self.attack += 5
        print(f"\n레벨 업! 현재 레벨: {self.level}")
        print(f"최대 체력이 {self.max_hp}로 증가했습니다.")
        print(f"공격력이 {self.attack}로 증가했습니다.")

    def gain_exp(self, exp):
        self.exp += exp
        if self.exp >= self.level * 20:
            self.level_up()
            self.exp = 0

    def use_skill(self, skill_name):
        return int(self.attack * self.skills[skill_name])

# 몬스터 클래스
class Monster(Character):
    def __init__(self, name, hp, attack, exp):
        super().__init__(name, hp, attack)
        self.exp = exp

# 게임 클래스
class Game:
    def __init__(self):
        self.player = Player("전사")
        self.monsters = [
            Monster("네펜더스", 50, 5, 10),
            Monster("슬라임", 30, 3, 5)
        ]
        self.boss = Monster("마왕", 200, 20, 50)

    def clear_screen(self):
        os.system('cls' if os.name == 'nt' else 'clear')

    def display_stats(self):
        print(f"\n{'=' * 30}")
        print(f"이름: {self.player.name}  레벨: {self.player.level}")
        print(f"체력: {self.player.hp}/{self.player.max_hp}")
        print(f"공격력: {self.player.attack}")
        print(f"경험치: {self.player.exp}/{self.player.level * 20}")
        print(f"{'=' * 30}\n")

    def display_monster(self, monster):
        art = {
            "네펜더스": """
      ,o.          8 8
     d   b        d8o8b
    8     8      d88888b
    8  o  8     (88888888)
    8  o  8    d(888888888)b
    8  o  8   d88888888888b
    8     8  d888888888888b
     dooob   8888888888888
              88888888888
               888888888
                8888888
                 88888
                  888
                   8
            """,
            "슬라임": """
       _____
     .'     '.
    /  o   o  \\
   |    ᗜ     |
    \  '---'  /
     '._____.'
            """,
            "마왕": """
             /\
            /  \
           |    |
          /  /\  \\
         /  /  \  \\
        /  /    \  \\
       /  /     /\  \\
      /  /     /  \  \\
     /  /     /\   \  \\
    /  /     /  \   \  \\
   /  /     /    \   \  \\
  /  /     /      \   \  \\
 /  /     /        \   \  \\
/  /     /          \   \  \\
\  \    /            \  /  /
 \  \  /              \/  /
  \  \/               /  /
   \  \             /  /
    \  \           /  /
     \  \         /  /
      \  '_______'  /
       \_____________/
            """
        }
        print(art[monster.name])
        print(f"\n{monster.name}  체력: {monster.hp}/{monster.max_hp}")

    def fight(self, monster):
        monster.reset_hp()  # 몬스터 체력 초기화
        self.clear_screen()
        print(f"\n{monster.name}와(과) 전투를 시작합니다!")
        
        while monster.is_alive() and self.player.is_alive():
            self.display_stats()
            self.display_monster(monster)
            print("\n행동을 선택하세요:")
            print("1. 기본 공격")
            print("2. 강한 공격")
            print("3. 도망가기")
            
            action = input("선택: ")
            
            if action == "1":
                damage = self.player.use_skill("기본 공격")
                monster.hp -= damage
                print(f"\n기본 공격으로 {damage}의 데미지를 입혔습니다!")
            elif action == "2":
                damage = self.player.use_skill("강한 공격")
                monster.hp -= damage
                print(f"\n강한 공격으로 {damage}의 데미지를 입혔습니다!")
            elif action == "3":
                print("\n전투에서 도망쳤습니다.")
                return False
            else:
                print("\n잘못된 입력입니다. 다시 선택해주세요.")
                continue

            if not monster.is_alive():
                print(f"\n{monster.name}을(를) 물리쳤습니다!")
                self.player.gain_exp(monster.exp)
                return True

            # 몬스터의 공격
            player_damage = monster.attack
            self.player.hp -= player_damage
            print(f"\n{monster.name}의 공격! {player_damage}의 데미지를 받았습니다.")

            if not self.player.is_alive():
                print("\n게임 오버! 당신은 죽었습니다.")
                return False

        return True

    def fight_boss(self):
        self.boss.reset_hp()  # 보스 체력 초기화
        self.clear_screen()
        print("\n마왕과의 최종 결전을 시작합니다!")
        
        while self.boss.is_alive() and self.player.is_alive():
            self.display_stats()
            self.display_monster(self.boss)
            print("\n행동을 선택하세요:")
            print("1. 기본 공격")
            print("2. 강한 공격")
            print("3. 회복 (체력 30 회복)")
            print("4. 도망가기")
            
            action = input("선택: ")
            
            if action == "1":
                damage = self.player.use_skill("기본 공격")
                self.boss.hp -= damage
                print(f"\n기본 공격으로 {damage}의 데미지를 입혔습니다!")
            elif action == "2":
                damage = self.player.use_skill("강한 공격")
                self.boss.hp -= damage
                print(f"\n강한 공격으로 {damage}의 데미지를 입혔습니다!")
            elif action == "3":
                heal = 30
                self.player.hp = min(self.player.hp + heal, self.player.max_hp)
                print(f"\n체력을 {heal} 회복했습니다!")
            elif action == "4":
                print("\n마왕과의 전투에서 도망쳤습니다.")
                return False
            else:
                print("\n잘못된 입력입니다. 다시 선택해주세요.")
                continue

            if not self.boss.is_alive():
                print("\n축하합니다! 마왕을 물리치고 세상을 구했습니다!")
                return True

            # 보스의 공격
            player_damage = self.boss.attack
            self.player.hp -= player_damage
            print(f"\n마왕의 강력한 공격! {player_damage}의 데미지를 받았습니다.")

            if not self.player.is_alive():
                print("\n게임 오버! 당신은 마왕에게 패배했습니다.")
                return False

        return True

    def play(self):
        print("텍스트 RPG에 오신 것을 환영합니다!")
        print("당신은 세상을 구하기 위해 여행을 떠나는 전사입니다.")
        
        while self.player.is_alive():
            self.display_stats()
            print("\n무엇을 하시겠습니까?")
            print("1. 몬스터 사냥")
            print("2. 휴식 (체력 회복)")
            if self.player.level >= 5:
                print("3. 마왕과 대결")
            print("4. 종료")
            
            choice = input("선택: ")
            
            if choice == "1":
                monster = random.choice(self.monsters)
                self.fight(monster)
            elif choice == "2":
                heal = self.player.max_hp // 2
                self.player.hp = min(self.player.hp + heal, self.player.max_hp)
                print(f"\n휴식을 취했습니다. 체력이 {heal} 회복되었습니다.")
            elif choice == "3" and self.player.level >= 5:
                if self.fight_boss():
                    print("\n게임 클리어! 축하합니다!")
                    break
            elif choice == "4":
                print("\n게임을 종료합니다. 안녕히 가세요!")
                break
            else:
                print("\n잘못된 입력입니다. 다시 선택해주세요.")

        print("\n게임이 종료되었습니다.")

# 게임 실행
if __name__ == "__main__":
    game = Game()
    game.play()