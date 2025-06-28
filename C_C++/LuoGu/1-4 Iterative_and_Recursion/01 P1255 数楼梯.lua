local function addBigInt(num1, num2)
    local len1 = #num1
    local len2 = #num2
    local maxLen = math.max(len1, len2) + 1
    local result = {}
    local carry = 0
    local i, j = len1, len2
    
    -- 预分配结果数组空间
    for idx = 1, maxLen do
        result[idx] = 0
    end
    
    local pos = maxLen
    while i >= 1 or j >= 1 or carry > 0 do
        local sum = carry
        
        if i >= 1 then
            -- 直接使用ASCII值计算，避免字符串转换
            sum = sum + string.byte(num1, i) - 48  -- '0' = 48
            i = i - 1
        end
        
        if j >= 1 then
            sum = sum + string.byte(num2, j) - 48  -- '0' = 48
            j = j - 1
        end
        
        carry = math.floor(sum / 10)
        result[pos] = sum % 10
        pos = pos - 1
    end
    
    -- 跳过前导零
    local start = 1
    while start <= maxLen and result[start] == 0 do
        start = start + 1
    end
    
    if start > maxLen then
        return "0"
    end
    
    -- 直接构建结果字符串
    for i = start, maxLen do
        result[i] = string.char(result[i] + 48)  -- 转换回字符
    end
    
    return table.concat(result, "", start, maxLen)
end

local function Fibonacci(n)
    local result;
    if n == 1 then
        return "0";
    elseif n == 2 then
        return "1";
    else
        local num1 = "0";
        local num2 = "1";
        for i = 0, n - 2 do
            num1, num2 = num2, addBigInt(num1, num2);
        end
        result = num2;
    end
    return result;
end


local function main(...)
    local n = io.read("*n");
    print(Fibonacci(n + 1));
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