declare module 'libyosys' {
    function setup(): void;
    function run(command: string): void;
    function shutdown(): void;
}
