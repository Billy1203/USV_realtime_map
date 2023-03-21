;; Auto-generated. Do not edit!


(when (boundp 'usv_msgs::GlbObsRcv)
  (if (not (find-package "USV_MSGS"))
    (make-package "USV_MSGS"))
  (shadow 'GlbObsRcv (find-package "USV_MSGS")))
(unless (find-package "USV_MSGS::GLBOBSRCV")
  (make-package "USV_MSGS::GLBOBSRCV"))
(unless (find-package "USV_MSGS::GLBOBSRCVREQUEST")
  (make-package "USV_MSGS::GLBOBSRCVREQUEST"))
(unless (find-package "USV_MSGS::GLBOBSRCVRESPONSE")
  (make-package "USV_MSGS::GLBOBSRCVRESPONSE"))

(in-package "ROS")





(defclass usv_msgs::GlbObsRcvRequest
  :super ros::object
  :slots (_req ))

(defmethod usv_msgs::GlbObsRcvRequest
  (:init
   (&key
    ((:req __req) nil)
    )
   (send-super :init)
   (setq _req __req)
   self)
  (:req
   (&optional (__req :null))
   (if (not (eq __req :null)) (setq _req __req)) _req)
  (:serialization-length
   ()
   (+
    ;; bool _req
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _req
       (if _req (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _req
     (setq _req (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass usv_msgs::GlbObsRcvResponse
  :super ros::object
  :slots (_result ))

(defmethod usv_msgs::GlbObsRcvResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional (__result :null))
   (if (not (eq __result :null)) (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass usv_msgs::GlbObsRcv
  :super ros::object
  :slots ())

(setf (get usv_msgs::GlbObsRcv :md5sum-) "7f352b44c251978f0843cd60887550cf")
(setf (get usv_msgs::GlbObsRcv :datatype-) "usv_msgs/GlbObsRcv")
(setf (get usv_msgs::GlbObsRcv :request) usv_msgs::GlbObsRcvRequest)
(setf (get usv_msgs::GlbObsRcv :response) usv_msgs::GlbObsRcvResponse)

(defmethod usv_msgs::GlbObsRcvRequest
  (:response () (instance usv_msgs::GlbObsRcvResponse :init)))

(setf (get usv_msgs::GlbObsRcvRequest :md5sum-) "7f352b44c251978f0843cd60887550cf")
(setf (get usv_msgs::GlbObsRcvRequest :datatype-) "usv_msgs/GlbObsRcvRequest")
(setf (get usv_msgs::GlbObsRcvRequest :definition-)
      "bool req
---
bool result

")

(setf (get usv_msgs::GlbObsRcvResponse :md5sum-) "7f352b44c251978f0843cd60887550cf")
(setf (get usv_msgs::GlbObsRcvResponse :datatype-) "usv_msgs/GlbObsRcvResponse")
(setf (get usv_msgs::GlbObsRcvResponse :definition-)
      "bool req
---
bool result

")



(provide :usv_msgs/GlbObsRcv "7f352b44c251978f0843cd60887550cf")


