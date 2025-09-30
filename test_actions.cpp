#include <gtest/gtest.h>
extern "C" {
    #include "./actions.h"
    #include "./email.h"
    #include "./charge_rate.h"
}

#include <cstdio>
#include <cstring>
#include <string>
#include <unistd.h>
#include <fcntl.h>

class OutputCapture {
public:
    void start() {
        fflush(stdout);
        // Save old stdout fd
        old_stdout_fd = dup(fileno(stdout));
        // Create a pipe
        pipe(fds);
        // Redirect stdout to pipe write end
        dup2(fds[1], fileno(stdout));
        close(fds[1]);
    }

    std::string stop() {
        fflush(stdout);
        // Restore original stdout
        dup2(old_stdout_fd, fileno(stdout));
        close(old_stdout_fd);

        // Read from pipe
        char buffer[4096];
        ssize_t count = read(fds[0], buffer, sizeof(buffer) - 1);
        close(fds[0]);
        if (count > 0) {
            buffer[count] = '\0';
            return std::string(buffer);
        }
        return "";
    }

private:
    int fds[2];
    int old_stdout_fd;
};

TEST(EmailActuatorTest, SendsEmail) {
    Actuator* email = email_actuator_create("test@example.com");
    ASSERT_NE(email, nullptr);

    OutputCapture capture;
    capture.start();
    email->actuate(email, "Test email alert");
    std::string output = capture.stop();

    EXPECT_NE(output.find("[EMAIL] Sending alert to test@example.com: Test email alert"), std::string::npos);

    email->destroy(email);
}

TEST(ChargeRateActuatorTest, RestrictsChargeRate) {
    Actuator* charge = charge_rate_actuator_create(60);
    ASSERT_NE(charge, nullptr);

    OutputCapture capture;
    capture.start();
    charge->actuate(charge, "Test charge restriction alert");
    std::string output = capture.stop();

    EXPECT_NE(output.find("[CHARGE RATE] Restricting charging rate to 60% due to alert: Test charge restriction alert"), std::string::npos);

    charge->destroy(charge);
}

