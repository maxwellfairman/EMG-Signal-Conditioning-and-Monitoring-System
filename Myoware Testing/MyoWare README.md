<p align="center" width="100%">
<b>Raw EMG Signal</b><br>
Amplified and biased to a 1.58 V virtual ground by the MyoWare sensor.
<video src="https://github.com/user-attachments/assets/ff61a4e0-5345-43ab-8351-14126cb93432" width="80%" controls></video>
</p>

<p align="center" width="100%">
<b>Rectified EMG Signal</b><br>
Output of the precision full-wave rectifier, converting the bipolar EMG waveform into a unipolar signal.
<video src="https://github.com/user-attachments/assets/6f1603f1-c087-4d85-b5ee-f1b137b88d05" width="80%" controls></video>
</p>

<p align="center" width="100%">
<b>Envelope Detection</b><br>
RC low-pass filter used to extract the EMG envelope. The envelope amplitude is attenuated relative to the rectified signal due to the passive filter implementation.
<video src="https://github.com/user-attachments/assets/43ac5ed1-b87a-4d96-a4f3-1599aed6bdf2" width="80%" controls></video>
</p>
