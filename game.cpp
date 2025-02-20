#define is_down(b) input->buttons[b].is_down
#define is_pressed(b) (input->buttons[b].is_down && input->buttons[b].is_changed)
#define is_released(b) (!input->buttons[b].is_down && input->buttons[b].is_changed)

float p1_pos, p1_speed, p2_pos, p2_speed;
float player_height = 12, player_width = 2.5;
float arena_height = 45;
float ball_size = 1;
float ball_x, ball_y, ball_speed_x = 10, ball_speed_y;

static void simulate_game(Input *input, float dt)
{
    clear_screen(0x000000);
    draw_rect(0, 0, 86, arena_height, 0xff0000);
    draw_rect(0, 0, 85, arena_height, 0x111111);

    // P1 Movement
    float p1_acc = 0.f;
    is_down(BUTTON_W) ? p1_acc += 2000 : 0;
    is_down(BUTTON_S) ? p1_acc -= 2000 : 0;
    p1_acc -= p1_speed * 10.f;
    p1_pos = p1_pos + p1_speed * dt + p1_acc * dt * dt * 0.5f;
    p1_speed = p1_speed + p1_acc * dt;

    // P1 Collision
    if (p1_pos + player_height > arena_height)
    {
        p1_pos = arena_height - player_height;
        p1_speed *= -0.5f;
    }
    else if (p1_pos - player_height < -arena_height)
    {
        p1_pos = -arena_height + player_height;
        p1_speed *= -0.5f;
    }

    // P2 Movement
    float p2_acc = 0.f;
    is_down(BUTTON_UP) ? p2_acc += 2000 : 0;
    is_down(BUTTON_DOWN) ? p2_acc -= 2000 : 0;
    p2_acc -= p2_speed * 10.f;
    p2_pos = p2_pos + p2_speed * dt + p2_acc * dt * dt * 0.5f;
    p2_speed = p2_speed + p2_acc * dt;

    // P2 Collision
    if (p2_pos + player_height > arena_height)
    {
        p2_pos = arena_height - player_height;
        p2_speed *= -0.5f;
    }
    else if (p2_pos - player_height < -arena_height)
    {
        p2_pos = -arena_height + player_height;
        p2_speed *= -0.5f;
    }

    // Ball Movement
    ball_x += ball_speed_x * dt;
    ball_y += ball_speed_y * dt;

    // Ball
    draw_rect(ball_x, ball_y, ball_size, ball_size, 0xff00ff);

    // Ball Collision
    if (ball_x + ball_size > 80 - player_width &&
        ball_x - ball_size < 80 + player_width &&
        ball_y + ball_size > p1_pos - player_height &&
        ball_y - ball_size < p1_pos + player_height)
    {
        ball_x = 80 - player_width - ball_size;
        ball_speed_x *= -1;
    }

    // Player 1
    draw_rect(-80, p1_pos, player_width, player_height, 0x0000ff);

    // Player 2
    draw_rect(80, p2_pos, player_width, player_height, 0x00ff00);
}