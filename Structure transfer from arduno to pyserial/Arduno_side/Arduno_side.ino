struct IMU_data {
  // first acceleration
  float IMU_X = 1.1;
  float IMU_Y = 1.2;
  float IMU_Z = 1.3;

  // then gyroscope
  float GYR_X = 2.1;
  float GYR_Y = 2.2;
  float GYR_Z = 2.3;

  // then magnetometer
  float MAG_X = 3.1;
  float MAG_Y = 3.2;
  float MAG_Z = 3.3;
};

  // instanciate one struct
  IMU_data IMU_data_holder;
  
  // length of the structure
  int len_struct = sizeof(IMU_data_holder);

// send the structure giving the IMU state through serial
void send_IMU_struct() {
  Serial.write('S');
  Serial.write((uint8_t *)&IMU_data_holder, len_struct);
  Serial.write('E');
  return;
}
 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  send_IMU_struct();
}
