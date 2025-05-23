#include "../../c2b.h"

#include <format>

int main() {
    // Easily adjust how long the async cmd will run for
    const int SLEEP_TIME = 5;

    // Create cmd that runs multiple commands at once
    // NOTE: This is not the recommended way to use Cmd, but is used this way for demo purposes
    //       Proper use would be multiple Cmd objects, or reset the current one after running
    //       with cmd.set_length(0)
    c2b::Cmd cmd(std::format("sleep {};", SLEEP_TIME), "echo 'sleep done!'");

    // Run the cmd asynchronously
    auto cmdFuture = cmd.run_async_redirect_output();

    // Do other things while cmd is running
    for (int i = 0; i < SLEEP_TIME * SLEEP_TIME * SLEEP_TIME; ++i) {
        std::cout << i << std::endl;
    }

    // Wait for the command to finish
    auto cmdResult = cmdFuture.get();

    // return the result code of the command
    return cmdResult;
}
