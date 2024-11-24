struct Button_State
{
    bool is_down;
    bool is_changed;
};

enum
{
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_SHIFT,

    BUTTON_COUNT, // Should be last line
};

struct Input
{
    Button_State buttons[BUTTON_COUNT];
};