#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
    rospy.init_node('talker', anonymous=True)

    message = rospy.get_param('~message', 'hello world')
    freq = rospy.get_param('~frequency', 10)
    topic_name = rospy.get_param('~topic_name', 'babbler') 
    pub = rospy.Publisher(topic_name, String, queue_size=10)

    r = rospy.Rate(freq) # 10hz

    while not rospy.is_shutdown():
        str = "%s %s"%(message, rospy.get_time())
        rospy.loginfo(str)
        pub.publish(str)
        r.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass