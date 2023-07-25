#include "reassembler.hh"

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  // Your code here.
  (void)first_index;
  (void)data;
  (void)is_last_substring;
  (void)output;
  if(first_index < unpoped_index_ || first_index >= output.bytes_pushed() + output.available_capacity()) return;
  if(first_index == unpoped_index_){
    output.push(data);
  }
  if(is_last_substring){
    if(output.bytes_pushed()==first_index){
      output.push(data);
      output.close();//close writer when last substr is ready
      return;
    }
    if(output.available_capacity() >= data.size()){
      //cache data
    }
  }
}

uint64_t Reassembler::bytes_pending() const
{
  // Your code here.
  return {};
}
