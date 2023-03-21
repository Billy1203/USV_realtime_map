;; Auto-generated. Do not edit!


(when (boundp 'usv_msgs::ThrustCommand)
  (if (not (find-package "USV_MSGS"))
    (make-package "USV_MSGS"))
  (shadow 'ThrustCommand (find-package "USV_MSGS")))
(unless (find-package "USV_MSGS::THRUSTCOMMAND")
  (make-package "USV_MSGS::THRUSTCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude ThrustCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass usv_msgs::ThrustCommand
  :super ros::object
  :slots (_header _left_thrust_cmd _right_thrust_cmd ))

(defmethod usv_msgs::ThrustCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:left_thrust_cmd __left_thrust_cmd) 0.0)
    ((:right_thrust_cmd __right_thrust_cmd) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _left_thrust_cmd (float __left_thrust_cmd))
   (setq _right_thrust_cmd (float __right_thrust_cmd))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:left_thrust_cmd
   (&optional __left_thrust_cmd)
   (if __left_thrust_cmd (setq _left_thrust_cmd __left_thrust_cmd)) _left_thrust_cmd)
  (:right_thrust_cmd
   (&optional __right_thrust_cmd)
   (if __right_thrust_cmd (setq _right_thrust_cmd __right_thrust_cmd)) _right_thrust_cmd)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _left_thrust_cmd
    8
    ;; float64 _right_thrust_cmd
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _left_thrust_cmd
       (sys::poke _left_thrust_cmd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_thrust_cmd
       (sys::poke _right_thrust_cmd (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _left_thrust_cmd
     (setq _left_thrust_cmd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_thrust_cmd
     (setq _right_thrust_cmd (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get usv_msgs::ThrustCommand :md5sum-) "ff278815bb5e6204701ce178b988e627")
(setf (get usv_msgs::ThrustCommand :datatype-) "usv_msgs/ThrustCommand")
(setf (get usv_msgs::ThrustCommand :definition-)
      "Header header

float64 left_thrust_cmd #[-1,1]
float64 right_thrust_cmd

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :usv_msgs/ThrustCommand "ff278815bb5e6204701ce178b988e627")


