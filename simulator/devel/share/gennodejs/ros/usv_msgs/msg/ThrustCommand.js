// Auto-generated. Do not edit!

// (in-package usv_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ThrustCommand {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.left_thrust_cmd = null;
      this.right_thrust_cmd = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('left_thrust_cmd')) {
        this.left_thrust_cmd = initObj.left_thrust_cmd
      }
      else {
        this.left_thrust_cmd = 0.0;
      }
      if (initObj.hasOwnProperty('right_thrust_cmd')) {
        this.right_thrust_cmd = initObj.right_thrust_cmd
      }
      else {
        this.right_thrust_cmd = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ThrustCommand
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [left_thrust_cmd]
    bufferOffset = _serializer.float64(obj.left_thrust_cmd, buffer, bufferOffset);
    // Serialize message field [right_thrust_cmd]
    bufferOffset = _serializer.float64(obj.right_thrust_cmd, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ThrustCommand
    let len;
    let data = new ThrustCommand(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [left_thrust_cmd]
    data.left_thrust_cmd = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_thrust_cmd]
    data.right_thrust_cmd = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'usv_msgs/ThrustCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ff278815bb5e6204701ce178b988e627';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ThrustCommand(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.left_thrust_cmd !== undefined) {
      resolved.left_thrust_cmd = msg.left_thrust_cmd;
    }
    else {
      resolved.left_thrust_cmd = 0.0
    }

    if (msg.right_thrust_cmd !== undefined) {
      resolved.right_thrust_cmd = msg.right_thrust_cmd;
    }
    else {
      resolved.right_thrust_cmd = 0.0
    }

    return resolved;
    }
};

module.exports = ThrustCommand;
