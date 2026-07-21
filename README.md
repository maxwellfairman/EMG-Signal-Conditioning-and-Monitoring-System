# Integrated EMG Device

- Designed, simulated, and validated an EMG signal-conditioning circuit in LTspice using a virtual ground, precision rectifier, and RC low-pass filter to extract the envelope from the MyoWare RAW output signal.
  - Signal chain: MyoWare RAW output → half-wave precision rectifier (centered at 1.58 V) → voltage adder → RC low-pass filter
- Built and tested the analog front end with an Arduino, breadboard, oscilloscope, and function generator, and integrated it with a MyoWare sensor for EMG acquisition.
- Developed Arduino firmware for real-time EMG acquisition, iEMG calculation, and configurable threshold-based alerts for monitoring forearm muscle activity.

<p align="center" width="100%">
Integrated EMG + buzzer alert to help prevent forearm overuse (threshold is set low for demonstration purposes; in practice, an alert would only trigger after 15–60 minutes of continuous use).

<video src="https://github.com/user-attachments/assets/263daff6-9c5d-4357-b7fb-59068fd469ef" width="80%" controls title="iEMG"></video>
</p>

<p align="center" width="100%">
Graph of the RAW signal (yellow), along with the rectified (pink) and smoothed (blue) signals.

<video src="https://github.com/user-attachments/assets/d5dcc8c1-0aa7-4633-89be-3b352f19fe44" width="80%" controls></video>
</p>
