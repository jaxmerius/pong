struct Button_State
{
    bool is_down;
    bool is_changed;
};

enum
{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_W,
    BUTTON_S,

    BUTTON_COUNT, // Should be last line
};

struct Input
{
    Button_State buttons[BUTTON_COUNT];
};