void movements() {
  if (left_sensor_status == 0 && right_sensor_status == 0) {
    my_robot.MoveForward(straightSpeed);
  } else if (left_sensor_status == 0) {
    my_robot.CenterPivotRight(rightSpeed);
  } else if (right_sensor_status == 0) {
    my_robot.CenterPivotLeft(leftSpeed);
  } else {
    if (bottom_left_sensor_status == 1 && bottom_right_sensor_status == 0) {
      if (goingStraight) {
        my_robot.MoveForward(straightSpeed);
      } else if (goingRight) {
        my_robot.MoveTurnUpRight(rightSpeed, angV);
      } else if (goingLeft) {
        my_robot.MoveTurnUpLeft(leftSpeed, angV);
      } else {
        my_robot.CenterPivotLeft(leftSpeed);
      }
    } else if (bottom_left_sensor_status == 0 && bottom_right_sensor_status == 1) {
      if (goingStraight) {
        my_robot.MoveForward(straightSpeed);
      } else if (goingRight) {
        my_robot.MoveTurnUpRight(rightSpeed, angV);
      } else if (goingLeft) {
        my_robot.MoveTurnUpLeft(leftSpeed, angV);
      } else {
        my_robot.CenterPivotRight(rightSpeed);
      }
    } else {
      if (goingLeft) {
        my_robot.MoveTurnUpLeft(leftSpeed, angV);
      } else if (goingRight) {
        my_robot.MoveTurnUpRight(rightSpeed, angV);
      } else if (halfTurn) {
        my_robot.CenterPivotLeft(leftSpeed);
      } else {
        my_robot.MoveForward(straightSpeed);
      }
    }
  }
}