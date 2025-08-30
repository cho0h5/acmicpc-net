const std = @import("std");
const splitAny = std.mem.splitAny;
const HashMap = std.AutoHashMap(u32, i32);
const PriorityQueue = std.PriorityQueue;

const stdin = std.io.getStdIn().reader();
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

const Element = struct {
    node: u32,
    min: i32,   // 1
    sum: i32,   // 2
};

fn compare(_: void, a: Element, b: Element) std.math.Order {
    if (a.min < b.min) {
        return .lt;
    } else if (a.min == b.min) {
        if (a.sum < b.sum) {
            return .lt;
        } else if (a.sum == b.sum) {
            return .eq;
        } else {
            return .gt;
        }
    } else {
        return .eq;
    }
}

fn sol(A: u32, B: u32, C: i32, graph: [100001]HashMap) !i32 {
    var pq = PriorityQueue(Element, void, compare).init(allocator, {});
    defer pq.deinit();

    try pq.add(.{ .node = A, .min = 0, .sum = 0});

    while (pq.removeOrNull()) |e| {
        const cnode = e.node;
        const cmin = e.min;
        const csum = e.sum;

        if (C < csum) {
            continue;
        }

        if (B == cnode) {
            return cmin;
        }

        var it = graph[cnode].iterator();
        while (it.next()) |neighbor| {
            const nnode = neighbor.key_ptr.*;
            const ncost = neighbor.value_ptr.*;

            const max = if (cmin > ncost) cmin else ncost;
            try pq.add(.{ .node = nnode, .min = max, .sum = csum + ncost});
        }
    }

    return -1;
}

pub fn main() !void {
    // Input
    const line = try stdin.readUntilDelimiterAlloc(allocator, '\n', 100);
    defer allocator.free(line);

    var it = splitAny(u8, line, " ");
    _ = try std.fmt.parseInt(i32, it.next().?, 10);
    const M = try std.fmt.parseInt(u32, it.next().?, 10);
    const A = try std.fmt.parseInt(u32, it.next().?, 10);
    const B = try std.fmt.parseInt(u32, it.next().?, 10);
    const C = try std.fmt.parseInt(i32, it.next().?, 10);

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
        const F = try std.fmt.parseInt(i32, it2.next().?, 10);

        try graph[S].put(E, F);
        try graph[E].put(S, F);
    }

//     // Check input
//     std.debug.print("N: {}, ", .{N});
//     std.debug.print("M: {}, ", .{M});
//     std.debug.print("A: {}, ", .{A});
//     std.debug.print("B: {}, ", .{B});
//     std.debug.print("C: {}\n", .{C});
// 
//     for (&graph, 0..) |*map, i| {
//         var it3 = map.*.iterator();
//         while (it3.next()) |entry| {
//             std.debug.print("{} {} {}\n", .{i, entry.key_ptr.*, entry.value_ptr.*});
//         }
//     }

    const result = try sol(A, B, C, graph);
    std.debug.print("{}\n", .{result});
}
