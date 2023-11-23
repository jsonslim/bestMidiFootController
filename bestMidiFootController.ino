#include <MIDI.h>
#include <vector>
#include <String>

#define buttonsNum 8

CtrlButton ctrlButtons[8] = {};

void initButtons()
{
  // read a preset from eeprom
  for (int i = 0; i < buttonsNum; i++)
  {
    ctrlButtons[i] = new CtrlButton();
  }
}

struct CtrlButtonPreset
{
  ButtonMode buttonMode;
  String name;
};

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
  int pin;
  ButtonMode buttonMode;
  String name;
  std::vector<Action> btnActions;
};

void setup()
{
  Serial.begin(115200);
  MIDI.begin(MIDI_CHANNEL);
  initButtons();
}

void loop()
{
}
