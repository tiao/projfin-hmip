interface eth1 {
	AdvSendAdvert on;
	MinRtrAdvInterval 1;
	MaxRtrAdvInterval 3;
	AdvHomeAgentFlag on;

	prefix 2001:c::/64
	{
		AdvOnLink on;
		AdvAutonomous on;
		AdvRouterAddr on; 
	};
};

