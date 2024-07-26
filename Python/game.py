import pygame
import random
import sys

# 초기화
pygame.init()

# 설정
WIDTH, HEIGHT = 300, 600  # 폭: 10칸, 높이: 20칸
BLOCK_SIZE = 30
GRID_WIDTH = WIDTH // BLOCK_SIZE
GRID_HEIGHT = HEIGHT // BLOCK_SIZE
FPS = 10

# 색상 정의
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)
YELLOW = (255, 255, 0)
ORANGE = (255, 165, 0)

# 화면 설정
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tetris")
clock = pygame.time.Clock()

# 테트로미노 클래스 정의
class Tetromino:
    shapes = [
        [[1, 1, 1, 1]],  # I
        [[1, 1, 1], [0, 1, 0]],  # T
        [[1, 1], [1, 1]],  # O
        [[0, 1, 1], [1, 1, 0]],  # S
        [[1, 1, 0], [0, 1, 1]],  # Z
        [[1, 1, 1], [1, 0, 0]],  # L
        [[1, 1, 1], [0, 0, 1]]   # J
    ]

    colors = [CYAN, MAGENTA, YELLOW, GREEN, RED, BLUE, ORANGE]

    def __init__(self):
        self.shape = random.choice(Tetromino.shapes)
        self.color = random.choice(Tetromino.colors)
        self.x = GRID_WIDTH // 2 - len(self.shape[0]) // 2
        self.y = 0

    def rotate(self):
        self.shape = [list(row) for row in zip(*self.shape[::-1])]

    def get_cells(self):
        return [(self.x + x, self.y + y) for y, row in enumerate(self.shape) for x, value in enumerate(row) if value]

# 그리드와 도형 그리기 함수 정의
def draw_grid():
    for x in range(0, WIDTH, BLOCK_SIZE):
        pygame.draw.line(screen, WHITE, (x, 0), (x, HEIGHT))
    for y in range(0, HEIGHT, BLOCK_SIZE):
        pygame.draw.line(screen, WHITE, (0, y), (WIDTH, y))

def draw_tetromino(tetromino):
    for x, y in tetromino.get_cells():
        pygame.draw.rect(screen, tetromino.color, (x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE))

def draw_board(board):
    for y, row in enumerate(board):
        for x, color in enumerate(row):
            if color:
                pygame.draw.rect(screen, color, (x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE))

def draw_score(score):
    font = pygame.font.SysFont(None, 36)
    text = font.render(f'Score: {score}', True, WHITE)
    screen.blit(text, (10, 10))

# 충돌 및 줄 삭제 함수 정의
def check_collision(board, tetromino):
    for x, y in tetromino.get_cells():
        if x < 0 or x >= GRID_WIDTH or y >= GRID_HEIGHT:
            return True
        if y >= 0 and board[y][x]:
            return True
    return False

def clear_lines(board):
    new_board = [row for row in board if any(cell == 0 for cell in row)]
    lines_cleared = GRID_HEIGHT - len(new_board)
    new_board = [[0] * GRID_WIDTH for _ in range(lines_cleared)] + new_board
    return new_board, lines_cleared

def merge_tetromino(board, tetromino):
    for x, y in tetromino.get_cells():
        if y >= 0:
            board[y][x] = tetromino.color

# 게임 루프 함수 정의
def main():
    board = [[0] * GRID_WIDTH for _ in range(GRID_HEIGHT)]
    current_tetromino = Tetromino()
    score = 0
    drop_time = pygame.time.get_ticks()
    fall_speed = 1000  # 초기 낙하 속도 (밀리초)

    while True:
        screen.fill(BLACK)
        draw_grid()
        draw_board(board)
        draw_tetromino(current_tetromino)
        draw_score(score)

        # 이벤트 처리
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_a:  # 왼쪽으로 이동
                    current_tetromino.x -= 1
                    if check_collision(board, current_tetromino):
                        current_tetromino.x += 1
                elif event.key == pygame.K_d:  # 오른쪽으로 이동
                    current_tetromino.x += 1
                    if check_collision(board, current_tetromino):
                        current_tetromino.x -= 1
                elif event.key == pygame.K_s:  # 아래로 이동
                    current_tetromino.y += 1
                    if check_collision(board, current_tetromino):
                        current_tetromino.y -= 1
                elif event.key == pygame.K_q:  # 회전
                    current_tetromino.rotate()
                    if check_collision(board, current_tetromino):
                        # 회전이 충돌할 때 원래 상태로 되돌림
                        current_tetromino.rotate()
                        current_tetromino.rotate()
                        current_tetromino.rotate()
                elif event.key == pygame.K_SPACE:  # 아래로 완전히 떨어뜨리기
                    while not check_collision(board, current_tetromino):
                        current_tetromino.y += 1
                    current_tetromino.y -= 1
                    merge_tetromino(board, current_tetromino)
                    board, lines_cleared = clear_lines(board)
                    score += lines_cleared * 100  # 줄당 100점 추가
                    current_tetromino = Tetromino()
                    if check_collision(board, current_tetromino):
                        print("Game Over!")
                        pygame.quit()
                        sys.exit()

        # 자동 낙하
        current_time = pygame.time.get_ticks()
        if current_time - drop_time > fall_speed:
            current_tetromino.y += 1
            if check_collision(board, current_tetromino):
                current_tetromino.y -= 1
                merge_tetromino(board, current_tetromino)
                board, lines_cleared = clear_lines(board)
                score += lines_cleared * 100  # 줄당 100점 추가
                current_tetromino = Tetromino()
                if check_collision(board, current_tetromino):
                    print("Game Over!")
                    pygame.quit()
                    sys.exit()
            drop_time = current_time

        pygame.display.flip()
        clock.tick(FPS)

if __name__ == "__main__":
    main()
