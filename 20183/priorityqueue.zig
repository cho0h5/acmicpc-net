const std = @import("std");
const splitAny = std.mem.splitAny;
const HashMap = std.AutoHashMap(u32, u32);
const PriorityQueue = std.PriorityQueue;

var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

//const Element = struct {
//    node: u32,
//    min: u32,   // 1
//    sum: u32,   // 2
//};
//
//fn compare(_: void, a: Element, b: Element) bool {
//    if (a.min < b.min) {
//        return true;
//    } else {
//        return a.sum < b.sum;
//    }
//}

fn compare(_: void, a: i32, b: i32) std.math.Order {
    if (a < b) return .lt;
    if (a > b) return .gt;
    return .eq;
}

pub fn main() !void {
    var pq = PriorityQueue(i32, void, compare).init(allocator, {});
    defer pq.deinit();

    try pq.add(3);
    try pq.add(2);
    try pq.add(4);
    try pq.add(1);
    try pq.add(5);

    std.debug.print("peek: {}\n", .{pq.peek().?});
    std.debug.print("peek: {}\n", .{pq.remove()});

    std.debug.print("peek: {}\n", .{pq.peek().?});
    std.debug.print("peek: {}\n", .{pq.remove()});

    std.debug.print("peek: {}\n", .{pq.peek().?});
    std.debug.print("peek: {}\n", .{pq.remove()});

    std.debug.print("peek: {}\n", .{pq.peek().?});
    std.debug.print("peek: {}\n", .{pq.remove()});

    std.debug.print("peek: {}\n", .{pq.peek().?});
    std.debug.print("peek: {}\n", .{pq.remove()});
}
