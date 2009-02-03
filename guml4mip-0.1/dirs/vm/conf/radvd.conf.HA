interface eth0 {
	AdvSendAdvert on;
	MinRtrAdvInterval 1;
	MaxRtrAdvInterval 3;
	AdvHomeAgentFlag on;

	prefix 2000:a::/64
	{
		AdvOnLink on;
		AdvAutonomous on;
		AdvRouterAddr on; 
	};
};

