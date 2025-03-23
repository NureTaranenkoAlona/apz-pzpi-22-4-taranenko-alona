// Інтерфейс для стратегії
public interface IPaymentStrategy
{
    void Pay(decimal amount);
}

// Конкретна стратегія: оплата кредитною карткою
public class CreditCardPayment : IPaymentStrategy
{
    private string _cardNumber;

    public CreditCardPayment(string cardNumber)
    {
        _cardNumber = cardNumber;
    }

    public void Pay(decimal amount)
    {
        Console.WriteLine($"Paid {amount} UAH using credit card {_cardNumber}.");
    }
}

// Конкретна стратегія: оплата через PayPal
public class PayPalPayment : IPaymentStrategy
{
    private string _email;

    public PayPalPayment(string email)
    {
        _email = email;
    }

    public void Pay(decimal amount)
    {
        Console.WriteLine($"Paid {amount} UAH via PayPal account {_email}.");
    }
}

// Конкретна стратегія: оплата криптовалютою
public class CryptoPayment : IPaymentStrategy
{
    private string _walletAddress;

    public CryptoPayment(string walletAddress)
    {
        _walletAddress = walletAddress;
    }

    public void Pay(decimal amount)
    {
        Console.WriteLine($"Paid {amount} UAH in cryptocurrency to wallet {_walletAddress}.");
    }
}

// Контекст
public class PaymentContext
{
    private IPaymentStrategy _paymentStrategy;

    public void SetPaymentStrategy(IPaymentStrategy paymentStrategy)
    {
        _paymentStrategy = paymentStrategy;
    }

    public void ProcessPayment(decimal amount)
    {
        if (_paymentStrategy == null)
        {
            throw new InvalidOperationException("Payment strategy is not set.");
        }

        _paymentStrategy.Pay(amount);
    }
}

// Головна функція
class Program
{
    static void Main()
    {
        var context = new PaymentContext();

        context.SetPaymentStrategy(new CreditCardPayment("1234-5678-9012-3456"));
        context.ProcessPayment(1000);

        context.SetPaymentStrategy(new PayPalPayment("user@example.com"));
        context.ProcessPayment(500);

        context.SetPaymentStrategy(new CryptoPayment("1A2b3C4d5E6f7G8h9I0J"));
        context.ProcessPayment(3000);
    }
}
