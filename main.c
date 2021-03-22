#include <nvml.h>
#include <stdio.h>


int main(void)
{
    int result = 0;
    nvmlReturn_t nvmlReturn;
    nvmlDevice_t nvmlDevice = 0;

    char buf[NVML_DEVICE_INFOROM_VERSION_BUFFER_SIZE] = { 0 };

    printf("*** nvmlInit ***\n");
    nvmlReturn = nvmlInit();

    if (NVML_SUCCESS == nvmlReturn)
    {
        printf("NVML_SUCCESS\n");
    }
    else
    {
        result = 1;
        switch (nvmlReturn)
        {
            case NVML_ERROR_DRIVER_NOT_LOADED:
                printf("NVML_ERROR_DRIVER_NOT_LOADED\n");
                break;
            case NVML_ERROR_NO_PERMISSION:
                printf("NVML_ERROR_NO_PERMISSION\n");
                break;
            case NVML_ERROR_UNKNOWN:
                printf("NVML_ERROR_UNKNOWN\n");
                break;
            default:
                printf("Unexpected result code: 0x%x\n", nvmlReturn);
        }
    }

    printf("*** nvmlDeviceGetHandleByIndex ***\n");
    nvmlReturn = nvmlDeviceGetHandleByIndex(0, &nvmlDevice);
    if (NVML_SUCCESS == nvmlReturn)
    {
        printf("NVML_SUCCESS\n");
    }
    else
    {
        result = 1;
        switch (nvmlReturn)
        {
            case NVML_ERROR_UNINITIALIZED:
                printf("NVML_ERROR_UNINITIALIZED\n");
                break;
            case NVML_ERROR_INVALID_ARGUMENT:
                printf("NVML_ERROR_INVALID_ARGUMENT\n");
                break;
            case NVML_ERROR_INSUFFICIENT_POWER:
                printf("NVML_ERROR_INSUFFICIENT_POWER\n");
                break;
            case NVML_ERROR_NO_PERMISSION:
                printf("NVML_ERROR_NO_PERMISSION\n");
                break;
            case NVML_ERROR_IRQ_ISSUE:
                printf("NVML_ERROR_IRQ_ISSUE\n");
                break;
            case NVML_ERROR_GPU_IS_LOST:
                printf("NVML_ERROR_GPU_IS_LOST\n");
                break;
            case NVML_ERROR_UNKNOWN:
                printf("NVML_ERROR_UNKNOWN\n");
                break;
            default:
                printf("Unexpected result code: 0x%x\n", nvmlReturn);
        }
    }

    printf("*** nvmlDeviceGetInforomVersion ***\n");
    nvmlReturn = nvmlDeviceGetInforomVersion(nvmlDevice, NVML_INFOROM_OEM, buf, sizeof(buf));
    if (NVML_SUCCESS == nvmlReturn)
    {
        printf("NVML_SUCCESS\n");
    }
    else
    {
        result = 1;
        switch (nvmlReturn)
        {
            case NVML_ERROR_UNINITIALIZED:
                printf("NVML_ERROR_UNINITIALIZED\n");
                break;
            case NVML_ERROR_INVALID_ARGUMENT:
                printf("NVML_ERROR_INVALID_ARGUMENT\n");
                break;
            case NVML_ERROR_INSUFFICIENT_SIZE:
                printf("NVML_ERROR_INSUFFICIENT_SIZE\n");
                break;
            case NVML_ERROR_NOT_SUPPORTED:
                printf("NVML_ERROR_NOT_SUPPORTED\n");
                break;
            case NVML_ERROR_GPU_IS_LOST:
                printf("NVML_ERROR_GPU_IS_LOST\n");
                break;
            case NVML_ERROR_UNKNOWN:
                printf("NVML_ERROR_UNKNOWN\n");
                break;
            default:
                printf("Unexpected result code: 0x%x\n", nvmlReturn);
        }
    }


    printf("*** nvmlDeviceValidateInforom ***\n");
    nvmlReturn = nvmlDeviceValidateInforom(nvmlDevice);
    if (NVML_SUCCESS == nvmlReturn)
    {
        printf("NVML_SUCCESS\n");
    }
    else
    {
        result = 1;
        switch (nvmlReturn)
        {
            case NVML_ERROR_CORRUPTED_INFOROM:
                printf("NVML_ERROR_CORRUPTED_INFOROM\n");
                break;
            case NVML_ERROR_UNINITIALIZED:
                printf("NVML_ERROR_UNINITIALIZED\n");
                break;
            case NVML_ERROR_NOT_SUPPORTED:
                printf("NVML_ERROR_NOT_SUPPORTED\n");
                break;
            case NVML_ERROR_GPU_IS_LOST:
                printf("NVML_ERROR_GPU_IS_LOST\n");
                break;
            case NVML_ERROR_UNKNOWN:
                printf("NVML_ERROR_UNKNOWN\n");
                break;
            default:
                printf("Unexpected result code: 0x%x\n", nvmlReturn);
        }
    }

    printf("*** nvmlShutdown ***\n");
    nvmlReturn = nvmlShutdown();

    if (NVML_SUCCESS == nvmlReturn)
    {
        printf("NVML_SUCCESS\n");
    }
    else
    {
        result = 1;
        switch (nvmlReturn)
        {
            case NVML_ERROR_UNINITIALIZED:
                printf("NVML_ERROR_UNINITIALIZED\n");
                break;
            case NVML_ERROR_UNKNOWN:
                printf("NVML_ERROR_UNKNOWN\n");
                break;
            default:
                printf("Unexpected result code: 0x%x\n", nvmlReturn);
        }
    }

    return result;
}

