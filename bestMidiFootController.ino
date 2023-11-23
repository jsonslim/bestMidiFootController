#include <MIDI.h>

enum ButtonMode
{
  MOMENTARY,
  LATCH
};

enum ButtonState
{
  UP,
  DOWN
};

class Action
{
  // can be anything that executes on btn press: sendMidi, change LED color, nothing, etc
};

class CtrlButton
{
public:
  CtrlButton(ButtonMode buttonMode)
  {
    this->buttonMode = buttonMode;
  }

  void handlePress()
  {
    for (auto action : this->btnActions)
    {
      action.fire();
    }
  }

private:
  ButtonMode buttonMode;
  String name;
  vector<Action> btnActions;
};

void setup()
{
  Serial.begin(115200);
  MIDI.begin(MIDI_CHANNEL);
}

void loop()
{
}
