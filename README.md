# Ball and Beam PID Control System

Demonstrating control theory, our project utilizes a PID controller to maintain a ball's position on a wooden beam. Employing a microcontroller, servo motor, and ultrasonic sensors, the system resists disturbances, showcasing stability and precision.

## Table of Contents

- [Introduction](#introduction)
- [Physical Setup](#physical-setup)
- [Architecture](#architecture)
- [Usage](#usage)
- [API Documentation](#api-documentation)
- [Contributing](#contributing)
- [Testing](#testing)
- [License](#license)

## Introduction

In this project, we aimed to design and control a ball and beam system using a PID controller. The objective was to develop a system that could maintain the position of the ball at a specific location on the beam, despite disturbances or changes in the system parameters. We used a microcontroller, servo motor, ultrasonic sensors, and other components to design the system.

## Physical Setup

To construct the physical ball and beam system, plywood serves as the primary material, secured with nails for permanent joints. The top beam, narrower than the lower beam, prevents contact when inclined. Key dimensions are detailed:
1. Beam length: 45 cm.
2. Servo-motor positioning ensures the top beam shaft aligns nearly perpendicularly to the ground in a balanced state.
3. Ultra-sonic sensors are strategically placed for accurate readings, targeting the ball's center.
4. Bearings and a pencil secure the top beam, preventing horizontal movement and unwanted vibrations during controller tuning.
