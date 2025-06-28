local function main()
    local n = io.read("*n");
    local s = {};
    local b = {};

    for i = 1, n do
        s[i] = io.read("*n");
        b[i] = io.read("*n");
    end

    local min_diff = math.huge;

    for state = 1, (1 << n) - 1 do
        local mul = 1;
        local sum = 0;
        local temp = state

        for i = 1, n do
            local bit = temp % 2;
            temp = math.floor(temp / 2)
            if bit == 1 then
                mul = mul * s[i];
                sum = sum + b[i];
            end
        end

        local diff = math.abs(mul - sum);
        if diff < min_diff then
            min_diff = diff
        end
    end
    print(min_diff)
end

main();