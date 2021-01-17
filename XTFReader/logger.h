#ifndef _LOGGER_H
#define _LOGGER_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <sstream>

#define _LOGGING_ENABLED
//!
//! convenience macro to log with file and line information
//!
#ifdef _LOGGING_ENABLED
#define LOG(level, msg) level(msg, __FILE__, __LINE__);
#else
#define LOG(level, msg)
#endif /* _LOGGING_ENABLED */

class logger_base {
public:
  //! ctor
  logger_base(void) = default;
  //! dtor
  virtual ~logger_base(void) = default;

  //! copy ctor
  logger_base(const logger_base&) = default;
  //! assignment operator
  logger_base& operator=(const logger_base&) = default;

public:
  //!
  //! debug logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  virtual void debug(const std::string& msg, const std::string& file, std::size_t line) = 0;

  //!
  //! info logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  virtual void info(const std::string& msg, const std::string& file, std::size_t line) = 0;

  //!
  //! warn logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  virtual void warn(const std::string& msg, const std::string& file, std::size_t line) = 0;

  //!
  //! error logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  virtual void error(const std::string& msg, const std::string& file, std::size_t line) = 0;

};

//!
//! default logger class provided by the library
//!
class logger : public logger_base {
public:
  //!
  //! log level
  //!
  enum class log_level {
    error = 0,
    warn  = 1,
    info  = 2,
    debug = 3
  };

public:
  //! ctor
  logger(log_level level = log_level::info);
  //! dtor
  ~logger(void) = default;

  //! copy ctor
  logger(const logger&) = default;
  //! assignment operator
  logger& operator=(const logger&) = default;

public:
  //!
  //! debug logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  void debug(const std::string& msg, const std::string& file, std::size_t line);

  //!
  //! info logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  void info(const std::string& msg, const std::string& file, std::size_t line);

  //!
  //! warn logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  void warn(const std::string& msg, const std::string& file, std::size_t line);

  //!
  //! error logging
  //!
  //! \param msg message to be logged
  //! \param file file from which the message is coming
  //! \param line line in the file of the message
  //!
  void error(const std::string& msg, const std::string& file, std::size_t line);

private:
  //!
  //! current log level in use
  //!
  log_level m_level;

  //!
  //! mutex used to serialize logs in multithreaded environment
  //!
  std::mutex m_mutex;
};

//!
//! variable containing the current logger
//! by default, not set (no logs)
//!
extern std::unique_ptr<logger_base> active_logger;

//!
//! debug logging
//! convenience function used internally to call the logger
//!
//! \param msg message to be logged
//! \param file file from which the message is coming
//! \param line line in the file of the message
//!
void debug(const std::string& msg, const std::string& file, std::size_t line);

//!
//! info logging
//! convenience function used internally to call the logger
//!
//! \param msg message to be logged
//! \param file file from which the message is coming
//! \param line line in the file of the message
//!
void info(const std::string& msg, const std::string& file, std::size_t line);

//!
//! warn logging
//! convenience function used internally to call the logger
//!
//! \param msg message to be logged
//! \param file file from which the message is coming
//! \param line line in the file of the message
//!
void warn(const std::string& msg, const std::string& file, std::size_t line);

//!
//! error logging
//! convenience function used internally to call the logger
//!
//! \param msg message to be logged
//! \param file file from which the message is coming
//! \param line line in the file of the message
//!
void error(const std::string& msg, const std::string& file, std::size_t line);

/*
//二维float数组打印显示
#define PrintArray2D(arr,m,n)       \
do                                  \
{                                   \
    int  i = 0;                     \
    int  j = 0;                     \
    for(i=0;i<m;i++)                \
    {                               \
        for(j=0;j<n;j++)            \
        {                           \
        printf("%f  ",arr[i][j]);   \
        }                           \
        printf("\n");               \
    }                               \
}while(0)
*/

#endif
