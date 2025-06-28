local function main(...)
	local dp = {}
	for i = 0, 20 do
		dp[i] = {}
		for j = 0, 20 do
			dp[i][j] = {}
		end
	end

	for a = 0, 20 do
		for b = 0, 20 do
			for c = 0, 20 do
				if a == 0 or b == 0 or c == 0 then
					dp[a][b][c] = 1
				elseif a < b and b < c then
					dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c]
				else
					dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1]
				end
			end
		end
	end

	while true do
		local line = io.read()
		if not line then break end
		local a, b, c = line:match("(%S+)%s+(%S+)%s+(%S+)")
		a = tonumber(a)
		b = tonumber(b)
		c = tonumber(c)
		if a == -1 and b == -1 and c == -1 then
			break
		end
		local ans
		if a <= 0 or b <= 0 or c <= 0 then
			ans = 1
		elseif a > 20 or b > 20 or c > 20 then
			ans = dp[20][20][20]
		else
			ans = dp[a][b][c]
		end
		print(string.format("w(%d, %d, %d) = %d", a, b, c, ans))
	end
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