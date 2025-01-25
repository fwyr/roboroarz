void sensor_initialisation() {
  if ((my_robot.sm_getShape()) == ('i')) {
    right_sensor_status = my_robot.module1_sensor_status(6);
    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
    left_sensor_status = my_robot.module1_sensor_status(10);
    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
    movements();
  }

  if ((my_robot.sm_getShape()) == ('o')) {
    bottom_left_sensor_status = my_robot.module1_sensor_status(0);
    bottom_right_sensor_status = my_robot.module1_sensor_status(4);
    right_sensor_status = my_robot.module1_sensor_status(6);
    left_sensor_status = my_robot.module4_sensor_status(0);
    movements();
  }
}