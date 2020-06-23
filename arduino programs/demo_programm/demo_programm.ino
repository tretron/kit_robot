#define button_tool_rotate_pos 1
#define button_tool_rotate_neg 2
#define button_wrist_pos 3
#define button_writst_neg 4
#define stepper_tool_rotate_DIR 5
#define stepper_tool_rotate_PULSE 6
#define stepper_wrist_DIR 7
#define stepper_wrist_PULSE 8

const int buttons_joints[][2] = { {button_tool_rotate_pos, button_tool_rotate_neg}
                                  ,{button_wrist_pos,button_writst_neg}};
const int stepper_joints[][2] = { {stepper_tool_rotate_DIR,stepper_tool_rotate_PULSE},
                                  {stepper_wrist_DIR,stepper_wrist_PULSE}};
int stepper_speed = 50;

void setup() {
  set_joint_inputs(buttons_joints);
  set_stepper_outputs(stepper_joints);

}

void loop() {
  operate_steppers(buttons_joints, stepper_joints);
}

void set_input_pullup(int pins[]){
  for(int i=0; i<= (sizeof(pins)-1); i++){
    pinMode(pins[i], INPUT_PULLUP);
  }
}
void set_joint_inputs(int pins[][2]){
  for(int j=0; j<= (sizeof(pins)-1); j++){
    set_outputs(pins[j]);
  }
}
void set_stepper_outputs(int pins[][2]){
  for(int j=0; j<= (sizeof(pins)-1); j++){
    set_outputs(pins[j]);
  }
}

void set_outputs(int pins[]){
  for(int i=0; i<= (sizeof(pins)-1); i++){
    pinMode(pins[i], OUTPUT);
  }
}
void operate_steppers(int button_pins[][2], int stepper_pins[][2]){
  for(int i = 0; i <= sizeof(button_pins)-1; i++){
    move_joint(button_pins[i], stepper_pins[i]);
  }
}
void move_joint(int inputs[],int steppers[]){
  if (check_pressed(inputs[0]) == true){
    rotate_CCW(steppers);
  }
  else if (check_pressed(inputs[1]) == true){
    rotate_CW(steppers);
  }
}
void rotate_CCW(int steppers[]){
  digitalWrite(steppers[0], LOW);
  move_stepper(steppers[1]);
}
void rotate_CW(int steppers[]){
  digitalWrite(steppers[0], HIGH);
  move_stepper(steppers[1]);
}
void move_stepper(int pin){
  highpulse(pin);
  delayMicroseconds(stepper_speed);
  lowpulse(pin);
  delayMicroseconds(stepper_speed);
  highpulse(pin);
}
void highpulse(int pin){
  digitalWrite(pin, HIGH);
}
void lowpulse(int pin){
  digitalWrite(pin, LOW);
}
bool check_pressed(int pin){
  return(digitalRead(pin));
}
