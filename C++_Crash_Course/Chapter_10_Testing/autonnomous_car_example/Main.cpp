/*
 * Services interact vai a service bus
 *    * each service publishes events
 *    * other services subscribe to these events as needed
 *
 * Autonomous Braking
 * 1) Need to determine if a collision is about to happen
 * 2) If a collision is about to happen, tell the car to brake
 * 3) Subscribe to 2 events
 *    a) SpeedUpdate - tells you that the car's speeed has changed
 *    b) CarDetected - tells you that another car has been detected
 *                     in front of you.
 * 4) Responsible for publishing a BrakeCommand to the service bus
 *    whenever an imminent collision is detected.
 *    You publish the BrakeCommand using a ServiceBus object that has a
 *    publish method
 * 5) Need to exponse an observe method so you can subscribe to SpeedUpdate
 *    and CarDetected events on the service.
 */
#include <stdexcept>
#include <iostream>
#include <functional>


class SpeedUpdate {
  public:
    double velocity_mps;
};

class CarDetected {
  public:
    double distance_m;
    double velocity_mps;
};

class BrakeCommand {
  public:
    double time_to_collision_s;
};

using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

class IServiceBus {
  public:
    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(const SpeedUpdateCallback&) = 0;
    virtual void subscribe(const CarDetectedCallback&) = 0;
};

class MockServiceBus : public IServiceBus {
  void publish(const BrakeCommand& cmd) override {
    ++commands_published;
    last_command = cmd;
  }

  void subscribe(const SpeedUpdateCallback& callback) override {
    speed_update_callback = callback;
  }

  void subscribe(const CarDetectedCallback& callback) override {
    car_detected_callback = callback;
  }

  BrakeCommand last_command {};
  int commands_published {};
  SpeedUpdateCallback speed_update_callback {};
  CarDetectedCallback car_detected_callback {};
};

class AutoBrake {
  public:
    AutoBrake([[maybe_unused]]IServiceBus& bus)
      : collision_threshold_s{5}, speed_mps{} {}
/*
    void observe([[maybe_unused]] const SpeedUpdate& x) {
      speed_mps = x.velocity_mps;
    }

    void observe(const CarDetected& cd) {
      const auto relative_velocity_mps {speed_mps -  cd.velocity_mps};
      const auto time_to_collision_s {cd.distance_m / relative_velocity_mps};
      if (time_to_collision_s > 0 && time_to_collision_s <= collision_threshold_s) {
        publish(BrakeCommand {time_to_collision_s});
      }
    }
    */

    void set_collision_threshold_s(double x) {
      if (x < 1) {
        throw std::exception{};
      }
      collision_threshold_s = x;
    }

    double get_collision_threshold_s() const {
      return collision_threshold_s;
    }

    double get_speed_mps() const {
      return speed_mps;
    }

  private:
    double collision_threshold_s;
    double speed_mps;
//    const T& publish;   // reference to the publish method of the service bus
};

// tests
constexpr void assert_that(bool statement, const char* message) 
{
  if (!statement) {
    throw std::runtime_error{message};
  }
}

void initial_speed_is_zero() 
{
  MockServiceBus bus {};
  AutoBrake auto_brake {bus};
  assert_that(static_cast<int>(auto_brake.get_speed_mps()) == 0L,
      "speed not equal to 0");
}

void initial_sensitivity_is_five()
{
  MockServiceBus bus {};
  AutoBrake auto_brake {bus};
  assert_that(static_cast<int>(auto_brake.get_collision_threshold_s()) == 5L,
      "sensitivity not equal to 5");
}

void sensitivity_greater_than_1()
{
  MockServiceBus bus {};
  AutoBrake auto_brake {bus};
  try {
    auto_brake.set_collision_threshold_s(0.05L);
  } catch (const std::exception&) {
    return;
  }
  assert_that(false, "no exception thrown");
}
/*
void speed_is_saved()
{
  MockServiceBus bus {};
  AutoBrake auto_brake {bus};
  auto_brake.observe(SpeedUpdate{100L});
  assert_that(static_cast<int>(auto_brake.get_speed_mps()) == 100, "speed not saved to 100");
  auto_brake.observe(SpeedUpdate{50L});
  assert_that(static_cast<int>(auto_brake.get_speed_mps()) == 50, "speed not saved to 50");
  auto_brake.observe(SpeedUpdate{0L});
  assert_that(static_cast<int>(auto_brake.get_speed_mps()) == 0, "speed not saved to 0");
}

void alert_when_imminent()
{
  int brake_commands_published {};
  AutoBrake auto_brake{ [&brake_commands_published](const BrakeCommand&) {
    ++brake_commands_published;
  }};
  auto_brake.set_collision_threshold_s(10L);
  auto_brake.observe(SpeedUpdate{100L});
  auto_brake.observe(CarDetected{100L, 0L});
  assert_that(brake_commands_published == 1, 
      "brake commands published not one");
}

void no_alert_when_not_imminent()
{
  int brake_commands_published {};
  AutoBrake auto_brake{ [&brake_commands_published](const BrakeCommand&) {
    ++brake_commands_published;
  }};
  auto_brake.set_collision_threshold_s(2L);
  auto_brake.observe(SpeedUpdate{100L});
  auto_brake.observe(CarDetected{1000L, 50L});
  assert_that(brake_commands_published == 0, 
      "brake command published");
}
*/
// Test Runner
void run_test(void(*unit_test)(), const char* name) 
{
  try {
    unit_test();
    std::cout << "[+] Test " << name << " successful.\n";
  } catch (const std::exception& e) {
    std::cerr << "[-] Test failure in " << name << ". " << e.what()
      << ".\n";
  }
}

int main()
{
  run_test(initial_speed_is_zero, "initial speed is 0");
  run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
  run_test(sensitivity_greater_than_1, "sensitivity greater than 1");
//run_test(speed_is_saved, "speed was saved");
//run_test(alert_when_imminent, "alert when immenent");
//run_test(no_alert_when_not_imminent, "no alert when not immenent");
}
