// Generated by gencpp from file usv_msgs/PolynomialTrajectory.msg
// DO NOT EDIT!


#ifndef USV_MSGS_MESSAGE_POLYNOMIALTRAJECTORY_H
#define USV_MSGS_MESSAGE_POLYNOMIALTRAJECTORY_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace usv_msgs
{
template <class ContainerAllocator>
struct PolynomialTrajectory_
{
  typedef PolynomialTrajectory_<ContainerAllocator> Type;

  PolynomialTrajectory_()
    : header()
    , trajectory_id(0)
    , action(0)
    , num_order(0)
    , num_segment(0)
    , start_yaw(0.0)
    , final_yaw(0.0)
    , coef_x()
    , coef_y()
    , time()
    , mag_coeff(0.0)
    , order()
    , debug_info()  {
    }
  PolynomialTrajectory_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , trajectory_id(0)
    , action(0)
    , num_order(0)
    , num_segment(0)
    , start_yaw(0.0)
    , final_yaw(0.0)
    , coef_x(_alloc)
    , coef_y(_alloc)
    , time(_alloc)
    , mag_coeff(0.0)
    , order(_alloc)
    , debug_info(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _trajectory_id_type;
  _trajectory_id_type trajectory_id;

   typedef uint32_t _action_type;
  _action_type action;

   typedef uint32_t _num_order_type;
  _num_order_type num_order;

   typedef uint32_t _num_segment_type;
  _num_segment_type num_segment;

   typedef double _start_yaw_type;
  _start_yaw_type start_yaw;

   typedef double _final_yaw_type;
  _final_yaw_type final_yaw;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _coef_x_type;
  _coef_x_type coef_x;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _coef_y_type;
  _coef_y_type coef_y;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _time_type;
  _time_type time;

   typedef double _mag_coeff_type;
  _mag_coeff_type mag_coeff;

   typedef std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> _order_type;
  _order_type order;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _debug_info_type;
  _debug_info_type debug_info;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(ACTION_ADD)
  #undef ACTION_ADD
#endif
#if defined(_WIN32) && defined(ACTION_ABORT)
  #undef ACTION_ABORT
#endif
#if defined(_WIN32) && defined(ACTION_WARN_START)
  #undef ACTION_WARN_START
#endif
#if defined(_WIN32) && defined(ACTION_WARN_FINAL)
  #undef ACTION_WARN_FINAL
#endif
#if defined(_WIN32) && defined(ACTION_WARN_IMPOSSIBLE)
  #undef ACTION_WARN_IMPOSSIBLE
#endif

  enum {
    ACTION_ADD = 1u,
    ACTION_ABORT = 2u,
    ACTION_WARN_START = 3u,
    ACTION_WARN_FINAL = 4u,
    ACTION_WARN_IMPOSSIBLE = 5u,
  };


  typedef boost::shared_ptr< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> const> ConstPtr;

}; // struct PolynomialTrajectory_

typedef ::usv_msgs::PolynomialTrajectory_<std::allocator<void> > PolynomialTrajectory;

typedef boost::shared_ptr< ::usv_msgs::PolynomialTrajectory > PolynomialTrajectoryPtr;
typedef boost::shared_ptr< ::usv_msgs::PolynomialTrajectory const> PolynomialTrajectoryConstPtr;

// constants requiring out of line definition

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator1> & lhs, const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.trajectory_id == rhs.trajectory_id &&
    lhs.action == rhs.action &&
    lhs.num_order == rhs.num_order &&
    lhs.num_segment == rhs.num_segment &&
    lhs.start_yaw == rhs.start_yaw &&
    lhs.final_yaw == rhs.final_yaw &&
    lhs.coef_x == rhs.coef_x &&
    lhs.coef_y == rhs.coef_y &&
    lhs.time == rhs.time &&
    lhs.mag_coeff == rhs.mag_coeff &&
    lhs.order == rhs.order &&
    lhs.debug_info == rhs.debug_info;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator1> & lhs, const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace usv_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "df4ecebd1c68590fe40691d3e33566ab";
  }

  static const char* value(const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdf4ecebd1c68590fULL;
  static const uint64_t static_value2 = 0xe40691d3e33566abULL;
};

template<class ContainerAllocator>
struct DataType< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "usv_msgs/PolynomialTrajectory";
  }

  static const char* value(const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"\n"
"# the trajectory id, starts from \"1\".\n"
"uint32 trajectory_id\n"
"\n"
"# the action command for trajectory server.\n"
"uint32 ACTION_ADD           =   1\n"
"uint32 ACTION_ABORT         =   2\n"
"uint32 ACTION_WARN_START           =   3\n"
"uint32 ACTION_WARN_FINAL           =   4\n"
"uint32 ACTION_WARN_IMPOSSIBLE      =   5\n"
"uint32 action\n"
"\n"
"# the order of trajectory.\n"
"uint32 num_order\n"
"uint32 num_segment\n"
"\n"
"# the polynomial coecfficients of the trajectory.\n"
"float64 start_yaw\n"
"float64 final_yaw\n"
"float64[] coef_x\n"
"float64[] coef_y\n"
"float64[] time\n"
"float64   mag_coeff\n"
"uint32[]  order\n"
"\n"
"string debug_info\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.trajectory_id);
      stream.next(m.action);
      stream.next(m.num_order);
      stream.next(m.num_segment);
      stream.next(m.start_yaw);
      stream.next(m.final_yaw);
      stream.next(m.coef_x);
      stream.next(m.coef_y);
      stream.next(m.time);
      stream.next(m.mag_coeff);
      stream.next(m.order);
      stream.next(m.debug_info);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PolynomialTrajectory_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::usv_msgs::PolynomialTrajectory_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::usv_msgs::PolynomialTrajectory_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "trajectory_id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.trajectory_id);
    s << indent << "action: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.action);
    s << indent << "num_order: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_order);
    s << indent << "num_segment: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.num_segment);
    s << indent << "start_yaw: ";
    Printer<double>::stream(s, indent + "  ", v.start_yaw);
    s << indent << "final_yaw: ";
    Printer<double>::stream(s, indent + "  ", v.final_yaw);
    s << indent << "coef_x[]" << std::endl;
    for (size_t i = 0; i < v.coef_x.size(); ++i)
    {
      s << indent << "  coef_x[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.coef_x[i]);
    }
    s << indent << "coef_y[]" << std::endl;
    for (size_t i = 0; i < v.coef_y.size(); ++i)
    {
      s << indent << "  coef_y[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.coef_y[i]);
    }
    s << indent << "time[]" << std::endl;
    for (size_t i = 0; i < v.time.size(); ++i)
    {
      s << indent << "  time[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.time[i]);
    }
    s << indent << "mag_coeff: ";
    Printer<double>::stream(s, indent + "  ", v.mag_coeff);
    s << indent << "order[]" << std::endl;
    for (size_t i = 0; i < v.order.size(); ++i)
    {
      s << indent << "  order[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.order[i]);
    }
    s << indent << "debug_info: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.debug_info);
  }
};

} // namespace message_operations
} // namespace ros

#endif // USV_MSGS_MESSAGE_POLYNOMIALTRAJECTORY_H
