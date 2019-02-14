# A Tiny Quadrotor Simulator

This is a ros-rviz based simulator for a Quadrotor. Purpose is to fully (as much as possible from the basics)
understand and experiment with Quadrotor-drones.


## Run with docker
I recommend running this with docker. See my [docker-images](https://cloud.docker.com/repository/docker/mpkuse/kusevisionkit). You may use my image which
was built from ros-melodic-base.

```
docker run -it -v /home/mpkuse/docker_ws_teenytiny/:/app  mpkuse/kusevisionkit:ros-melodic-custom  bash
cd /app
# Create catkin workspace on container image
mkdir -p catkin_ws/src
cd catkin_ws/
catkin_make
source /app/catkin_ws/devel/setup.bash/

# Clone this repo
cd /app/catkin_ws/src
git clone <this>

# Compile
cd /app/catkin_ws
catkin_make

# Run
```

Then create a `catkin_ws` in this container and clone this repo into `catkin_ws/src`.
In the future i will make the process smoother. The main idea is to have all the dependencies installed in the
image.


## Author
Manohar Kuse <mpkuse@connect.ust.hk>
