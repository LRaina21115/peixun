# 消息定义：系统状态
builtin_interfaces/Time stamp # 时间戳 (对应代码中的 self.get_clock().now().to_msg())
string  host_name             # 主机名
float32 cpu_percent           # CPU使用率
float32 memory_percent        # 内存使用率
float32 memory_total          # 内存总量 (MB)
float32 memory_available      # 内存可用 (MB)
float32 net_sent              # 网络发送量 (MB)
float32 net_recv              # 网络接收量 (MB)