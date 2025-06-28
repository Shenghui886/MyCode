local function main(...)
	-- 动态规划
	local dp = {}; -- 存储每种栈状态下小球排列的种数
	local n = io.read("*n");

	for i = 1, n do
		dp[i] = {};
		-- 第一步状态只有出,所以从第二步状态开始计算
		dp[i][1] = i;

		for j = 2, n do
			if i == 1 or i < j then
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			end
		end
	end
	print(dp[n][n]);
end

-- Detect if executed directly or required
if pcall(debug.getlocal, 4, 1) then
	-- Return module when required
	return { main = main }
else
	-- Execute when run directly
	local success, err = xpcall(main, debug.traceback, ...)
	if not success then
		print(("[\27[31mERROR\27[0m] %s"):format(err))
		os.exit(1)
	end
	os.exit(0)
end