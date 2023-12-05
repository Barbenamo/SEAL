import math
from math import sin, cos, pi
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from geometry_msgs.msg import Quaternion
from sensor_msgs.msg import JointState
from tf2_ros import TransformBroadcaster, TransformStamped
from nav_msgs.msg import Odometry

class StatePublisher(Node):

    def __init__(self):
        rclpy.init()
        super().__init__('state_publisher')
        qos_profile = QoSProfile(depth=10)
        self.joint_pub = self.create_publisher(JointState, 'joint_states', qos_profile)
        self.broadcaster = TransformBroadcaster(self, qos=qos_profile)
        self.nodeName = self.get_name()
        self.get_logger().info("{0} started".format(self.nodeName))

        self.odom_subscriber = self.create_subscription(
            Odometry,
            '/Odom',  # Modify this topic name to match your actual topic
            self.odom_callback,
            qos_profile
        )

        try:
            while rclpy.ok():
                rclpy.spin(self)
        except KeyboardInterrupt:
            pass


    def odom_callback(self, msg):
        now = self.get_clock().now()
        # message declarations
        odom_trans = TransformStamped()
        odom_trans.header.frame_id = 'map'
        odom_trans.child_frame_id = '_name'
        joint_state = JointState()
        # update transform
        odom_trans.header.stamp = now.to_msg()
        odom_trans.transform.translation.x = msg.pose.pose.position.x
        odom_trans.transform.translation.y = msg.pose.pose.position.y
        odom_trans.transform.translation.z = msg.pose.pose.position.z

        odom_trans.transform.rotation = msg.pose.pose.orientation 

        orientation_q = msg.pose.pose.orientation
        roll, pitch, yaw = quaternion_to_euler(orientation_q)
        
        # send the joint state and transform
        self.joint_pub.publish(joint_state)
        self.broadcaster.sendTransform(odom_trans)
        self.get_logger().info("-------------------------------")
        # self.get_logger().info(
            # f"Position: x = {msg.pose.pose.position.x}, "
            # f"y = {msg.pose.pose.position.y}, "
            # f"z = {msg.pose.pose.position.z}"
        # )

        self.get_logger().info(f"   roll: {roll},"
                                f"  pitch: {pitch},"
                                f"  yaw: {yaw}")

        
        pass
    

def euler_to_quaternion(roll, pitch, yaw):
    """
    get a quaternion from Euler angles.
    """

    qx = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2)
    qy = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2)
    qz = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2)
    qw = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2)
    return Quaternion(x=qx, y=qy, z=qz, w=qw)

def quaternion_to_euler(quaternion: Quaternion):
    """
    Convert a quaternion to Euler angles.
    """
    x, y, z, w = quaternion.x, quaternion.y, quaternion.z, quaternion.w

    # Roll (x-axis rotation)
    sinr_cosp = 2 * (w * x + y * z)
    cosr_cosp = 1 - 2 * (x * x + y * y)
    roll = math.atan2(sinr_cosp, cosr_cosp)

    # Pitch (y-axis rotation)
    sinp = 2 * (w * y - z * x)
    if abs(sinp) >= 1:
        pitch = math.copysign(math.pi / 2, sinp)  # use 90 degrees if out of range
    else:
        pitch = math.asin(sinp)

    # Yaw (z-axis rotation)
    siny_cosp = 2 * (w * z + x * y)
    cosy_cosp = 1 - 2 * (y * y + z * z)
    yaw = math.atan2(siny_cosp, cosy_cosp)

    return roll, pitch, yaw

def main():
    node = StatePublisher()
    

if __name__ == '__main__':
    main()