local function decompress(str)
	local result = {}
	local i = 1
	local n = #str
	while i <= n do
		local char = str:sub(i, i)
		if char == '[' then
			i = i + 1
			local num_str = ""
			while i <= n and str:sub(i, i):match("%d") do
				num_str = num_str .. str:sub(i, i)
				i = i + 1
			end
			local num = tonumber(num_str)
			if not num then
				error("Invalid number in brackets")
			end
			local count = 1
			local j = i
			while count > 0 and j <= n do
				local next_char = str:sub(j, j)
				if next_char == '[' then
					count = count + 1
				elseif next_char == ']' then
					count = count - 1
				end
				j = j + 1
			end
			local inner_str = str:sub(i, j - 2) -- Exclude the closing bracket
			local decompressed_inner = decompress(inner_str)
			for _ = 1, num do
				table.insert(result, decompressed_inner)
			end
			i = j -- Move past the closing bracket
		else
			table.insert(result, char)
			i = i + 1
		end
	end
	return table.concat(result)
end

local function main(...)
	local str = io.read("*l")
	print(decompress(str))
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