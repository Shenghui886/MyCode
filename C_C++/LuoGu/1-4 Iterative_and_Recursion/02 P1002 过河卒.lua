-- local function main(...)
--     local input = io.read()
--     local n, m, hx, hy = input:match("(%d+)%s+(%d+)%s+(%d+)%s+(%d+)")
--     n, m, hx, hy = tonumber(n), tonumber(m), tonumber(hx), tonumber(hy)

--     -- 创建动态规划数组和控制点标记数组
--     local dp = {}
--     local control = {}
--     for i = 0, n do
--         dp[i] = {}
--         control[i] = {}
--         for j = 0, m do
--             dp[i][j] = 0
--             control[i][j] = false
--         end
--     end

--     -- 标记马的控制点（包括马自身位置）
--     local horsePoints = {
--         {0, 0},   -- 马自身
--         {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
--         {1, -2}, {1, 2}, {2, -1}, {2, 1}
--     }

--     for _, point in ipairs(horsePoints) do
--         local nx = hx + point[1]
--         local ny = hy + point[2]
--         if nx >= 0 and nx <= n and ny >= 0 and ny <= m then
--             control[nx][ny] = true
--         end
--     end

--     -- 初始化起点
--     if not control[0][0] then
--         dp[0][0] = 1
--     else
--         dp[0][0] = 0
--     end

--     -- 初始化第一行
--     for j = 1, m do
--         if not control[0][j] then
--             dp[0][j] = dp[0][j-1]
--         else
--             dp[0][j] = 0
--         end
--     end

--     -- 初始化第一列
--     for i = 1, n do
--         if not control[i][0] then
--             dp[i][0] = dp[i-1][0]
--         else
--             dp[i][0] = 0
--         end
--     end

--     -- 动态规划计算其他位置
--     for i = 1, n do
--         for j = 1, m do
--             if not control[i][j] then
--                 dp[i][j] = dp[i-1][j] + dp[i][j-1]
--             else
--                 dp[i][j] = 0
--             end
--         end
--     end

--     -- 输出结果
--     print(dp[n][m])
-- end

local function main()
    local input = io.read()
    local Bx, By, hx, hy = input:match("(%d+)%s+(%d+)%s+(%d+)%s+(%d+)")
    Bx, By, hx, hy = tonumber(Bx), tonumber(By), tonumber(hx), tonumber(hy)

    -- 创建动态规划数组
    local map = {}
    for y = 0, By do
        map[y] = {}
        for x = 0, Bx do
            map[y][x] = 0
        end
    end

    -- 标记马的控制点为障碍（-1）
    local function markBlocked(x, y)
        if x >= 0 and x <= Bx and y >= 0 and y <= By then
            map[y][x] = -1
        end
    end

    -- 标记马本身和所有可能的控制点
    markBlocked(hx, hy)
    markBlocked(hx - 1, hy + 2)
    markBlocked(hx - 1, hy - 2)
    markBlocked(hx + 1, hy + 2)
    markBlocked(hx + 1, hy - 2)
    markBlocked(hx - 2, hy + 1)
    markBlocked(hx - 2, hy - 1)
    markBlocked(hx + 2, hy + 1)
    markBlocked(hx + 2, hy - 1)

    -- 初始化起点
    if map[0][0] ~= -1 then
        map[0][0] = 1
    end

    -- 动态规划计算路径数
    for y = 0, By do
        for x = 0, Bx do
            if x == 0 and y == 0 then
                -- 起点已经初始化过，跳过
            else
                if map[y][x] == -1 then
                    -- 障碍点，路径数为0
                    map[y][x] = 0
                else
                    -- 计算从左边和上边来的路径数
                    local left = (x > 0 and map[y][x-1] or 0)
                    local top = (y > 0 and map[y-1][x] or 0)
                    map[y][x] = left + top
                end
            end
        end
    end

    -- 输出结果
    print(map[By][Bx])
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