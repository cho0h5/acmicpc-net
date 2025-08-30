const std = @import("std");
const splitAny = std.mem.splitAny;
const HashMap = std.AutoHashMap(u32, u32);

const stdin = std.io.getStdIn().reader();
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

fn sol(N: u32, M: u32, A: u32, B: u32, C: u32, graph: [100001]HashMap) void {
}

pub fn main() !void {
    // Input
    const line = try stdin.readUntilDelimiterAlloc(allocator, '\n', 100);
    defer allocator.free(line);

    var it = splitAny(u8, line, " ");
    const N = try std.fmt.parseInt(u32, it.next().?, 10);
    const M = try std.fmt.parseInt(u32, it.next().?, 10);
    const A = try std.fmt.parseInt(u32, it.next().?, 10);
    const B = try std.fmt.parseInt(u32, it.next().?, 10);
    const C = try std.fmt.parseInt(u32, it.next().?, 10);

    var graph: [100001]HashMap = undefined;
    for (&graph) |*map| {
        map.* = HashMap.init(allocator);
    }

    for (0..M) |_| {
        const line2 = try stdin.readUntilDelimiterAlloc(allocator, '\n', 100);
        defer allocator.free(line2);

        var it2 = splitAny(u8, line2, " ");
        const S = try std.fmt.parseInt(u32, it2.next().?, 10);
        const E = try std.fmt.parseInt(u32, it2.next().?, 10);
        const F = try std.fmt.parseInt(u32, it2.next().?, 10);

        try graph[S].put(E, F);
        try graph[E].put(S, F);
    }

    // Check input
    std.debug.print("N: {}, ", .{N});
    std.debug.print("M: {}, ", .{M});
    std.debug.print("A: {}, ", .{A});
    std.debug.print("B: {}, ", .{B});
    std.debug.print("C: {}\n", .{C});

    for (&graph, 0..) |*map, i| {
        var it3 = map.*.iterator();
        while (it3.next()) |entry| {
            std.debug.print("{} {} {}\n", .{i, entry.key_ptr.*, entry.value_ptr.*});
        }
    }

    sol(N, M, A, B, C, graph);
}
