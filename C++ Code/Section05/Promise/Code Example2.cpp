//Creating a shared_future

std::promise<void> promise1;
std::shared_future<void> sFuture(promise1.get_future());
