# Toy Robot Code Challenge

## Description
- The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.
- There are no other obstructions on the table surface.
- The robot is free to roam around the surface of the table, but must be prevented from falling to destruction.
- Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

## Commands
- A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.
- Input can be from a file, or from standard input.

#### PLACE X,Y,F
- PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.
- The origin (0,0) can be considered to be the SOUTH WEST most corner.
- It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command.
- The application should discard all commands in the sequence until a valid PLACE command has been executed.

#### MOVE
- MOVE will move the toy robot one unit forward in the direction it is currently facing.

#### LEFT and RIGHT
- LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.

#### REPORT
- REPORT will announce the X,Y and F of the robot.

## Constraints
- The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
- Anymove that would cause the robot to fall must be ignored.

## Example
There is a ready-to-use application in ToyRobot\example, ToyRobot.exe. Click StartToyRobot.bat will use command.txt as input.

#### a)----------------
- PLACE 0,0,NORTH \n
- MOVE
- REPORT
- Output: 0,1,NORTH
#### b)----------------
- PLACE 0,0,NORTH
- LEFT
- REPORT
- Output: 0,0,WEST
#### c)----------------
- PLACE 1,2,EAST
- MOVE
- MOVE
- LEFT
- MOVE
- REPORT
- Output: 3,3,NORTH

## Dependencies
- Google test, https://github.com/google/googletest

## Build
- DownLoad Visual Studio 2019.
- Open ToyRobot.sln with Visual Studio 2019.
- Build Solution.

## Unit test
- Using Google test for the project.
- Active project "ToyRobotTest" to debug.
- Test code locate at "ToyRobot\test"
- There is a runnable exe in "ToyRobot\example". Execute "UnitTest.bat" to see results.
