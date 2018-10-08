#include "ns3/core-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Network Simulator");

int main(int argc,char *argv[]){
	NS_LOG_UNCOND("Nice Stuff");
	
	Simulator::Run();
	Simulator::Destory();
	return 0;
}
