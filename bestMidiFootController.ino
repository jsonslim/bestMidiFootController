#include <MIDI.h>
#include <vector>
#include <String>

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
  virtual void fire() = 0;
};

class SendMidiAction : public Action
{
public:
  void fire() override
  {
    // Implementation for sending MIDI
  }
};

class CtrlButton
{
public:
  CtrlButton(ButtonMode buttonMode, const String &name) : buttonMode(buttonMode), name(name) {}

  void addAction(const Action &action)
  {
    btnActions.push_back(action);
  }

  void handlePress()
  {
    for (auto &action : this->btnActions)
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
