#include "reassembler.hh"
#include <string>
#include <iostream>
using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring, Writer& output )
{
  // Your code here.
  (void)first_index;
  (void)data;
  (void)is_last_substring;
  (void)output;
  if(is_last_substring){
    eof_index_ = first_index + data.size();
    eof = true;
  }
  if(first_index+data.size() < output.bytes_pushed() || first_index >= output.bytes_pushed()+ output.available_capacity()) return;
  if(first_index <= output.bytes_pushed()){
    //此处进行切割left
    auto temp = output.bytes_pushed();
    auto push_size = min(data.size()- output.bytes_pushed()-first_index, output.available_capacity());
    
    output.push(data.substr(output.bytes_pushed()-first_index, push_size));
    //std::cout<< first_index << " " << push_size << " " << data.substr(output.bytes_pushed()-first_index, push_size) << " " << output.bytes_pushed() <<endl;
    for(auto b:buffers_){
      if(b.first<output.bytes_pushed()){
        buffers_.erase(b.first);
      }
      if(output.bytes_pushed()==b.first){
        output.push(string(1,b.second));
        buffers_.erase(b.first);
      }
    }
    while(push_size>0){
      pushed.insert(temp+push_size);
      push_size--;
    }
  }
  //中间
  if(first_index>output.bytes_pushed()){
    auto str = (data.substr(0, min(data.size(), output.available_capacity())));
    for(uint64_t i = 0; i<str.size();i++){
      if(pushed.count(first_index+i) == 0){
          pushed.insert(first_index+i);
          buffers_.insert(std::make_pair(first_index+i, str[i]));
      }
    }
  }
  if(eof && eof_index_ == output.bytes_pushed()){
    output.close();
  }
}

uint64_t Reassembler::bytes_pending() const
{
  // Your code here.

  return buffers_.size();
}
