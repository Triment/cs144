#include "reassembler.hh"
#include <string>
using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  // Your code here.
  (void)first_index;
  (void)data;
  (void)is_last_substring;
  (void)output;
  if(at_left || at_right) return;//around between
  if(at_popped){//
    output.push(data);
  }
  if( !at_popp)

  if(output.available_capacity() > 0){
    for(auto i: buffers_){ }//forrange buffer and find index==output.bytes_pushed
  }
}
bool Reassembler::under_unpopped(Writer& output, uint64_t index, string data){ return index < output.bytes_pushed(); }
bool Reassembler::under_unacceptable(Writer& output, uint64_t index, string data){ return index < output.bytes_pushed() + output.available_capacity(); }
bool Reassembler::beyond_unpopped(Writer& output, uint64_t index, string data) {return index + data.size() > output.bytes_pushed();}
bool Reassembler::beyond_unacceptable(Writer& output, uint64_t index, string data) { return index + data.size() > output.bytes_pushed() + output.available_capacity();}

bool Reassembler::at_unpopped(Writer& output, uint64_t index, string data){ return output.bytes_pushed() == index; }
void Reassembler::traverse_buffers(Writer& output){
  for(auto i: buffers_){
    if(i.first == output.bytes_pushed()){
      output.push(i.second);
    }
  }
}
uint64_t Reassembler::bytes_pending() const
{
  // Your code here.
  uint64_t sum = 0;
  for(auto i:buffers_){
    sum += 1;
  }
  return sum;
}
