local function main(...)
	
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