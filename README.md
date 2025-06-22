# Icarus_Flight_Controller
A compact indoor drone flight controller built around the ESP32 microcontroller, designed specifically for brushed motor quadcopters. It integrates critical subsystems including an inertial measurement unit, motor control, battery management, and camera connectivity, making it ideal for small-scale autonomous or semi-autonomous aerial robotics.

Unlike off-the-shelf drone controllers that depend on external ESCs and bulky companion boards, this design is fully embedded — using two DRV8833 dual H-bridge drivers to directly control up to four brushed DC motors, enabling simplified hardware and reduced size and weight.

The ICM-42688 is the onboard IMU which provides real-time motion data (acceleration and angular velocity), allowing the controller to compute orientation and run stabilization algorithms like PID control. The OV2640 camera connector enables vision-based features such as image streaming, object tracking, and AI-based navigation — all within the capabilities of the ESP32.

Power is handled through a LiPo-compatible charging and regulation circuit, enabling safe USB C charging and efficient power delivery to the motors and logic systems. 

With native Wi-Fi and Bluetooth, the ESP32 facilitates wireless telemetry, OTA updates, and remote control via mobile or web-based applications.

This controller is ideal for:
	•	Indoor micro drones
	•	Swarm drone projects
	•	DIY autonomous quadcopters

Future iterations of this flight controller will expand its capabilities with additional onboard sensors, including time-of-flight (ToF) proximity sensors for obstacle avoidance, a barometer for accurate altitude hold, a magnetometer for compass-based heading correction, and an interface for GPS modules to enable outdoor and waypoint-based navigation. These enhancements will support more advanced flight behaviors such as autonomous path planning, hover stabilization, and vision-sensor fusion, while maintaining a compact form factor for both indoor and outdoor microdrone applications.
