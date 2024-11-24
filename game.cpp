#define is_down(b) input->buttons[b].is_down
#define is_pressed(b) (input->buttons[b].is_down && input->buttons[b].is_changed)
#define is_released(b) (!input->buttons[b].is_down && input->buttons[b].is_changed)

float player_pos, speed;

static void simulate_game(Input *input, float dt)
{
    clear_screen(0xffffff);
    draw_rect(0, 0, 86, 45, 0xff0000);
    draw_rect(0, 0, 85, 45, 0x000000);

    float acc = 0.f;

    // Input handling
    is_down(BUTTON_UP) ? acc += 2000 : 0;
    is_down(BUTTON_DOWN) ? acc -= 2000 : 0;

    // Movement
    acc -= speed * 10.f;
    player_pos = player_pos + speed * dt + acc * dt * dt * 0.5f;
    speed = speed + acc * dt;

    // Ball
    draw_rect(0, 0, 1, 1, 0xff00ff);

    // Player
    draw_rect(80, player_pos, 2.5, 12, 0x00ff00);

    // Enemy
    draw_rect(-80, 0, 2.5, 12, 0x0000ff);
}