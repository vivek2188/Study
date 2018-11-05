#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/application-module.h"
#include "ns3/netanim-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE("Mesh Topology");

int main(int argc,char *argv[]){
	CommandLine cmd;
	cmd.Parse(argc,argv);

	Time::SetResolution(Time::NS);
	LogComponentEnable("UdpEchoClientApplication",LOG_LEVEL_INFO);
	LogComponentEnable("UdpEchoServerApplication",LOG_LEVEL_INFO);

	NodeContainer nodes;
	nodes.Create(3);

	PointToPointHelper ptp;
	ptp.SetDeviceAttribute("DataRate",StringValue("5Mbps"));
	ptp.SetDeviceAttribute("Delay",StringValue("2ms"));

	NetDeviceContainer d1,d2,d3,d4,d5,d6;
	d1 = ptp.Install(nodes.Get(0),nodes.Get(1));
	d2 = ptp.Install(nodes.Get(0),nodes.Get(2));
	d3 = ptp.Install(nodes.Get(0),nodes.Get(3));
	d4 = ptp.Install(nodes.Get(1),nodes.Get(2));
	d5 = ptp.Install(nodes.Get(1),nodes.Get(3));
	d6 = ptp.Install(nodes.Get(2),nodes.Get(3));

	InternetStackHelper stack;
	stack.Install(nodes);

	Ipv4AddressHelper address;
	address.SetBase("10.1.1.0","255.255.255.0");
	Ipv4InterfaceContainer interfaces = address.Assign(d);

	UdpEchoServerHelper echoServer (9);

	ApplicationContainer serverApps = echoServer.Install(nodes.Get(1));
	serverApps.Start(Seconds(1.0));
	serverApps.Stop(Seconds(10.0));

	UdpEchoClientHelper echoClient (interfaces.GetAddress(1),9);
	echoClient.SetAttribute("MaxPackets",UintegerValue(1));
	echoClient.SetAttribute("Interval",TimeValue(Seconds(1.0)));
	echoClient.SetAttribute("PacketSize",UintegerValue(1024));

	ApplicationContainer clientApps = echoClient.Install(nodes.Get(0));
	clientApps.Start(Seconds(2.0));
	clientApps.Stop(Seconds(10.0));

	Simulator::run();
	Simulator::destory();
	return 0;
}
