declare module libyosys {
    export function setup(): void;
    export function run(command: string): void;
    export function shutdown(): void;
}
