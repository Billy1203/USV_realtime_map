
(cl:in-package :asdf)

(defsystem "usv_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MPCCommand" :depends-on ("_package_MPCCommand"))
    (:file "_package_MPCCommand" :depends-on ("_package"))
    (:file "PolynomialTrajectory" :depends-on ("_package_PolynomialTrajectory"))
    (:file "_package_PolynomialTrajectory" :depends-on ("_package"))
    (:file "PositionCommand" :depends-on ("_package_PositionCommand"))
    (:file "_package_PositionCommand" :depends-on ("_package"))
    (:file "SpeedCourse" :depends-on ("_package_SpeedCourse"))
    (:file "_package_SpeedCourse" :depends-on ("_package"))
    (:file "ThrustCommand" :depends-on ("_package_ThrustCommand"))
    (:file "_package_ThrustCommand" :depends-on ("_package"))
  ))