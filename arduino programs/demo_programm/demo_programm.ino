#define button_tool_rotate_pos 1
#define button_tool_rotate_neg 2
#define button_wrist_pos 3
#define button_writst_neg 4
#define stepper_tool_rotate_DIR 5
#define stepper_tool_rotate_PULSE 6
#define stepper_wrist_DIR 7
#define stepper_wrist_PULSE 8

const int inputs[] = {button_tool_rotate_pos, button_tool_rotate_neg,button_wrist_pos,button_writst_neg};
const int stepper_joints[][2] = { {stepper_tool_rotate_DIR,stepper_tool_rotate_PULSE},
                                  {stepper_wrist_DIR,stepper_wrist_PULSE}};

void setup() {
  set_input_pullup(inputs);
  set_stepper_outputs(stepper_joints);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void set_input_pullup(int pins[]){
  for(int i=0; i<= (sizeof(pins)-1); i++){
    pinMode(pins[i], INPUT_PULLUP);
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
