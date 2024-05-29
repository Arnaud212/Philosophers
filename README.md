# Philosophers Project

## Overview
The **Philosophers** project is a simulation of the classic dining philosophers problem. In this project, you will learn the basics of threading and process synchronization using mutexes. You will create a program where philosophers sit at a table, eating, thinking, and sleeping, while sharing forks. The goal is to manage their actions and resources (forks) to prevent any philosopher from starving and avoid race conditions.

## Key Concepts
1. **Philosophers and Forks**:
   - Philosophers sit at a round table with one fork between each pair.
   - Each philosopher needs two forks to eat.
2. **Actions**:
   - Philosophers can eat, think, or sleep.
   - They need to alternate between these actions without overlapping.
3. **Synchronization**:
   - Use mutexes to protect the state of the forks and prevent data races.
4. **Simulation End**:
   - The simulation stops when a philosopher dies of starvation or all philosophers have eaten a specified number of times.

## How to Use the Project

### Compilation
To compile the project, navigate to the project directory and run:
```sh
make
```

### Running the Simulation

To run the simulation, use the following command:
```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- **number_of_philosophers**: The number of philosophers (and forks) at the table.
- **time_to_die** (in milliseconds): The maximum time a philosopher can go without eating before dying.
- **time_to_eat** (in milliseconds): The time a philosopher spends eating.
- **time_to_sleep** (in milliseconds): The time a philosopher spends sleeping.
- **number_of_times_each_philosopher_must_eat** (optional): The number of times each philosopher must eat before the simulation ends.

### Example

```sh
./philo 5 800 200 200 7
```

This command runs the simulation with 5 philosophers, each having:

- 800 ms before they die if they do not eat,
- 200 ms to eat,
- 200 ms to sleep,
- and each must eat 7 times before the simulation stops.

### Logs and Output

- The program logs each state change of a philosopher with a timestamp and the philosopher's number.

- Example logs:
```csharp
100ms 1 has taken a fork
100ms 1 is eating
300ms 1 is sleeping
500ms 1 is thinking
700ms 1 died
```