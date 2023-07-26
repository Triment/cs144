#include <stdexcept>

#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : 
capacity_( capacity ), 
bytes_({}),
written_count_(0),
read_count_(0),
end_(false),
err_state_(false)
{}

void Writer::push( string data )
{
  // Your code here.
  if(end_ || available_capacity() <= 0){
    return;
  }
  auto len = min(available_capacity(), data.size()); 
  for (uint64_t i = 0; i < len; i++)
  {
    bytes_.push_back(data[i]);
  }
  written_count_ += len;//increment pushed_size_
}

void Writer::close()
{
  // Your code here.
  end_ = true;
}

void Writer::set_error()
{
  // Your code here.
  err_state_ = true;
}

bool Writer::is_closed() const
{
  // Your code here.
  return end_;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - bytes_.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return written_count_;
}

string_view Reader::peek() const
{
  // Your code here.
  return string_view{&bytes_[0], 1};
}

bool Reader::is_finished() const
{
  // Your code here.
  return end_ && bytes_.empty();
}

bool Reader::has_error() const
{
  // Your code here.
  return err_state_;
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if(bytes_.empty()) return;
  len = min(len, bytes_.size());
  bytes_.erase(bytes_.begin(),bytes_.begin()+len);
  read_count_ += len;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return bytes_.size();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return read_count_;
}
