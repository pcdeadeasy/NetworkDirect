#include "stdafx.h"
#include <winerror.h>

LPCWSTR get_error_symbol(HRESULT hr)
{
  LPCWSTR ans = NULL;
  if ((ans = get_ndstatus_symbol(hr)) == NULL)
  {
    if ((ans = get_win_error_symbol(hr)) == NULL)
    {
      ans = L"ERROR_ULISTED";
    }
  }
  return ans;
}

LPCWSTR get_win_error_symbol(HRESULT hr) {
  LPCWSTR ans;
  switch (hr) {
  case 0x00000002:
    ans = L"ERROR_FILE_NOT_FOUND";
    break;
  case 0x00000003:
    ans = L"ERROR_PATH_NOT_FOUND";
    break;
  case 0x00000004:
    ans = L"ERROR_TOO_MANY_OPEN_FILES";
    break;
  case 0x00000005:
    ans = L"ERROR_ACCESS_DENIED";
    break;
  case 0x00000006:
    ans = L"ERROR_INVALID_HANDLE";
    break;
  case 0x00000007:
    ans = L"ERROR_ARENA_TRASHED";
    break;
  case 0x00000009:
    ans = L"ERROR_INVALID_BLOCK";
    break;
  case 0x0000000A:
    ans = L"ERROR_BAD_ENVIRONMENT";
    break;
  case 0x0000000B:
    ans = L"ERROR_BAD_FORMAT";
    break;
  case 0x0000000C:
    ans = L"ERROR_INVALID_ACCESS";
    break;
  case 0x0000000D:
    ans = L"ERROR_INVALID_DATA";
    break;
  case 0x0000000E:
    ans = L"ERROR_OUTOFMEMORY";
    break;
  case 0x0000000F:
    ans = L"ERROR_INVALID_DRIVE";
    break;
  case 0x00000010:
    ans = L"ERROR_CURRENT_DIRECTORY";
    break;
  case 0x00000011:
    ans = L"ERROR_NOT_SAME_DEVICE";
    break;
  case 0x00000012:
    ans = L"ERROR_NO_MORE_FILES";
    break;
  case 0x00000013:
    ans = L"ERROR_WRITE_PROTECT";
    break;
  case 0x00000014:
    ans = L"ERROR_BAD_UNIT";
    break;
  case 0x00000015:
    ans = L"ERROR_NOT_READY";
    break;
  case 0x00000016:
    ans = L"ERROR_BAD_COMMAND";
    break;
  case 0x00000017:
    ans = L"ERROR_CRC";
    break;
  case 0x00000018:
    ans = L"ERROR_BAD_LENGTH";
    break;
  case 0x00000019:
    ans = L"ERROR_SEEK";
    break;
  case 0x0000001A:
    ans = L"ERROR_NOT_DOS_DISK";
    break;
  case 0x0000001B:
    ans = L"ERROR_SECTOR_NOT_FOUND";
    break;
  case 0x0000001C:
    ans = L"ERROR_OUT_OF_PAPER";
    break;
  case 0x0000001D:
    ans = L"ERROR_WRITE_FAULT";
    break;
  case 0x0000001E:
    ans = L"ERROR_READ_FAULT";
    break;
  case 0x0000001F:
    ans = L"ERROR_GEN_FAILURE";
    break;
  case 0x00000020:
    ans = L"ERROR_SHARING_VIOLATION";
    break;
  case 0x00000021:
    ans = L"ERROR_LOCK_VIOLATION";
    break;
  case 0x00000022:
    ans = L"ERROR_WRONG_DISK";
    break;
  case 0x00000024:
    ans = L"ERROR_SHARING_BUFFER_EXCEEDED";
    break;
  case 0x00000026:
    ans = L"ERROR_HANDLE_EOF";
    break;
  case 0x00000027:
    ans = L"ERROR_HANDLE_DISK_FULL";
    break;
  case 0x00000032:
    ans = L"ERROR_NOT_SUPPORTED";
    break;
  case 0x00000033:
    ans = L"ERROR_REM_NOT_LIST";
    break;
  case 0x00000034:
    ans = L"ERROR_DUP_NAME";
    break;
  case 0x00000035:
    ans = L"ERROR_BAD_NETPATH";
    break;
  case 0x00000036:
    ans = L"ERROR_NETWORK_BUSY";
    break;
  case 0x00000038:
    ans = L"ERROR_TOO_MANY_CMDS";
    break;
  case 0x00000039:
    ans = L"ERROR_ADAP_HDW_ERR";
    break;
  case 0x0000003A:
    ans = L"ERROR_BAD_NET_RESP";
    break;
  case 0x0000003B:
    ans = L"ERROR_UNEXP_NET_ERR";
    break;
  case 0x0000003C:
    ans = L"ERROR_BAD_REM_ADAP";
    break;
  case 0x0000003D:
    ans = L"ERROR_PRINTQ_FULL";
    break;
  case 0x0000003E:
    ans = L"ERROR_NO_SPOOL_SPACE";
    break;
  case 0x0000003F:
    ans = L"ERROR_PRINT_CANCELLED";
    break;
  case 0x00000040:
    ans = L"ERROR_NETNAME_DELETED";
    break;
  case 0x00000041:
    ans = L"ERROR_NETWORK_ACCESS_DENIED";
    break;
  case 0x00000042:
    ans = L"ERROR_BAD_DEV_TYPE";
    break;
  case 0x00000043:
    ans = L"ERROR_BAD_NET_NAME";
    break;
  case 0x00000044:
    ans = L"ERROR_TOO_MANY_NAMES";
    break;
  case 0x00000045:
    ans = L"ERROR_TOO_MANY_SESS";
    break;
  case 0x00000046:
    ans = L"ERROR_SHARING_PAUSED";
    break;
  case 0x00000047:
    ans = L"ERROR_REQ_NOT_ACCEP";
    break;
  case 0x00000048:
    ans = L"ERROR_REDIR_PAUSED";
    break;
  case 0x00000050:
    ans = L"ERROR_FILE_EXISTS";
    break;
  case 0x00000052:
    ans = L"ERROR_CANNOT_MAKE";
    break;
  case 0x00000053:
    ans = L"ERROR_FAIL_I24";
    break;
  case 0x00000054:
    ans = L"ERROR_OUT_OF_STRUCTURES";
    break;
  case 0x00000055:
    ans = L"ERROR_ALREADY_ASSIGNED";
    break;
  case 0x00000056:
    ans = L"ERROR_INVALID_PASSWORD";
    break;
  case 0x00000058:
    ans = L"ERROR_NET_WRITE_FAULT";
    break;
  case 0x00000059:
    ans = L"ERROR_NO_PROC_SLOTS";
    break;
  case 0x00000064:
    ans = L"ERROR_TOO_MANY_SEMAPHORES";
    break;
  case 0x00000065:
    ans = L"ERROR_EXCL_SEM_ALREADY_OWNED";
    break;
  case 0x00000066:
    ans = L"ERROR_SEM_IS_SET";
    break;
  case 0x00000067:
    ans = L"ERROR_TOO_MANY_SEM_REQUESTS";
    break;
  case 0x00000068:
    ans = L"ERROR_INVALID_AT_INTERRUPT_TIME";
    break;
  case 0x00000069:
    ans = L"ERROR_SEM_OWNER_DIED";
    break;
  case 0x0000006A:
    ans = L"ERROR_SEM_USER_LIMIT";
    break;
  case 0x0000006B:
    ans = L"ERROR_DISK_CHANGE";
    break;
  case 0x0000006C:
    ans = L"ERROR_DRIVE_LOCKED";
    break;
  case 0x0000006D:
    ans = L"ERROR_BROKEN_PIPE";
    break;
  case 0x0000006E:
    ans = L"ERROR_OPEN_FAILED";
    break;
  case 0x0000006F:
    ans = L"ERROR_BUFFER_OVERFLOW";
    break;
  case 0x00000070:
    ans = L"ERROR_DISK_FULL";
    break;
  case 0x00000071:
    ans = L"ERROR_NO_MORE_SEARCH_HANDLES";
    break;
  case 0x00000072:
    ans = L"ERROR_INVALID_TARGET_HANDLE";
    break;
  case 0x00000075:
    ans = L"ERROR_INVALID_CATEGORY";
    break;
  case 0x00000076:
    ans = L"ERROR_INVALID_VERIFY_SWITCH";
    break;
  case 0x00000077:
    ans = L"ERROR_BAD_DRIVER_LEVEL";
    break;
  case 0x00000078:
    ans = L"ERROR_CALL_NOT_IMPLEMENTED";
    break;
  case 0x00000079:
    ans = L"ERROR_SEM_TIMEOUT";
    break;
  case 0x0000007C:
    ans = L"ERROR_INVALID_LEVEL";
    break;
  case 0x0000007D:
    ans = L"ERROR_NO_VOLUME_LABEL";
    break;
  case 0x0000007E:
    ans = L"ERROR_MOD_NOT_FOUND";
    break;
  case 0x0000007F:
    ans = L"ERROR_PROC_NOT_FOUND";
    break;
  case 0x00000080:
    ans = L"ERROR_WAIT_NO_CHILDREN";
    break;
  case 0x00000081:
    ans = L"ERROR_CHILD_NOT_COMPLETE";
    break;
  case 0x00000082:
    ans = L"ERROR_DIRECT_ACCESS_HANDLE";
    break;
  case 0x00000083:
    ans = L"ERROR_NEGATIVE_SEEK";
    break;
  case 0x00000084:
    ans = L"ERROR_SEEK_ON_DEVICE";
    break;
  case 0x00000085:
    ans = L"ERROR_IS_JOIN_TARGET";
    break;
  case 0x00000086:
    ans = L"ERROR_IS_JOINED";
    break;
  case 0x00000087:
    ans = L"ERROR_IS_SUBSTED";
    break;
  case 0x00000088:
    ans = L"ERROR_NOT_JOINED";
    break;
  case 0x00000089:
    ans = L"ERROR_NOT_SUBSTED";
    break;
  case 0x0000008A:
    ans = L"ERROR_JOIN_TO_JOIN";
    break;
  case 0x0000008B:
    ans = L"ERROR_SUBST_TO_SUBST";
    break;
  case 0x0000008C:
    ans = L"ERROR_JOIN_TO_SUBST";
    break;
  case 0x0000008D:
    ans = L"ERROR_SUBST_TO_JOIN";
    break;
  case 0x0000008E:
    ans = L"ERROR_BUSY_DRIVE";
    break;
  case 0x0000008F:
    ans = L"ERROR_SAME_DRIVE";
    break;
  case 0x00000090:
    ans = L"ERROR_DIR_NOT_ROOT";
    break;
  case 0x00000091:
    ans = L"ERROR_DIR_NOT_EMPTY";
    break;
  case 0x00000092:
    ans = L"ERROR_IS_SUBST_PATH";
    break;
  case 0x00000093:
    ans = L"ERROR_IS_JOIN_PATH";
    break;
  case 0x00000094:
    ans = L"ERROR_PATH_BUSY";
    break;
  case 0x00000095:
    ans = L"ERROR_IS_SUBST_TARGET";
    break;
  case 0x00000096:
    ans = L"ERROR_SYSTEM_TRACE";
    break;
  case 0x00000097:
    ans = L"ERROR_INVALID_EVENT_COUNT";
    break;
  case 0x00000098:
    ans = L"ERROR_TOO_MANY_MUXWAITERS";
    break;
  case 0x00000099:
    ans = L"ERROR_INVALID_LIST_FORMAT";
    break;
  case 0x0000009A:
    ans = L"ERROR_LABEL_TOO_LONG";
    break;
  case 0x0000009B:
    ans = L"ERROR_TOO_MANY_TCBS";
    break;
  case 0x0000009C:
    ans = L"ERROR_SIGNAL_REFUSED";
    break;
  case 0x0000009D:
    ans = L"ERROR_DISCARDED";
    break;
  case 0x0000009E:
    ans = L"ERROR_NOT_LOCKED";
    break;
  case 0x0000009F:
    ans = L"ERROR_BAD_THREADID_ADDR";
    break;
  case 0x000000A0:
    ans = L"ERROR_BAD_ARGUMENTS";
    break;
  case 0x000000A1:
    ans = L"ERROR_BAD_PATHNAME";
    break;
  case 0x000000A2:
    ans = L"ERROR_SIGNAL_PENDING";
    break;
  case 0x000000A4:
    ans = L"ERROR_MAX_THRDS_REACHED";
    break;
  case 0x000000A7:
    ans = L"ERROR_LOCK_FAILED";
    break;
  case 0x000000AB:
    ans = L"ERROR_DEVICE_SUPPORT_IN_PROGRESS";
    break;
  case 0x000000AD:
    ans = L"ERROR_CANCEL_VIOLATION";
    break;
  case 0x000000AE:
    ans = L"ERROR_ATOMIC_LOCKS_NOT_SUPPORTED";
    break;
  case 0x000000B4:
    ans = L"ERROR_INVALID_SEGMENT_NUMBER";
    break;
  case 0x000000B6:
    ans = L"ERROR_INVALID_ORDINAL";
    break;
  case 0x000000B7:
    ans = L"ERROR_ALREADY_EXISTS";
    break;
  case 0x000000BA:
    ans = L"ERROR_INVALID_FLAG_NUMBER";
    break;
  case 0x000000BB:
    ans = L"ERROR_SEM_NOT_FOUND";
    break;
  case 0x000000BC:
    ans = L"ERROR_INVALID_STARTING_CODESEG";
    break;
  case 0x000000BD:
    ans = L"ERROR_INVALID_STACKSEG";
    break;
  case 0x000000BE:
    ans = L"ERROR_INVALID_MODULETYPE";
    break;
  case 0x000000BF:
    ans = L"ERROR_INVALID_EXE_SIGNATURE";
    break;
  case 0x000000C0:
    ans = L"ERROR_EXE_MARKED_INVALID";
    break;
  case 0x000000C1:
    ans = L"ERROR_BAD_EXE_FORMAT";
    break;
  case 0x000000C3:
    ans = L"ERROR_INVALID_MINALLOCSIZE";
    break;
  case 0x000000C4:
    ans = L"ERROR_DYNLINK_FROM_INVALID_RING";
    break;
  case 0x000000C5:
    ans = L"ERROR_IOPL_NOT_ENABLED";
    break;
  case 0x000000C6:
    ans = L"ERROR_INVALID_SEGDPL";
    break;
  case 0x000000C8:
    ans = L"ERROR_RING2SEG_MUST_BE_MOVABLE";
    break;
  case 0x000000C9:
    ans = L"ERROR_RELOC_CHAIN_XEEDS_SEGLIM";
    break;
  case 0x000000CA:
    ans = L"ERROR_INFLOOP_IN_RELOC_CHAIN";
    break;
  case 0x000000CB:
    ans = L"ERROR_ENVVAR_NOT_FOUND";
    break;
  case 0x000000CD:
    ans = L"ERROR_NO_SIGNAL_SENT";
    break;
  case 0x000000CE:
    ans = L"ERROR_FILENAME_EXCED_RANGE";
    break;
  case 0x000000CF:
    ans = L"ERROR_RING2_STACK_IN_USE";
    break;
  case 0x000000D0:
    ans = L"ERROR_META_EXPANSION_TOO_LONG";
    break;
  case 0x000000D1:
    ans = L"ERROR_INVALID_SIGNAL_NUMBER";
    break;
  case 0x000000D2:
    ans = L"ERROR_THREAD_1_INACTIVE";
    break;
  case 0x000000D4:
    ans = L"ERROR_LOCKED";
    break;
  case 0x000000D6:
    ans = L"ERROR_TOO_MANY_MODULES";
    break;
  case 0x000000D7:
    ans = L"ERROR_NESTING_NOT_ALLOWED";
    break;
  case 0x000000D8:
    ans = L"ERROR_EXE_MACHINE_TYPE_MISMATCH";
    break;
  case 0x000000D9:
    ans = L"ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY";
    break;
  case 0x000000DA:
    ans = L"ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY";
    break;
  case 0x000000DC:
    ans = L"ERROR_FILE_CHECKED_OUT";
    break;
  case 0x000000DD:
    ans = L"ERROR_CHECKOUT_REQUIRED";
    break;
  case 0x000000DE:
    ans = L"ERROR_BAD_FILE_TYPE";
    break;
  case 0x000000DF:
    ans = L"ERROR_FILE_TOO_LARGE";
    break;
  case 0x000000E0:
    ans = L"ERROR_FORMS_AUTH_REQUIRED";
    break;
  case 0x000000E1:
    ans = L"ERROR_VIRUS_INFECTED";
    break;
  case 0x000000E2:
    ans = L"ERROR_VIRUS_DELETED";
    break;
  case 0x000000E5:
    ans = L"ERROR_PIPE_LOCAL";
    break;
  case 0x000000E6:
    ans = L"ERROR_BAD_PIPE";
    break;
  case 0x000000E7:
    ans = L"ERROR_PIPE_BUSY";
    break;
  case 0x000000E8:
    ans = L"ERROR_NO_DATA";
    break;
  case 0x000000E9:
    ans = L"ERROR_PIPE_NOT_CONNECTED";
    break;
  case 0x000000EB:
    ans = L"ERROR_NO_WORK_DONE";
    break;
  case 0x000000F0:
    ans = L"ERROR_VC_DISCONNECTED";
    break;
  case 0x000000FE:
    ans = L"ERROR_INVALID_EA_NAME";
    break;
  case 0x000000FF:
    ans = L"ERROR_EA_LIST_INCONSISTENT";
    break;
  case 0x00000103:
    ans = L"ERROR_NO_MORE_ITEMS";
    break;
  case 0x0000010A:
    ans = L"ERROR_CANNOT_COPY";
    break;
  case 0x0000010B:
    ans = L"ERROR_DIRECTORY";
    break;
  case 0x00000113:
    ans = L"ERROR_EAS_DIDNT_FIT";
    break;
  case 0x00000114:
    ans = L"ERROR_EA_FILE_CORRUPT";
    break;
  case 0x00000115:
    ans = L"ERROR_EA_TABLE_FULL";
    break;
  case 0x00000116:
    ans = L"ERROR_INVALID_EA_HANDLE";
    break;
  case 0x0000011A:
    ans = L"ERROR_EAS_NOT_SUPPORTED";
    break;
  case 0x00000120:
    ans = L"ERROR_NOT_OWNER";
    break;
  case 0x0000012A:
    ans = L"ERROR_TOO_MANY_POSTS";
    break;
  case 0x0000012B:
    ans = L"ERROR_PARTIAL_COPY";
    break;
  case 0x0000012C:
    ans = L"ERROR_OPLOCK_NOT_GRANTED";
    break;
  case 0x0000012D:
    ans = L"ERROR_INVALID_OPLOCK_PROTOCOL";
    break;
  case 0x0000012E:
    ans = L"ERROR_DISK_TOO_FRAGMENTED";
    break;
  case 0x0000012F:
    ans = L"ERROR_DELETE_PENDING";
    break;
  case 0x00000130:
    ans = L"ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING";
    break;
  case 0x00000131:
    ans = L"ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME";
    break;
  case 0x00000132:
    ans = L"ERROR_SECURITY_STREAM_IS_INCONSISTENT";
    break;
  case 0x00000133:
    ans = L"ERROR_INVALID_LOCK_RANGE";
    break;
  case 0x00000134:
    ans = L"ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT";
    break;
  case 0x00000135:
    ans = L"ERROR_NOTIFICATION_GUID_ALREADY_DEFINED";
    break;
  case 0x00000136:
    ans = L"ERROR_INVALID_EXCEPTION_HANDLER";
    break;
  case 0x00000137:
    ans = L"ERROR_DUPLICATE_PRIVILEGES";
    break;
  case 0x00000138:
    ans = L"ERROR_NO_RANGES_PROCESSED";
    break;
  case 0x00000139:
    ans = L"ERROR_NOT_ALLOWED_ON_SYSTEM_FILE";
    break;
  case 0x0000013A:
    ans = L"ERROR_DISK_RESOURCES_EXHAUSTED";
    break;
  case 0x0000013B:
    ans = L"ERROR_INVALID_TOKEN";
    break;
  case 0x0000013C:
    ans = L"ERROR_DEVICE_FEATURE_NOT_SUPPORTED";
    break;
  case 0x0000013D:
    ans = L"ERROR_MR_MID_NOT_FOUND";
    break;
  case 0x0000013E:
    ans = L"ERROR_SCOPE_NOT_FOUND";
    break;
  case 0x0000013F:
    ans = L"ERROR_UNDEFINED_SCOPE";
    break;
  case 0x00000140:
    ans = L"ERROR_INVALID_CAP";
    break;
  case 0x00000141:
    ans = L"ERROR_DEVICE_UNREACHABLE";
    break;
  case 0x00000142:
    ans = L"ERROR_DEVICE_NO_RESOURCES";
    break;
  case 0x00000143:
    ans = L"ERROR_DATA_CHECKSUM_ERROR";
    break;
  case 0x00000144:
    ans = L"ERROR_INTERMIXED_KERNEL_EA_OPERATION";
    break;
  case 0x00000146:
    ans = L"ERROR_FILE_LEVEL_TRIM_NOT_SUPPORTED";
    break;
  case 0x00000147:
    ans = L"ERROR_OFFSET_ALIGNMENT_VIOLATION";
    break;
  case 0x00000148:
    ans = L"ERROR_INVALID_FIELD_IN_PARAMETER_LIST";
    break;
  case 0x00000149:
    ans = L"ERROR_OPERATION_IN_PROGRESS";
    break;
  case 0x0000014A:
    ans = L"ERROR_BAD_DEVICE_PATH";
    break;
  case 0x0000014B:
    ans = L"ERROR_TOO_MANY_DESCRIPTORS";
    break;
  case 0x0000014C:
    ans = L"ERROR_SCRUB_DATA_DISABLED";
    break;
  case 0x0000014D:
    ans = L"ERROR_NOT_REDUNDANT_STORAGE";
    break;
  case 0x0000014E:
    ans = L"ERROR_RESIDENT_FILE_NOT_SUPPORTED";
    break;
  case 0x0000014F:
    ans = L"ERROR_COMPRESSED_FILE_NOT_SUPPORTED";
    break;
  case 0x00000150:
    ans = L"ERROR_DIRECTORY_NOT_SUPPORTED";
    break;
  case 0x00000151:
    ans = L"ERROR_NOT_READ_FROM_COPY";
    break;
  case 0x00000152:
    ans = L"ERROR_FT_WRITE_FAILURE";
    break;
  case 0x00000153:
    ans = L"ERROR_FT_DI_SCAN_REQUIRED";
    break;
  case 0x00000154:
    ans = L"ERROR_INVALID_KERNEL_INFO_VERSION";
    break;
  case 0x00000155:
    ans = L"ERROR_INVALID_PEP_INFO_VERSION";
    break;
  case 0x00000156:
    ans = L"ERROR_OBJECT_NOT_EXTERNALLY_BACKED";
    break;
  case 0x00000157:
    ans = L"ERROR_EXTERNAL_BACKING_PROVIDER_UNKNOWN";
    break;
  case 0x00000158:
    ans = L"ERROR_COMPRESSION_NOT_BENEFICIAL";
    break;
  case 0x00000159:
    ans = L"ERROR_STORAGE_TOPOLOGY_ID_MISMATCH";
    break;
  case 0x0000015A:
    ans = L"ERROR_BLOCKED_BY_PARENTAL_CONTROLS";
    break;
  case 0x0000015B:
    ans = L"ERROR_BLOCK_TOO_MANY_REFERENCES";
    break;
  case 0x0000015C:
    ans = L"ERROR_MARKED_TO_DISALLOW_WRITES";
    break;
  case 0x0000015D:
    ans = L"ERROR_ENCLAVE_FAILURE";
    break;
  case 0x0000015E:
    ans = L"ERROR_FAIL_NOACTION_REBOOT";
    break;
  case 0x0000015F:
    ans = L"ERROR_FAIL_SHUTDOWN";
    break;
  case 0x00000160:
    ans = L"ERROR_FAIL_RESTART";
    break;
  case 0x00000161:
    ans = L"ERROR_MAX_SESSIONS_REACHED";
    break;
  case 0x00000162:
    ans = L"ERROR_NETWORK_ACCESS_DENIED_EDP";
    break;
  case 0x00000163:
    ans = L"ERROR_DEVICE_HINT_NAME_BUFFER_TOO_SMALL";
    break;
  case 0x00000164:
    ans = L"ERROR_EDP_POLICY_DENIES_OPERATION";
    break;
  case 0x00000165:
    ans = L"ERROR_EDP_DPL_POLICY_CANT_BE_SATISFIED";
    break;
  case 0x00000166:
    ans = L"ERROR_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT";
    break;
  case 0x00000167:
    ans = L"ERROR_DEVICE_IN_MAINTENANCE";
    break;
  case 0x00000168:
    ans = L"ERROR_NOT_SUPPORTED_ON_DAX";
    break;
  case 0x00000169:
    ans = L"ERROR_DAX_MAPPING_EXISTS";
    break;
  case 0x0000016A:
    ans = L"ERROR_CLOUD_FILE_PROVIDER_NOT_RUNNING";
    break;
  case 0x0000016B:
    ans = L"ERROR_CLOUD_FILE_METADATA_CORRUPT";
    break;
  case 0x0000016C:
    ans = L"ERROR_CLOUD_FILE_METADATA_TOO_LARGE";
    break;
  case 0x0000016D:
    ans = L"ERROR_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE";
    break;
  case 0x0000016E:
    ans = L"ERROR_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH";
    break;
  case 0x0000016F:
    ans = L"ERROR_CHILD_PROCESS_BLOCKED";
    break;
  case 0x00000170:
    ans = L"ERROR_STORAGE_LOST_DATA_PERSISTENCE";
    break;
  case 0x00000171:
    ans = L"ERROR_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE";
    break;
  case 0x00000172:
    ans = L"ERROR_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT";
    break;
  case 0x00000173:
    ans = L"ERROR_FILE_SYSTEM_VIRTUALIZATION_BUSY";
    break;
  case 0x00000174:
    ans = L"ERROR_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN";
    break;
  case 0x00000175:
    ans = L"ERROR_GDI_HANDLE_LEAK";
    break;
  case 0x00000176:
    ans = L"ERROR_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS";
    break;
  case 0x00000177:
    ans = L"ERROR_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED";
    break;
  case 0x00000178:
    ans = L"ERROR_NOT_A_CLOUD_FILE";
    break;
  case 0x00000179:
    ans = L"ERROR_CLOUD_FILE_NOT_IN_SYNC";
    break;
  case 0x0000017A:
    ans = L"ERROR_CLOUD_FILE_ALREADY_CONNECTED";
    break;
  case 0x0000017B:
    ans = L"ERROR_CLOUD_FILE_NOT_SUPPORTED";
    break;
  case 0x0000017C:
    ans = L"ERROR_CLOUD_FILE_INVALID_REQUEST";
    break;
  case 0x0000017D:
    ans = L"ERROR_CLOUD_FILE_READ_ONLY_VOLUME";
    break;
  case 0x0000017E:
    ans = L"ERROR_CLOUD_FILE_CONNECTED_PROVIDER_ONLY";
    break;
  case 0x0000017F:
    ans = L"ERROR_CLOUD_FILE_VALIDATION_FAILED";
    break;
  case 0x00000180:
    ans = L"ERROR_SMB1_NOT_AVAILABLE";
    break;
  case 0x00000181:
    ans = L"ERROR_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION";
    break;
  case 0x00000182:
    ans = L"ERROR_CLOUD_FILE_AUTHENTICATION_FAILED";
    break;
  case 0x00000183:
    ans = L"ERROR_CLOUD_FILE_INSUFFICIENT_RESOURCES";
    break;
  case 0x00000184:
    ans = L"ERROR_CLOUD_FILE_NETWORK_UNAVAILABLE";
    break;
  case 0x00000185:
    ans = L"ERROR_CLOUD_FILE_UNSUCCESSFUL";
    break;
  case 0x00000186:
    ans = L"ERROR_CLOUD_FILE_NOT_UNDER_SYNC_ROOT";
    break;
  case 0x00000187:
    ans = L"ERROR_CLOUD_FILE_IN_USE";
    break;
  case 0x00000188:
    ans = L"ERROR_CLOUD_FILE_PINNED";
    break;
  case 0x00000189:
    ans = L"ERROR_CLOUD_FILE_REQUEST_ABORTED";
    break;
  case 0x0000018A:
    ans = L"ERROR_CLOUD_FILE_PROPERTY_CORRUPT";
    break;
  case 0x0000018B:
    ans = L"ERROR_CLOUD_FILE_ACCESS_DENIED";
    break;
  case 0x0000018C:
    ans = L"ERROR_CLOUD_FILE_INCOMPATIBLE_HARDLINKS";
    break;
  case 0x0000018D:
    ans = L"ERROR_CLOUD_FILE_PROPERTY_LOCK_CONFLICT";
    break;
  case 0x0000018E:
    ans = L"ERROR_CLOUD_FILE_REQUEST_CANCELED";
    break;
  case 0x0000018F:
    ans = L"ERROR_EXTERNAL_SYSKEY_NOT_SUPPORTED";
    break;
  case 0x00000190:
    ans = L"ERROR_THREAD_MODE_ALREADY_BACKGROUND";
    break;
  case 0x00000191:
    ans = L"ERROR_THREAD_MODE_NOT_BACKGROUND";
    break;
  case 0x00000192:
    ans = L"ERROR_PROCESS_MODE_ALREADY_BACKGROUND";
    break;
  case 0x00000193:
    ans = L"ERROR_PROCESS_MODE_NOT_BACKGROUND";
    break;
  case 0x00000194:
    ans = L"ERROR_CLOUD_FILE_PROVIDER_TERMINATED";
    break;
  case 0x00000195:
    ans = L"ERROR_NOT_A_CLOUD_SYNC_ROOT";
    break;
  case 0x00000196:
    ans = L"ERROR_FILE_PROTECTED_UNDER_DPL";
    break;
  case 0x00000197:
    ans = L"ERROR_VOLUME_NOT_CLUSTER_ALIGNED";
    break;
  case 0x00000198:
    ans = L"ERROR_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND";
    break;
  case 0x00000199:
    ans = L"ERROR_APPX_FILE_NOT_ENCRYPTED";
    break;
  case 0x0000019A:
    ans = L"ERROR_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED";
    break;
  case 0x0000019B:
    ans = L"ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET";
    break;
  case 0x0000019C:
    ans = L"ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE";
    break;
  case 0x0000019D:
    ans = L"ERROR_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER";
    break;
  case 0x0000019E:
    ans = L"ERROR_LINUX_SUBSYSTEM_NOT_PRESENT";
    break;
  case 0x0000019F:
    ans = L"ERROR_FT_READ_FAILURE";
    break;
  case 0x000001A0:
    ans = L"ERROR_STORAGE_RESERVE_ID_INVALID";
    break;
  case 0x000001A1:
    ans = L"ERROR_STORAGE_RESERVE_DOES_NOT_EXIST";
    break;
  case 0x000001A2:
    ans = L"ERROR_STORAGE_RESERVE_ALREADY_EXISTS";
    break;
  case 0x000001A3:
    ans = L"ERROR_STORAGE_RESERVE_NOT_EMPTY";
    break;
  case 0x000001A4:
    ans = L"ERROR_NOT_A_DAX_VOLUME";
    break;
  case 0x000001A5:
    ans = L"ERROR_NOT_DAX_MAPPABLE";
    break;
  case 0x000001A6:
    ans = L"ERROR_TIME_CRITICAL_THREAD";
    break;
  case 0x000001A7:
    ans = L"ERROR_DPL_NOT_SUPPORTED_FOR_USER";
    break;
  case 0x000001A8:
    ans = L"ERROR_CASE_DIFFERING_NAMES_IN_DIR";
    break;
  case 0x000001C2:
    ans = L"ERROR_CAPAUTHZ_NOT_DEVUNLOCKED";
    break;
  case 0x000001C3:
    ans = L"ERROR_CAPAUTHZ_CHANGE_TYPE";
    break;
  case 0x000001C4:
    ans = L"ERROR_CAPAUTHZ_NOT_PROVISIONED";
    break;
  case 0x000001C5:
    ans = L"ERROR_CAPAUTHZ_NOT_AUTHORIZED";
    break;
  case 0x000001C6:
    ans = L"ERROR_CAPAUTHZ_NO_POLICY";
    break;
  case 0x000001C7:
    ans = L"ERROR_CAPAUTHZ_DB_CORRUPTED";
    break;
  case 0x000001C8:
    ans = L"ERROR_CAPAUTHZ_SCCD_INVALID_CATALOG";
    break;
  case 0x000001C9:
    ans = L"ERROR_CAPAUTHZ_SCCD_NO_AUTH_ENTITY";
    break;
  case 0x000001CA:
    ans = L"ERROR_CAPAUTHZ_SCCD_PARSE_ERROR";
    break;
  case 0x000001CB:
    ans = L"ERROR_CAPAUTHZ_SCCD_DEV_MODE_REQUIRED";
    break;
  case 0x000001CC:
    ans = L"ERROR_CAPAUTHZ_SCCD_NO_CAPABILITY_MATCH";
    break;
  case 0x000001E0:
    ans = L"ERROR_PNP_QUERY_REMOVE_DEVICE_TIMEOUT";
    break;
  case 0x000001E1:
    ans = L"ERROR_PNP_QUERY_REMOVE_RELATED_DEVICE_TIMEOUT";
    break;
  case 0x000001E2:
    ans = L"ERROR_PNP_QUERY_REMOVE_UNRELATED_DEVICE_TIMEOUT";
    break;
  case 0x000001E3:
    ans = L"ERROR_DEVICE_HARDWARE_ERROR";
    break;
  case 0x000001E7:
    ans = L"ERROR_INVALID_ADDRESS";
    break;
  case 0x0000049F:
    ans = L"ERROR_VRF_CFG_ENABLED";
    break;
  case 0x000004A0:
    ans = L"ERROR_PARTITION_TERMINATING";
    break;
  case 0x000001F4:
    ans = L"ERROR_USER_PROFILE_LOAD";
    break;
  case 0x00000216:
    ans = L"ERROR_ARITHMETIC_OVERFLOW";
    break;
  case 0x00000217:
    ans = L"ERROR_PIPE_CONNECTED";
    break;
  case 0x00000218:
    ans = L"ERROR_PIPE_LISTENING";
    break;
  case 0x00000219:
    ans = L"ERROR_VERIFIER_STOP";
    break;
  case 0x0000021A:
    ans = L"ERROR_ABIOS_ERROR";
    break;
  case 0x0000021B:
    ans = L"ERROR_WX86_WARNING";
    break;
  case 0x0000021C:
    ans = L"ERROR_WX86_ERROR";
    break;
  case 0x0000021D:
    ans = L"ERROR_TIMER_NOT_CANCELED";
    break;
  case 0x0000021E:
    ans = L"ERROR_UNWIND";
    break;
  case 0x0000021F:
    ans = L"ERROR_BAD_STACK";
    break;
  case 0x00000220:
    ans = L"ERROR_INVALID_UNWIND_TARGET";
    break;
  case 0x00000221:
    ans = L"ERROR_INVALID_PORT_ATTRIBUTES";
    break;
  case 0x00000222:
    ans = L"ERROR_PORT_MESSAGE_TOO_LONG";
    break;
  case 0x00000223:
    ans = L"ERROR_INVALID_QUOTA_LOWER";
    break;
  case 0x00000224:
    ans = L"ERROR_DEVICE_ALREADY_ATTACHED";
    break;
  case 0x00000225:
    ans = L"ERROR_INSTRUCTION_MISALIGNMENT";
    break;
  case 0x00000226:
    ans = L"ERROR_PROFILING_NOT_STARTED";
    break;
  case 0x00000227:
    ans = L"ERROR_PROFILING_NOT_STOPPED";
    break;
  case 0x00000228:
    ans = L"ERROR_COULD_NOT_INTERPRET";
    break;
  case 0x00000229:
    ans = L"ERROR_PROFILING_AT_LIMIT";
    break;
  case 0x0000022A:
    ans = L"ERROR_CANT_WAIT";
    break;
  case 0x0000022B:
    ans = L"ERROR_CANT_TERMINATE_SELF";
    break;
  case 0x0000022C:
    ans = L"ERROR_UNEXPECTED_MM_CREATE_ERR";
    break;
  case 0x0000022D:
    ans = L"ERROR_UNEXPECTED_MM_MAP_ERROR";
    break;
  case 0x0000022E:
    ans = L"ERROR_UNEXPECTED_MM_EXTEND_ERR";
    break;
  case 0x0000022F:
    ans = L"ERROR_BAD_FUNCTION_TABLE";
    break;
  case 0x00000230:
    ans = L"ERROR_NO_GUID_TRANSLATION";
    break;
  case 0x00000231:
    ans = L"ERROR_INVALID_LDT_SIZE";
    break;
  case 0x00000233:
    ans = L"ERROR_INVALID_LDT_OFFSET";
    break;
  case 0x00000234:
    ans = L"ERROR_INVALID_LDT_DESCRIPTOR";
    break;
  case 0x00000235:
    ans = L"ERROR_TOO_MANY_THREADS";
    break;
  case 0x00000236:
    ans = L"ERROR_THREAD_NOT_IN_PROCESS";
    break;
  case 0x00000237:
    ans = L"ERROR_PAGEFILE_QUOTA_EXCEEDED";
    break;
  case 0x00000238:
    ans = L"ERROR_LOGON_SERVER_CONFLICT";
    break;
  case 0x00000239:
    ans = L"ERROR_SYNCHRONIZATION_REQUIRED";
    break;
  case 0x0000023A:
    ans = L"ERROR_NET_OPEN_FAILED";
    break;
  case 0x0000023B:
    ans = L"ERROR_IO_PRIVILEGE_FAILED";
    break;
  case 0x0000023D:
    ans = L"ERROR_MISSING_SYSTEMFILE";
    break;
  case 0x0000023E:
    ans = L"ERROR_UNHANDLED_EXCEPTION";
    break;
  case 0x0000023F:
    ans = L"ERROR_APP_INIT_FAILURE";
    break;
  case 0x00000240:
    ans = L"ERROR_PAGEFILE_CREATE_FAILED";
    break;
  case 0x00000241:
    ans = L"ERROR_INVALID_IMAGE_HASH";
    break;
  case 0x00000242:
    ans = L"ERROR_NO_PAGEFILE";
    break;
  case 0x00000243:
    ans = L"ERROR_ILLEGAL_FLOAT_CONTEXT";
    break;
  case 0x00000244:
    ans = L"ERROR_NO_EVENT_PAIR";
    break;
  case 0x00000245:
    ans = L"ERROR_DOMAIN_CTRLR_CONFIG_ERROR";
    break;
  case 0x00000246:
    ans = L"ERROR_ILLEGAL_CHARACTER";
    break;
  case 0x00000247:
    ans = L"ERROR_UNDEFINED_CHARACTER";
    break;
  case 0x00000248:
    ans = L"ERROR_FLOPPY_VOLUME";
    break;
  case 0x00000249:
    ans = L"ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT";
    break;
  case 0x0000024A:
    ans = L"ERROR_BACKUP_CONTROLLER";
    break;
  case 0x0000024B:
    ans = L"ERROR_MUTANT_LIMIT_EXCEEDED";
    break;
  case 0x0000024C:
    ans = L"ERROR_FS_DRIVER_REQUIRED";
    break;
  case 0x0000024D:
    ans = L"ERROR_CANNOT_LOAD_REGISTRY_FILE";
    break;
  case 0x0000024E:
    ans = L"ERROR_DEBUG_ATTACH_FAILED";
    break;
  case 0x0000024F:
    ans = L"ERROR_SYSTEM_PROCESS_TERMINATED";
    break;
  case 0x00000250:
    ans = L"ERROR_DATA_NOT_ACCEPTED";
    break;
  case 0x00000251:
    ans = L"ERROR_VDM_HARD_ERROR";
    break;
  case 0x00000252:
    ans = L"ERROR_DRIVER_CANCEL_TIMEOUT";
    break;
  case 0x00000253:
    ans = L"ERROR_REPLY_MESSAGE_MISMATCH";
    break;
  case 0x00000254:
    ans = L"ERROR_LOST_WRITEBEHIND_DATA";
    break;
  case 0x00000255:
    ans = L"ERROR_CLIENT_SERVER_PARAMETERS_INVALID";
    break;
  case 0x00000256:
    ans = L"ERROR_NOT_TINY_STREAM";
    break;
  case 0x00000257:
    ans = L"ERROR_STACK_OVERFLOW_READ";
    break;
  case 0x00000258:
    ans = L"ERROR_CONVERT_TO_LARGE";
    break;
  case 0x00000259:
    ans = L"ERROR_FOUND_OUT_OF_SCOPE";
    break;
  case 0x0000025A:
    ans = L"ERROR_ALLOCATE_BUCKET";
    break;
  case 0x0000025B:
    ans = L"ERROR_MARSHALL_OVERFLOW";
    break;
  case 0x0000025C:
    ans = L"ERROR_INVALID_VARIANT";
    break;
  case 0x0000025D:
    ans = L"ERROR_BAD_COMPRESSION_BUFFER";
    break;
  case 0x0000025E:
    ans = L"ERROR_AUDIT_FAILED";
    break;
  case 0x0000025F:
    ans = L"ERROR_TIMER_RESOLUTION_NOT_SET";
    break;
  case 0x00000260:
    ans = L"ERROR_INSUFFICIENT_LOGON_INFO";
    break;
  case 0x00000261:
    ans = L"ERROR_BAD_DLL_ENTRYPOINT";
    break;
  case 0x00000262:
    ans = L"ERROR_BAD_SERVICE_ENTRYPOINT";
    break;
  case 0x00000263:
    ans = L"ERROR_IP_ADDRESS_CONFLICT1";
    break;
  case 0x00000264:
    ans = L"ERROR_IP_ADDRESS_CONFLICT2";
    break;
  case 0x00000265:
    ans = L"ERROR_REGISTRY_QUOTA_LIMIT";
    break;
  case 0x00000266:
    ans = L"ERROR_NO_CALLBACK_ACTIVE";
    break;
  case 0x00000267:
    ans = L"ERROR_PWD_TOO_SHORT";
    break;
  case 0x00000268:
    ans = L"ERROR_PWD_TOO_RECENT";
    break;
  case 0x00000269:
    ans = L"ERROR_PWD_HISTORY_CONFLICT";
    break;
  case 0x0000026A:
    ans = L"ERROR_UNSUPPORTED_COMPRESSION";
    break;
  case 0x0000026B:
    ans = L"ERROR_INVALID_HW_PROFILE";
    break;
  case 0x0000026C:
    ans = L"ERROR_INVALID_PLUGPLAY_DEVICE_PATH";
    break;
  case 0x0000026D:
    ans = L"ERROR_QUOTA_LIST_INCONSISTENT";
    break;
  case 0x0000026E:
    ans = L"ERROR_EVALUATION_EXPIRATION";
    break;
  case 0x0000026F:
    ans = L"ERROR_ILLEGAL_DLL_RELOCATION";
    break;
  case 0x00000270:
    ans = L"ERROR_DLL_INIT_FAILED_LOGOFF";
    break;
  case 0x00000271:
    ans = L"ERROR_VALIDATE_CONTINUE";
    break;
  case 0x00000272:
    ans = L"ERROR_NO_MORE_MATCHES";
    break;
  case 0x00000273:
    ans = L"ERROR_RANGE_LIST_CONFLICT";
    break;
  case 0x00000274:
    ans = L"ERROR_SERVER_SID_MISMATCH";
    break;
  case 0x00000275:
    ans = L"ERROR_CANT_ENABLE_DENY_ONLY";
    break;
  case 0x00000278:
    ans = L"ERROR_NOINTERFACE";
    break;
  case 0x00000279:
    ans = L"ERROR_DRIVER_FAILED_SLEEP";
    break;
  case 0x0000027A:
    ans = L"ERROR_CORRUPT_SYSTEM_FILE";
    break;
  case 0x0000027B:
    ans = L"ERROR_COMMITMENT_MINIMUM";
    break;
  case 0x0000027C:
    ans = L"ERROR_PNP_RESTART_ENUMERATION";
    break;
  case 0x0000027D:
    ans = L"ERROR_SYSTEM_IMAGE_BAD_SIGNATURE";
    break;
  case 0x0000027E:
    ans = L"ERROR_PNP_REBOOT_REQUIRED";
    break;
  case 0x0000027F:
    ans = L"ERROR_INSUFFICIENT_POWER";
    break;
  case 0x00000280:
    ans = L"ERROR_MULTIPLE_FAULT_VIOLATION";
    break;
  case 0x00000281:
    ans = L"ERROR_SYSTEM_SHUTDOWN";
    break;
  case 0x00000282:
    ans = L"ERROR_PORT_NOT_SET";
    break;
  case 0x00000283:
    ans = L"ERROR_DS_VERSION_CHECK_FAILURE";
    break;
  case 0x00000284:
    ans = L"ERROR_RANGE_NOT_FOUND";
    break;
  case 0x00000286:
    ans = L"ERROR_NOT_SAFE_MODE_DRIVER";
    break;
  case 0x00000287:
    ans = L"ERROR_FAILED_DRIVER_ENTRY";
    break;
  case 0x00000288:
    ans = L"ERROR_DEVICE_ENUMERATION_ERROR";
    break;
  case 0x00000289:
    ans = L"ERROR_MOUNT_POINT_NOT_RESOLVED";
    break;
  case 0x0000028A:
    ans = L"ERROR_INVALID_DEVICE_OBJECT_PARAMETER";
    break;
  case 0x0000028B:
    ans = L"ERROR_MCA_OCCURED";
    break;
  case 0x0000028C:
    ans = L"ERROR_DRIVER_DATABASE_ERROR";
    break;
  case 0x0000028D:
    ans = L"ERROR_SYSTEM_HIVE_TOO_LARGE";
    break;
  case 0x0000028E:
    ans = L"ERROR_DRIVER_FAILED_PRIOR_UNLOAD";
    break;
  case 0x0000028F:
    ans = L"ERROR_VOLSNAP_PREPARE_HIBERNATE";
    break;
  case 0x00000290:
    ans = L"ERROR_HIBERNATION_FAILURE";
    break;
  case 0x00000291:
    ans = L"ERROR_PWD_TOO_LONG";
    break;
  case 0x00000299:
    ans = L"ERROR_FILE_SYSTEM_LIMITATION";
    break;
  case 0x0000029C:
    ans = L"ERROR_ASSERTION_FAILURE";
    break;
  case 0x0000029D:
    ans = L"ERROR_ACPI_ERROR";
    break;
  case 0x0000029E:
    ans = L"ERROR_WOW_ASSERTION";
    break;
  case 0x0000029F:
    ans = L"ERROR_PNP_BAD_MPS_TABLE";
    break;
  case 0x000002A0:
    ans = L"ERROR_PNP_TRANSLATION_FAILED";
    break;
  case 0x000002A1:
    ans = L"ERROR_PNP_IRQ_TRANSLATION_FAILED";
    break;
  case 0x000002A2:
    ans = L"ERROR_PNP_INVALID_ID";
    break;
  case 0x000002A3:
    ans = L"ERROR_WAKE_SYSTEM_DEBUGGER";
    break;
  case 0x000002A4:
    ans = L"ERROR_HANDLES_CLOSED";
    break;
  case 0x000002A5:
    ans = L"ERROR_EXTRANEOUS_INFORMATION";
    break;
  case 0x000002A6:
    ans = L"ERROR_RXACT_COMMIT_NECESSARY";
    break;
  case 0x000002A7:
    ans = L"ERROR_MEDIA_CHECK";
    break;
  case 0x000002A8:
    ans = L"ERROR_GUID_SUBSTITUTION_MADE";
    break;
  case 0x000002A9:
    ans = L"ERROR_STOPPED_ON_SYMLINK";
    break;
  case 0x000002AA:
    ans = L"ERROR_LONGJUMP";
    break;
  case 0x000002AB:
    ans = L"ERROR_PLUGPLAY_QUERY_VETOED";
    break;
  case 0x000002AC:
    ans = L"ERROR_UNWIND_CONSOLIDATE";
    break;
  case 0x000002AD:
    ans = L"ERROR_REGISTRY_HIVE_RECOVERED";
    break;
  case 0x000002AE:
    ans = L"ERROR_DLL_MIGHT_BE_INSECURE";
    break;
  case 0x000002AF:
    ans = L"ERROR_DLL_MIGHT_BE_INCOMPATIBLE";
    break;
  case 0x000002B1:
    ans = L"ERROR_DBG_REPLY_LATER";
    break;
  case 0x000002B2:
    ans = L"ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE";
    break;
  case 0x000002B6:
    ans = L"ERROR_DBG_PRINTEXCEPTION_C";
    break;
  case 0x000002B7:
    ans = L"ERROR_DBG_RIPEXCEPTION";
    break;
  case 0x000002BA:
    ans = L"ERROR_OBJECT_NAME_EXISTS";
    break;
  case 0x000002BB:
    ans = L"ERROR_THREAD_WAS_SUSPENDED";
    break;
  case 0x000002BC:
    ans = L"ERROR_IMAGE_NOT_AT_BASE";
    break;
  case 0x000002BD:
    ans = L"ERROR_RXACT_STATE_CREATED";
    break;
  case 0x000002BF:
    ans = L"ERROR_BAD_CURRENT_DIRECTORY";
    break;
  case 0x000002C0:
    ans = L"ERROR_FT_READ_RECOVERY_FROM_BACKUP";
    break;
  case 0x000002C1:
    ans = L"ERROR_FT_WRITE_RECOVERY";
    break;
  case 0x000002C2:
    ans = L"ERROR_IMAGE_MACHINE_TYPE_MISMATCH";
    break;
  case 0x000002C3:
    ans = L"ERROR_RECEIVE_PARTIAL";
    break;
  case 0x000002C4:
    ans = L"ERROR_RECEIVE_EXPEDITED";
    break;
  case 0x000002C5:
    ans = L"ERROR_RECEIVE_PARTIAL_EXPEDITED";
    break;
  case 0x000002C6:
    ans = L"ERROR_EVENT_DONE";
    break;
  case 0x000002C7:
    ans = L"ERROR_EVENT_PENDING";
    break;
  case 0x000002C8:
    ans = L"ERROR_CHECKING_FILE_SYSTEM";
    break;
  case 0x000002C9:
    ans = L"ERROR_FATAL_APP_EXIT";
    break;
  case 0x000002CA:
    ans = L"ERROR_PREDEFINED_HANDLE";
    break;
  case 0x000002CB:
    ans = L"ERROR_WAS_UNLOCKED";
    break;
  case 0x000002CC:
    ans = L"ERROR_SERVICE_NOTIFICATION";
    break;
  case 0x000002CD:
    ans = L"ERROR_WAS_LOCKED";
    break;
  case 0x000002CE:
    ans = L"ERROR_LOG_HARD_ERROR";
    break;
  case 0x000002CF:
    ans = L"ERROR_ALREADY_WIN32";
    break;
  case 0x000002D0:
    ans = L"ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE";
    break;
  case 0x000002D1:
    ans = L"ERROR_NO_YIELD_PERFORMED";
    break;
  case 0x000002D2:
    ans = L"ERROR_TIMER_RESUME_IGNORED";
    break;
  case 0x000002D3:
    ans = L"ERROR_ARBITRATION_UNHANDLED";
    break;
  case 0x000002D4:
    ans = L"ERROR_CARDBUS_NOT_SUPPORTED";
    break;
  case 0x000002D5:
    ans = L"ERROR_MP_PROCESSOR_MISMATCH";
    break;
  case 0x000002D6:
    ans = L"ERROR_HIBERNATED";
    break;
  case 0x000002D7:
    ans = L"ERROR_RESUME_HIBERNATION";
    break;
  case 0x000002D8:
    ans = L"ERROR_FIRMWARE_UPDATED";
    break;
  case 0x000002D9:
    ans = L"ERROR_DRIVERS_LEAKING_LOCKED_PAGES";
    break;
  case 0x000002DA:
    ans = L"ERROR_WAKE_SYSTEM";
    break;
  case 0x000002DB:
    ans = L"ERROR_WAIT_1";
    break;
  case 0x000002DC:
    ans = L"ERROR_WAIT_2";
    break;
  case 0x000002DD:
    ans = L"ERROR_WAIT_3";
    break;
  case 0x000002DE:
    ans = L"ERROR_WAIT_63";
    break;
  case 0x000002E0:
    ans = L"ERROR_ABANDONED_WAIT_63";
    break;
  case 0x000002E2:
    ans = L"ERROR_KERNEL_APC";
    break;
  case 0x000002E3:
    ans = L"ERROR_ALERTED";
    break;
  case 0x000002E4:
    ans = L"ERROR_ELEVATION_REQUIRED";
    break;
  case 0x000002E5:
    ans = L"ERROR_REPARSE";
    break;
  case 0x000002E6:
    ans = L"ERROR_OPLOCK_BREAK_IN_PROGRESS";
    break;
  case 0x000002E7:
    ans = L"ERROR_VOLUME_MOUNTED";
    break;
  case 0x000002E8:
    ans = L"ERROR_RXACT_COMMITTED";
    break;
  case 0x000002E9:
    ans = L"ERROR_NOTIFY_CLEANUP";
    break;
  case 0x000002EA:
    ans = L"ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED";
    break;
  case 0x000002EB:
    ans = L"ERROR_PAGE_FAULT_TRANSITION";
    break;
  case 0x000002EC:
    ans = L"ERROR_PAGE_FAULT_DEMAND_ZERO";
    break;
  case 0x000002ED:
    ans = L"ERROR_PAGE_FAULT_COPY_ON_WRITE";
    break;
  case 0x000002EE:
    ans = L"ERROR_PAGE_FAULT_GUARD_PAGE";
    break;
  case 0x000002EF:
    ans = L"ERROR_PAGE_FAULT_PAGING_FILE";
    break;
  case 0x000002F0:
    ans = L"ERROR_CACHE_PAGE_LOCKED";
    break;
  case 0x000002F1:
    ans = L"ERROR_CRASH_DUMP";
    break;
  case 0x000002F2:
    ans = L"ERROR_BUFFER_ALL_ZEROS";
    break;
  case 0x000002F3:
    ans = L"ERROR_REPARSE_OBJECT";
    break;
  case 0x000002F4:
    ans = L"ERROR_RESOURCE_REQUIREMENTS_CHANGED";
    break;
  case 0x000002F5:
    ans = L"ERROR_TRANSLATION_COMPLETE";
    break;
  case 0x000002F6:
    ans = L"ERROR_NOTHING_TO_TERMINATE";
    break;
  case 0x000002F7:
    ans = L"ERROR_PROCESS_NOT_IN_JOB";
    break;
  case 0x000002F8:
    ans = L"ERROR_PROCESS_IN_JOB";
    break;
  case 0x000002F9:
    ans = L"ERROR_VOLSNAP_HIBERNATE_READY";
    break;
  case 0x000002FA:
    ans = L"ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY";
    break;
  case 0x000002FB:
    ans = L"ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED";
    break;
  case 0x000002FC:
    ans = L"ERROR_INTERRUPT_STILL_CONNECTED";
    break;
  case 0x000002FD:
    ans = L"ERROR_WAIT_FOR_OPLOCK";
    break;
  case 0x00000300:
    ans = L"ERROR_CALLBACK_POP_STACK";
    break;
  case 0x00000301:
    ans = L"ERROR_COMPRESSION_DISABLED";
    break;
  case 0x00000302:
    ans = L"ERROR_CANTFETCHBACKWARDS";
    break;
  case 0x00000303:
    ans = L"ERROR_CANTSCROLLBACKWARDS";
    break;
  case 0x00000304:
    ans = L"ERROR_ROWSNOTRELEASED";
    break;
  case 0x00000305:
    ans = L"ERROR_BAD_ACCESSOR_FLAGS";
    break;
  case 0x00000306:
    ans = L"ERROR_ERRORS_ENCOUNTERED";
    break;
  case 0x00000307:
    ans = L"ERROR_NOT_CAPABLE";
    break;
  case 0x00000308:
    ans = L"ERROR_REQUEST_OUT_OF_SEQUENCE";
    break;
  case 0x00000309:
    ans = L"ERROR_VERSION_PARSE_ERROR";
    break;
  case 0x0000030A:
    ans = L"ERROR_BADSTARTPOSITION";
    break;
  case 0x0000030B:
    ans = L"ERROR_MEMORY_HARDWARE";
    break;
  case 0x0000030C:
    ans = L"ERROR_DISK_REPAIR_DISABLED";
    break;
  case 0x0000030D:
    ans = L"ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE";
    break;
  case 0x0000030E:
    ans = L"ERROR_SYSTEM_POWERSTATE_TRANSITION";
    break;
  case 0x0000030F:
    ans = L"ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION";
    break;
  case 0x00000310:
    ans = L"ERROR_MCA_EXCEPTION";
    break;
  case 0x00000311:
    ans = L"ERROR_ACCESS_AUDIT_BY_POLICY";
    break;
  case 0x00000312:
    ans = L"ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY";
    break;
  case 0x00000313:
    ans = L"ERROR_ABANDON_HIBERFILE";
    break;
  case 0x00000314:
    ans = L"ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED";
    break;
  case 0x00000315:
    ans = L"ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR";
    break;
  case 0x00000316:
    ans = L"ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR";
    break;
  case 0x00000317:
    ans = L"ERROR_BAD_MCFG_TABLE";
    break;
  case 0x00000318:
    ans = L"ERROR_DISK_REPAIR_REDIRECTED";
    break;
  case 0x00000319:
    ans = L"ERROR_DISK_REPAIR_UNSUCCESSFUL";
    break;
  case 0x0000031A:
    ans = L"ERROR_CORRUPT_LOG_OVERFULL";
    break;
  case 0x0000031B:
    ans = L"ERROR_CORRUPT_LOG_CORRUPTED";
    break;
  case 0x0000031C:
    ans = L"ERROR_CORRUPT_LOG_UNAVAILABLE";
    break;
  case 0x0000031D:
    ans = L"ERROR_CORRUPT_LOG_DELETED_FULL";
    break;
  case 0x0000031E:
    ans = L"ERROR_CORRUPT_LOG_CLEARED";
    break;
  case 0x0000031F:
    ans = L"ERROR_ORPHAN_NAME_EXHAUSTED";
    break;
  case 0x00000320:
    ans = L"ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE";
    break;
  case 0x00000321:
    ans = L"ERROR_CANNOT_GRANT_REQUESTED_OPLOCK";
    break;
  case 0x00000322:
    ans = L"ERROR_CANNOT_BREAK_OPLOCK";
    break;
  case 0x00000323:
    ans = L"ERROR_OPLOCK_HANDLE_CLOSED";
    break;
  case 0x00000324:
    ans = L"ERROR_NO_ACE_CONDITION";
    break;
  case 0x00000325:
    ans = L"ERROR_INVALID_ACE_CONDITION";
    break;
  case 0x00000326:
    ans = L"ERROR_FILE_HANDLE_REVOKED";
    break;
  case 0x00000327:
    ans = L"ERROR_IMAGE_AT_DIFFERENT_BASE";
    break;
  case 0x00000328:
    ans = L"ERROR_ENCRYPTED_IO_NOT_POSSIBLE";
    break;
  case 0x00000329:
    ans = L"ERROR_FILE_METADATA_OPTIMIZATION_IN_PROGRESS";
    break;
  case 0x0000032A:
    ans = L"ERROR_QUOTA_ACTIVITY";
    break;
  case 0x0000032B:
    ans = L"ERROR_HANDLE_REVOKED";
    break;
  case 0x0000032C:
    ans = L"ERROR_CALLBACK_INVOKE_INLINE";
    break;
  case 0x0000032D:
    ans = L"ERROR_CPU_SET_INVALID";
    break;
  case 0x0000032E:
    ans = L"ERROR_ENCLAVE_NOT_TERMINATED";
    break;
  case 0x0000032F:
    ans = L"ERROR_ENCLAVE_VIOLATION";
    break;
  case 0x000003E2:
    ans = L"ERROR_EA_ACCESS_DENIED";
    break;
  case 0x000003E3:
    ans = L"ERROR_OPERATION_ABORTED";
    break;
  case 0x000003E4:
    ans = L"ERROR_IO_INCOMPLETE";
    break;
  case 0x000003E6:
    ans = L"ERROR_NOACCESS";
    break;
  case 0x000003E7:
    ans = L"ERROR_SWAPERROR";
    break;
  case 0x000003E9:
    ans = L"ERROR_STACK_OVERFLOW";
    break;
  case 0x000003EA:
    ans = L"ERROR_INVALID_MESSAGE";
    break;
  case 0x000003EB:
    ans = L"ERROR_CAN_NOT_COMPLETE";
    break;
  case 0x000003EC:
    ans = L"ERROR_INVALID_FLAGS";
    break;
  case 0x000003ED:
    ans = L"ERROR_UNRECOGNIZED_VOLUME";
    break;
  case 0x000003EE:
    ans = L"ERROR_FILE_INVALID";
    break;
  case 0x000003EF:
    ans = L"ERROR_FULLSCREEN_MODE";
    break;
  case 0x000003F0:
    ans = L"ERROR_NO_TOKEN";
    break;
  case 0x000003F1:
    ans = L"ERROR_BADDB";
    break;
  case 0x000003F2:
    ans = L"ERROR_BADKEY";
    break;
  case 0x000003F3:
    ans = L"ERROR_CANTOPEN";
    break;
  case 0x000003F4:
    ans = L"ERROR_CANTREAD";
    break;
  case 0x000003F5:
    ans = L"ERROR_CANTWRITE";
    break;
  case 0x000003F6:
    ans = L"ERROR_REGISTRY_RECOVERED";
    break;
  case 0x000003F7:
    ans = L"ERROR_REGISTRY_CORRUPT";
    break;
  case 0x000003F8:
    ans = L"ERROR_REGISTRY_IO_FAILED";
    break;
  case 0x000003F9:
    ans = L"ERROR_NOT_REGISTRY_FILE";
    break;
  case 0x000003FA:
    ans = L"ERROR_KEY_DELETED";
    break;
  case 0x000003FB:
    ans = L"ERROR_NO_LOG_SPACE";
    break;
  case 0x000003FC:
    ans = L"ERROR_KEY_HAS_CHILDREN";
    break;
  case 0x000003FD:
    ans = L"ERROR_CHILD_MUST_BE_VOLATILE";
    break;
  case 0x000003FE:
    ans = L"ERROR_NOTIFY_ENUM_DIR";
    break;
  case 0x0000041B:
    ans = L"ERROR_DEPENDENT_SERVICES_RUNNING";
    break;
  case 0x0000041C:
    ans = L"ERROR_INVALID_SERVICE_CONTROL";
    break;
  case 0x0000041D:
    ans = L"ERROR_SERVICE_REQUEST_TIMEOUT";
    break;
  case 0x0000041E:
    ans = L"ERROR_SERVICE_NO_THREAD";
    break;
  case 0x0000041F:
    ans = L"ERROR_SERVICE_DATABASE_LOCKED";
    break;
  case 0x00000420:
    ans = L"ERROR_SERVICE_ALREADY_RUNNING";
    break;
  case 0x00000421:
    ans = L"ERROR_INVALID_SERVICE_ACCOUNT";
    break;
  case 0x00000422:
    ans = L"ERROR_SERVICE_DISABLED";
    break;
  case 0x00000423:
    ans = L"ERROR_CIRCULAR_DEPENDENCY";
    break;
  case 0x00000424:
    ans = L"ERROR_SERVICE_DOES_NOT_EXIST";
    break;
  case 0x00000425:
    ans = L"ERROR_SERVICE_CANNOT_ACCEPT_CTRL";
    break;
  case 0x00000426:
    ans = L"ERROR_SERVICE_NOT_ACTIVE";
    break;
  case 0x00000427:
    ans = L"ERROR_FAILED_SERVICE_CONTROLLER_CONNECT";
    break;
  case 0x00000428:
    ans = L"ERROR_EXCEPTION_IN_SERVICE";
    break;
  case 0x00000429:
    ans = L"ERROR_DATABASE_DOES_NOT_EXIST";
    break;
  case 0x0000042A:
    ans = L"ERROR_SERVICE_SPECIFIC_ERROR";
    break;
  case 0x0000042B:
    ans = L"ERROR_PROCESS_ABORTED";
    break;
  case 0x0000042C:
    ans = L"ERROR_SERVICE_DEPENDENCY_FAIL";
    break;
  case 0x0000042D:
    ans = L"ERROR_SERVICE_LOGON_FAILED";
    break;
  case 0x0000042E:
    ans = L"ERROR_SERVICE_START_HANG";
    break;
  case 0x0000042F:
    ans = L"ERROR_INVALID_SERVICE_LOCK";
    break;
  case 0x00000430:
    ans = L"ERROR_SERVICE_MARKED_FOR_DELETE";
    break;
  case 0x00000431:
    ans = L"ERROR_SERVICE_EXISTS";
    break;
  case 0x00000432:
    ans = L"ERROR_ALREADY_RUNNING_LKG";
    break;
  case 0x00000433:
    ans = L"ERROR_SERVICE_DEPENDENCY_DELETED";
    break;
  case 0x00000434:
    ans = L"ERROR_BOOT_ALREADY_ACCEPTED";
    break;
  case 0x00000435:
    ans = L"ERROR_SERVICE_NEVER_STARTED";
    break;
  case 0x00000436:
    ans = L"ERROR_DUPLICATE_SERVICE_NAME";
    break;
  case 0x00000437:
    ans = L"ERROR_DIFFERENT_SERVICE_ACCOUNT";
    break;
  case 0x00000438:
    ans = L"ERROR_CANNOT_DETECT_DRIVER_FAILURE";
    break;
  case 0x00000439:
    ans = L"ERROR_CANNOT_DETECT_PROCESS_ABORT";
    break;
  case 0x0000043A:
    ans = L"ERROR_NO_RECOVERY_PROGRAM";
    break;
  case 0x0000043B:
    ans = L"ERROR_SERVICE_NOT_IN_EXE";
    break;
  case 0x0000043C:
    ans = L"ERROR_NOT_SAFEBOOT_SERVICE";
    break;
  case 0x0000044C:
    ans = L"ERROR_END_OF_MEDIA";
    break;
  case 0x0000044D:
    ans = L"ERROR_FILEMARK_DETECTED";
    break;
  case 0x0000044E:
    ans = L"ERROR_BEGINNING_OF_MEDIA";
    break;
  case 0x0000044F:
    ans = L"ERROR_SETMARK_DETECTED";
    break;
  case 0x00000450:
    ans = L"ERROR_NO_DATA_DETECTED";
    break;
  case 0x00000451:
    ans = L"ERROR_PARTITION_FAILURE";
    break;
  case 0x00000452:
    ans = L"ERROR_INVALID_BLOCK_LENGTH";
    break;
  case 0x00000453:
    ans = L"ERROR_DEVICE_NOT_PARTITIONED";
    break;
  case 0x00000454:
    ans = L"ERROR_UNABLE_TO_LOCK_MEDIA";
    break;
  case 0x00000455:
    ans = L"ERROR_UNABLE_TO_UNLOAD_MEDIA";
    break;
  case 0x00000456:
    ans = L"ERROR_MEDIA_CHANGED";
    break;
  case 0x00000457:
    ans = L"ERROR_BUS_RESET";
    break;
  case 0x00000458:
    ans = L"ERROR_NO_MEDIA_IN_DRIVE";
    break;
  case 0x00000459:
    ans = L"ERROR_NO_UNICODE_TRANSLATION";
    break;
  case 0x0000045A:
    ans = L"ERROR_DLL_INIT_FAILED";
    break;
  case 0x0000045B:
    ans = L"ERROR_SHUTDOWN_IN_PROGRESS";
    break;
  case 0x0000045C:
    ans = L"ERROR_NO_SHUTDOWN_IN_PROGRESS";
    break;
  case 0x0000045D:
    ans = L"ERROR_IO_DEVICE";
    break;
  case 0x0000045E:
    ans = L"ERROR_SERIAL_NO_DEVICE";
    break;
  case 0x0000045F:
    ans = L"ERROR_IRQ_BUSY";
    break;
  case 0x00000460:
    ans = L"ERROR_MORE_WRITES";
    break;
  case 0x00000461:
    ans = L"ERROR_COUNTER_TIMEOUT";
    break;
  case 0x00000462:
    ans = L"ERROR_FLOPPY_ID_MARK_NOT_FOUND";
    break;
  case 0x00000463:
    ans = L"ERROR_FLOPPY_WRONG_CYLINDER";
    break;
  case 0x00000464:
    ans = L"ERROR_FLOPPY_UNKNOWN_ERROR";
    break;
  case 0x00000465:
    ans = L"ERROR_FLOPPY_BAD_REGISTERS";
    break;
  case 0x00000466:
    ans = L"ERROR_DISK_RECALIBRATE_FAILED";
    break;
  case 0x00000467:
    ans = L"ERROR_DISK_OPERATION_FAILED";
    break;
  case 0x00000468:
    ans = L"ERROR_DISK_RESET_FAILED";
    break;
  case 0x00000469:
    ans = L"ERROR_EOM_OVERFLOW";
    break;
  case 0x0000046A:
    ans = L"ERROR_NOT_ENOUGH_SERVER_MEMORY";
    break;
  case 0x0000046B:
    ans = L"ERROR_POSSIBLE_DEADLOCK";
    break;
  case 0x0000046C:
    ans = L"ERROR_MAPPED_ALIGNMENT";
    break;
  case 0x00000474:
    ans = L"ERROR_SET_POWER_STATE_VETOED";
    break;
  case 0x00000475:
    ans = L"ERROR_SET_POWER_STATE_FAILED";
    break;
  case 0x00000476:
    ans = L"ERROR_TOO_MANY_LINKS";
    break;
  case 0x0000047E:
    ans = L"ERROR_OLD_WIN_VERSION";
    break;
  case 0x0000047F:
    ans = L"ERROR_APP_WRONG_OS";
    break;
  case 0x00000480:
    ans = L"ERROR_SINGLE_INSTANCE_APP";
    break;
  case 0x00000481:
    ans = L"ERROR_RMODE_APP";
    break;
  case 0x00000482:
    ans = L"ERROR_INVALID_DLL";
    break;
  case 0x00000483:
    ans = L"ERROR_NO_ASSOCIATION";
    break;
  case 0x00000484:
    ans = L"ERROR_DDE_FAIL";
    break;
  case 0x00000485:
    ans = L"ERROR_DLL_NOT_FOUND";
    break;
  case 0x00000486:
    ans = L"ERROR_NO_MORE_USER_HANDLES";
    break;
  case 0x00000487:
    ans = L"ERROR_MESSAGE_SYNC_ONLY";
    break;
  case 0x00000488:
    ans = L"ERROR_SOURCE_ELEMENT_EMPTY";
    break;
  case 0x00000489:
    ans = L"ERROR_DESTINATION_ELEMENT_FULL";
    break;
  case 0x0000048A:
    ans = L"ERROR_ILLEGAL_ELEMENT_ADDRESS";
    break;
  case 0x0000048B:
    ans = L"ERROR_MAGAZINE_NOT_PRESENT";
    break;
  case 0x0000048D:
    ans = L"ERROR_DEVICE_REQUIRES_CLEANING";
    break;
  case 0x0000048E:
    ans = L"ERROR_DEVICE_DOOR_OPEN";
    break;
  case 0x0000048F:
    ans = L"ERROR_DEVICE_NOT_CONNECTED";
    break;
  case 0x00000490:
    ans = L"ERROR_NOT_FOUND";
    break;
  case 0x00000491:
    ans = L"ERROR_NO_MATCH";
    break;
  case 0x00000492:
    ans = L"ERROR_SET_NOT_FOUND";
    break;
  case 0x00000493:
    ans = L"ERROR_POINT_NOT_FOUND";
    break;
  case 0x00000494:
    ans = L"ERROR_NO_TRACKING_SERVICE";
    break;
  case 0x00000495:
    ans = L"ERROR_NO_VOLUME_ID";
    break;
  case 0x00000497:
    ans = L"ERROR_UNABLE_TO_REMOVE_REPLACED";
    break;
  case 0x00000498:
    ans = L"ERROR_UNABLE_TO_MOVE_REPLACEMENT";
    break;
  case 0x00000499:
    ans = L"ERROR_UNABLE_TO_MOVE_REPLACEMENT_2";
    break;
  case 0x0000049A:
    ans = L"ERROR_JOURNAL_DELETE_IN_PROGRESS";
    break;
  case 0x0000049B:
    ans = L"ERROR_JOURNAL_NOT_ACTIVE";
    break;
  case 0x0000049C:
    ans = L"ERROR_POTENTIAL_FILE_FOUND";
    break;
  case 0x0000049D:
    ans = L"ERROR_JOURNAL_ENTRY_DELETED";
    break;
  case 0x000004A6:
    ans = L"ERROR_SHUTDOWN_IS_SCHEDULED";
    break;
  case 0x000004A7:
    ans = L"ERROR_SHUTDOWN_USERS_LOGGED_ON";
    break;
  case 0x000004B0:
    ans = L"ERROR_BAD_DEVICE";
    break;
  case 0x000004B1:
    ans = L"ERROR_CONNECTION_UNAVAIL";
    break;
  case 0x000004B2:
    ans = L"ERROR_DEVICE_ALREADY_REMEMBERED";
    break;
  case 0x000004B3:
    ans = L"ERROR_NO_NET_OR_BAD_PATH";
    break;
  case 0x000004B4:
    ans = L"ERROR_BAD_PROVIDER";
    break;
  case 0x000004B5:
    ans = L"ERROR_CANNOT_OPEN_PROFILE";
    break;
  case 0x000004B6:
    ans = L"ERROR_BAD_PROFILE";
    break;
  case 0x000004B7:
    ans = L"ERROR_NOT_CONTAINER";
    break;
  case 0x000004B8:
    ans = L"ERROR_EXTENDED_ERROR";
    break;
  case 0x000004B9:
    ans = L"ERROR_INVALID_GROUPNAME";
    break;
  case 0x000004BA:
    ans = L"ERROR_INVALID_COMPUTERNAME";
    break;
  case 0x000004BB:
    ans = L"ERROR_INVALID_EVENTNAME";
    break;
  case 0x000004BC:
    ans = L"ERROR_INVALID_DOMAINNAME";
    break;
  case 0x000004BD:
    ans = L"ERROR_INVALID_SERVICENAME";
    break;
  case 0x000004BE:
    ans = L"ERROR_INVALID_NETNAME";
    break;
  case 0x000004BF:
    ans = L"ERROR_INVALID_SHARENAME";
    break;
  case 0x000004C0:
    ans = L"ERROR_INVALID_PASSWORDNAME";
    break;
  case 0x000004C1:
    ans = L"ERROR_INVALID_MESSAGENAME";
    break;
  case 0x000004C2:
    ans = L"ERROR_INVALID_MESSAGEDEST";
    break;
  case 0x000004C3:
    ans = L"ERROR_SESSION_CREDENTIAL_CONFLICT";
    break;
  case 0x000004C4:
    ans = L"ERROR_REMOTE_SESSION_LIMIT_EXCEEDED";
    break;
  case 0x000004C5:
    ans = L"ERROR_DUP_DOMAINNAME";
    break;
  case 0x000004C6:
    ans = L"ERROR_NO_NETWORK";
    break;
  case 0x000004C7:
    ans = L"ERROR_CANCELLED";
    break;
  case 0x000004C8:
    ans = L"ERROR_USER_MAPPED_FILE";
    break;
  case 0x000004C9:
    ans = L"ERROR_CONNECTION_REFUSED";
    break;
  case 0x000004CA:
    ans = L"ERROR_GRACEFUL_DISCONNECT";
    break;
  case 0x000004CB:
    ans = L"ERROR_ADDRESS_ALREADY_ASSOCIATED";
    break;
  case 0x000004CC:
    ans = L"ERROR_ADDRESS_NOT_ASSOCIATED";
    break;
  case 0x000004CD:
    ans = L"ERROR_CONNECTION_INVALID";
    break;
  case 0x000004CE:
    ans = L"ERROR_CONNECTION_ACTIVE";
    break;
  case 0x000004CF:
    ans = L"ERROR_NETWORK_UNREACHABLE";
    break;
  case 0x000004D0:
    ans = L"ERROR_HOST_UNREACHABLE";
    break;
  case 0x000004D1:
    ans = L"ERROR_PROTOCOL_UNREACHABLE";
    break;
  case 0x000004D2:
    ans = L"ERROR_PORT_UNREACHABLE";
    break;
  case 0x000004D3:
    ans = L"ERROR_REQUEST_ABORTED";
    break;
  case 0x000004D4:
    ans = L"ERROR_CONNECTION_ABORTED";
    break;
  case 0x000004D5:
    ans = L"ERROR_RETRY";
    break;
  case 0x000004D6:
    ans = L"ERROR_CONNECTION_COUNT_LIMIT";
    break;
  case 0x000004D7:
    ans = L"ERROR_LOGIN_TIME_RESTRICTION";
    break;
  case 0x000004D8:
    ans = L"ERROR_LOGIN_WKSTA_RESTRICTION";
    break;
  case 0x000004D9:
    ans = L"ERROR_INCORRECT_ADDRESS";
    break;
  case 0x000004DA:
    ans = L"ERROR_ALREADY_REGISTERED";
    break;
  case 0x000004DB:
    ans = L"ERROR_SERVICE_NOT_FOUND";
    break;
  case 0x000004DC:
    ans = L"ERROR_NOT_AUTHENTICATED";
    break;
  case 0x000004DD:
    ans = L"ERROR_NOT_LOGGED_ON";
    break;
  case 0x000004DF:
    ans = L"ERROR_ALREADY_INITIALIZED";
    break;
  case 0x000004E1:
    ans = L"ERROR_NO_SUCH_SITE";
    break;
  case 0x000004E2:
    ans = L"ERROR_DOMAIN_CONTROLLER_EXISTS";
    break;
  case 0x000004E3:
    ans = L"ERROR_ONLY_IF_CONNECTED";
    break;
  case 0x000004E4:
    ans = L"ERROR_OVERRIDE_NOCHANGES";
    break;
  case 0x000004E5:
    ans = L"ERROR_BAD_USER_PROFILE";
    break;
  case 0x000004E6:
    ans = L"ERROR_NOT_SUPPORTED_ON_SBS";
    break;
  case 0x000004E7:
    ans = L"ERROR_SERVER_SHUTDOWN_IN_PROGRESS";
    break;
  case 0x000004E8:
    ans = L"ERROR_HOST_DOWN";
    break;
  case 0x000004E9:
    ans = L"ERROR_NON_ACCOUNT_SID";
    break;
  case 0x000004EA:
    ans = L"ERROR_NON_DOMAIN_SID";
    break;
  case 0x000004EB:
    ans = L"ERROR_APPHELP_BLOCK";
    break;
  case 0x000004EC:
    ans = L"ERROR_ACCESS_DISABLED_BY_POLICY";
    break;
  case 0x000004ED:
    ans = L"ERROR_REG_NAT_CONSUMPTION";
    break;
  case 0x000004EE:
    ans = L"ERROR_CSCSHARE_OFFLINE";
    break;
  case 0x000004EF:
    ans = L"ERROR_PKINIT_FAILURE";
    break;
  case 0x000004F0:
    ans = L"ERROR_SMARTCARD_SUBSYSTEM_FAILURE";
    break;
  case 0x000004F1:
    ans = L"ERROR_DOWNGRADE_DETECTED";
    break;
  case 0x000004F7:
    ans = L"ERROR_MACHINE_LOCKED";
    break;
  case 0x000004F8:
    ans = L"ERROR_SMB_GUEST_LOGON_BLOCKED";
    break;
  case 0x000004F9:
    ans = L"ERROR_CALLBACK_SUPPLIED_INVALID_DATA";
    break;
  case 0x000004FA:
    ans = L"ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED";
    break;
  case 0x000004FB:
    ans = L"ERROR_DRIVER_BLOCKED";
    break;
  case 0x000004FC:
    ans = L"ERROR_INVALID_IMPORT_OF_NON_DLL";
    break;
  case 0x000004FD:
    ans = L"ERROR_ACCESS_DISABLED_WEBBLADE";
    break;
  case 0x000004FE:
    ans = L"ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER";
    break;
  case 0x000004FF:
    ans = L"ERROR_RECOVERY_FAILURE";
    break;
  case 0x00000500:
    ans = L"ERROR_ALREADY_FIBER";
    break;
  case 0x00000501:
    ans = L"ERROR_ALREADY_THREAD";
    break;
  case 0x00000502:
    ans = L"ERROR_STACK_BUFFER_OVERRUN";
    break;
  case 0x00000503:
    ans = L"ERROR_PARAMETER_QUOTA_EXCEEDED";
    break;
  case 0x00000504:
    ans = L"ERROR_DEBUGGER_INACTIVE";
    break;
  case 0x00000505:
    ans = L"ERROR_DELAY_LOAD_FAILED";
    break;
  case 0x00000506:
    ans = L"ERROR_VDM_DISALLOWED";
    break;
  case 0x00000507:
    ans = L"ERROR_UNIDENTIFIED_ERROR";
    break;
  case 0x00000508:
    ans = L"ERROR_INVALID_CRUNTIME_PARAMETER";
    break;
  case 0x00000509:
    ans = L"ERROR_BEYOND_VDL";
    break;
  case 0x0000050A:
    ans = L"ERROR_INCOMPATIBLE_SERVICE_SID_TYPE";
    break;
  case 0x0000050B:
    ans = L"ERROR_DRIVER_PROCESS_TERMINATED";
    break;
  case 0x0000050C:
    ans = L"ERROR_IMPLEMENTATION_LIMIT";
    break;
  case 0x0000050D:
    ans = L"ERROR_PROCESS_IS_PROTECTED";
    break;
  case 0x0000050E:
    ans = L"ERROR_SERVICE_NOTIFY_CLIENT_LAGGING";
    break;
  case 0x0000050F:
    ans = L"ERROR_DISK_QUOTA_EXCEEDED";
    break;
  case 0x00000510:
    ans = L"ERROR_CONTENT_BLOCKED";
    break;
  case 0x00000511:
    ans = L"ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE";
    break;
  case 0x00000512:
    ans = L"ERROR_APP_HANG";
    break;
  case 0x00000513:
    ans = L"ERROR_INVALID_LABEL";
    break;
  case 0x00000514:
    ans = L"ERROR_NOT_ALL_ASSIGNED";
    break;
  case 0x00000515:
    ans = L"ERROR_SOME_NOT_MAPPED";
    break;
  case 0x00000516:
    ans = L"ERROR_NO_QUOTAS_FOR_ACCOUNT";
    break;
  case 0x00000517:
    ans = L"ERROR_LOCAL_USER_SESSION_KEY";
    break;
  case 0x00000518:
    ans = L"ERROR_NULL_LM_PASSWORD";
    break;
  case 0x00000519:
    ans = L"ERROR_UNKNOWN_REVISION";
    break;
  case 0x0000051A:
    ans = L"ERROR_REVISION_MISMATCH";
    break;
  case 0x0000051B:
    ans = L"ERROR_INVALID_OWNER";
    break;
  case 0x0000051C:
    ans = L"ERROR_INVALID_PRIMARY_GROUP";
    break;
  case 0x0000051D:
    ans = L"ERROR_NO_IMPERSONATION_TOKEN";
    break;
  case 0x0000051E:
    ans = L"ERROR_CANT_DISABLE_MANDATORY";
    break;
  case 0x0000051F:
    ans = L"ERROR_NO_LOGON_SERVERS";
    break;
  case 0x00000520:
    ans = L"ERROR_NO_SUCH_LOGON_SESSION";
    break;
  case 0x00000521:
    ans = L"ERROR_NO_SUCH_PRIVILEGE";
    break;
  case 0x00000522:
    ans = L"ERROR_PRIVILEGE_NOT_HELD";
    break;
  case 0x00000523:
    ans = L"ERROR_INVALID_ACCOUNT_NAME";
    break;
  case 0x00000524:
    ans = L"ERROR_USER_EXISTS";
    break;
  case 0x00000525:
    ans = L"ERROR_NO_SUCH_USER";
    break;
  case 0x00000526:
    ans = L"ERROR_GROUP_EXISTS";
    break;
  case 0x00000527:
    ans = L"ERROR_NO_SUCH_GROUP";
    break;
  case 0x00000528:
    ans = L"ERROR_MEMBER_IN_GROUP";
    break;
  case 0x00000529:
    ans = L"ERROR_MEMBER_NOT_IN_GROUP";
    break;
  case 0x0000052A:
    ans = L"ERROR_LAST_ADMIN";
    break;
  case 0x0000052B:
    ans = L"ERROR_WRONG_PASSWORD";
    break;
  case 0x0000052C:
    ans = L"ERROR_ILL_FORMED_PASSWORD";
    break;
  case 0x0000052D:
    ans = L"ERROR_PASSWORD_RESTRICTION";
    break;
  case 0x0000052E:
    ans = L"ERROR_LOGON_FAILURE";
    break;
  case 0x0000052F:
    ans = L"ERROR_ACCOUNT_RESTRICTION";
    break;
  case 0x00000530:
    ans = L"ERROR_INVALID_LOGON_HOURS";
    break;
  case 0x00000531:
    ans = L"ERROR_INVALID_WORKSTATION";
    break;
  case 0x00000532:
    ans = L"ERROR_PASSWORD_EXPIRED";
    break;
  case 0x00000533:
    ans = L"ERROR_ACCOUNT_DISABLED";
    break;
  case 0x00000534:
    ans = L"ERROR_NONE_MAPPED";
    break;
  case 0x00000535:
    ans = L"ERROR_TOO_MANY_LUIDS_REQUESTED";
    break;
  case 0x00000536:
    ans = L"ERROR_LUIDS_EXHAUSTED";
    break;
  case 0x00000537:
    ans = L"ERROR_INVALID_SUB_AUTHORITY";
    break;
  case 0x00000538:
    ans = L"ERROR_INVALID_ACL";
    break;
  case 0x00000539:
    ans = L"ERROR_INVALID_SID";
    break;
  case 0x0000053A:
    ans = L"ERROR_INVALID_SECURITY_DESCR";
    break;
  case 0x0000053C:
    ans = L"ERROR_BAD_INHERITANCE_ACL";
    break;
  case 0x0000053D:
    ans = L"ERROR_SERVER_DISABLED";
    break;
  case 0x0000053E:
    ans = L"ERROR_SERVER_NOT_DISABLED";
    break;
  case 0x0000053F:
    ans = L"ERROR_INVALID_ID_AUTHORITY";
    break;
  case 0x00000540:
    ans = L"ERROR_ALLOTTED_SPACE_EXCEEDED";
    break;
  case 0x00000541:
    ans = L"ERROR_INVALID_GROUP_ATTRIBUTES";
    break;
  case 0x00000542:
    ans = L"ERROR_BAD_IMPERSONATION_LEVEL";
    break;
  case 0x00000543:
    ans = L"ERROR_CANT_OPEN_ANONYMOUS";
    break;
  case 0x00000544:
    ans = L"ERROR_BAD_VALIDATION_CLASS";
    break;
  case 0x00000545:
    ans = L"ERROR_BAD_TOKEN_TYPE";
    break;
  case 0x00000546:
    ans = L"ERROR_NO_SECURITY_ON_OBJECT";
    break;
  case 0x00000547:
    ans = L"ERROR_CANT_ACCESS_DOMAIN_INFO";
    break;
  case 0x00000548:
    ans = L"ERROR_INVALID_SERVER_STATE";
    break;
  case 0x00000549:
    ans = L"ERROR_INVALID_DOMAIN_STATE";
    break;
  case 0x0000054A:
    ans = L"ERROR_INVALID_DOMAIN_ROLE";
    break;
  case 0x0000054B:
    ans = L"ERROR_NO_SUCH_DOMAIN";
    break;
  case 0x0000054C:
    ans = L"ERROR_DOMAIN_EXISTS";
    break;
  case 0x0000054D:
    ans = L"ERROR_DOMAIN_LIMIT_EXCEEDED";
    break;
  case 0x0000054E:
    ans = L"ERROR_INTERNAL_DB_CORRUPTION";
    break;
  case 0x0000054F:
    ans = L"ERROR_INTERNAL_ERROR";
    break;
  case 0x00000550:
    ans = L"ERROR_GENERIC_NOT_MAPPED";
    break;
  case 0x00000551:
    ans = L"ERROR_BAD_DESCRIPTOR_FORMAT";
    break;
  case 0x00000552:
    ans = L"ERROR_NOT_LOGON_PROCESS";
    break;
  case 0x00000553:
    ans = L"ERROR_LOGON_SESSION_EXISTS";
    break;
  case 0x00000554:
    ans = L"ERROR_NO_SUCH_PACKAGE";
    break;
  case 0x00000555:
    ans = L"ERROR_BAD_LOGON_SESSION_STATE";
    break;
  case 0x00000556:
    ans = L"ERROR_LOGON_SESSION_COLLISION";
    break;
  case 0x00000557:
    ans = L"ERROR_INVALID_LOGON_TYPE";
    break;
  case 0x00000558:
    ans = L"ERROR_CANNOT_IMPERSONATE";
    break;
  case 0x00000559:
    ans = L"ERROR_RXACT_INVALID_STATE";
    break;
  case 0x0000055A:
    ans = L"ERROR_RXACT_COMMIT_FAILURE";
    break;
  case 0x0000055B:
    ans = L"ERROR_SPECIAL_ACCOUNT";
    break;
  case 0x0000055C:
    ans = L"ERROR_SPECIAL_GROUP";
    break;
  case 0x0000055D:
    ans = L"ERROR_SPECIAL_USER";
    break;
  case 0x0000055E:
    ans = L"ERROR_MEMBERS_PRIMARY_GROUP";
    break;
  case 0x0000055F:
    ans = L"ERROR_TOKEN_ALREADY_IN_USE";
    break;
  case 0x00000560:
    ans = L"ERROR_NO_SUCH_ALIAS";
    break;
  case 0x00000561:
    ans = L"ERROR_MEMBER_NOT_IN_ALIAS";
    break;
  case 0x00000562:
    ans = L"ERROR_MEMBER_IN_ALIAS";
    break;
  case 0x00000563:
    ans = L"ERROR_ALIAS_EXISTS";
    break;
  case 0x00000564:
    ans = L"ERROR_LOGON_NOT_GRANTED";
    break;
  case 0x00000565:
    ans = L"ERROR_TOO_MANY_SECRETS";
    break;
  case 0x00000566:
    ans = L"ERROR_SECRET_TOO_LONG";
    break;
  case 0x00000567:
    ans = L"ERROR_INTERNAL_DB_ERROR";
    break;
  case 0x00000568:
    ans = L"ERROR_TOO_MANY_CONTEXT_IDS";
    break;
  case 0x00000569:
    ans = L"ERROR_LOGON_TYPE_NOT_GRANTED";
    break;
  case 0x0000056A:
    ans = L"ERROR_NT_CROSS_ENCRYPTION_REQUIRED";
    break;
  case 0x0000056B:
    ans = L"ERROR_NO_SUCH_MEMBER";
    break;
  case 0x0000056C:
    ans = L"ERROR_INVALID_MEMBER";
    break;
  case 0x0000056D:
    ans = L"ERROR_TOO_MANY_SIDS";
    break;
  case 0x0000056E:
    ans = L"ERROR_LM_CROSS_ENCRYPTION_REQUIRED";
    break;
  case 0x0000056F:
    ans = L"ERROR_NO_INHERITANCE";
    break;
  case 0x00000570:
    ans = L"ERROR_FILE_CORRUPT";
    break;
  case 0x00000571:
    ans = L"ERROR_DISK_CORRUPT";
    break;
  case 0x00000572:
    ans = L"ERROR_NO_USER_SESSION_KEY";
    break;
  case 0x00000573:
    ans = L"ERROR_LICENSE_QUOTA_EXCEEDED";
    break;
  case 0x00000574:
    ans = L"ERROR_WRONG_TARGET_NAME";
    break;
  case 0x00000575:
    ans = L"ERROR_MUTUAL_AUTH_FAILED";
    break;
  case 0x00000576:
    ans = L"ERROR_TIME_SKEW";
    break;
  case 0x00000577:
    ans = L"ERROR_CURRENT_DOMAIN_NOT_ALLOWED";
    break;
  case 0x00000578:
    ans = L"ERROR_INVALID_WINDOW_HANDLE";
    break;
  case 0x00000579:
    ans = L"ERROR_INVALID_MENU_HANDLE";
    break;
  case 0x0000057A:
    ans = L"ERROR_INVALID_CURSOR_HANDLE";
    break;
  case 0x0000057B:
    ans = L"ERROR_INVALID_ACCEL_HANDLE";
    break;
  case 0x0000057C:
    ans = L"ERROR_INVALID_HOOK_HANDLE";
    break;
  case 0x0000057D:
    ans = L"ERROR_INVALID_DWP_HANDLE";
    break;
  case 0x0000057E:
    ans = L"ERROR_TLW_WITH_WSCHILD";
    break;
  case 0x0000057F:
    ans = L"ERROR_CANNOT_FIND_WND_CLASS";
    break;
  case 0x00000580:
    ans = L"ERROR_WINDOW_OF_OTHER_THREAD";
    break;
  case 0x00000581:
    ans = L"ERROR_HOTKEY_ALREADY_REGISTERED";
    break;
  case 0x00000582:
    ans = L"ERROR_CLASS_ALREADY_EXISTS";
    break;
  case 0x00000583:
    ans = L"ERROR_CLASS_DOES_NOT_EXIST";
    break;
  case 0x00000584:
    ans = L"ERROR_CLASS_HAS_WINDOWS";
    break;
  case 0x00000585:
    ans = L"ERROR_INVALID_INDEX";
    break;
  case 0x00000586:
    ans = L"ERROR_INVALID_ICON_HANDLE";
    break;
  case 0x00000587:
    ans = L"ERROR_PRIVATE_DIALOG_INDEX";
    break;
  case 0x00000588:
    ans = L"ERROR_LISTBOX_ID_NOT_FOUND";
    break;
  case 0x00000589:
    ans = L"ERROR_NO_WILDCARD_CHARACTERS";
    break;
  case 0x0000058A:
    ans = L"ERROR_CLIPBOARD_NOT_OPEN";
    break;
  case 0x0000058B:
    ans = L"ERROR_HOTKEY_NOT_REGISTERED";
    break;
  case 0x0000058C:
    ans = L"ERROR_WINDOW_NOT_DIALOG";
    break;
  case 0x0000058D:
    ans = L"ERROR_CONTROL_ID_NOT_FOUND";
    break;
  case 0x0000058E:
    ans = L"ERROR_INVALID_COMBOBOX_MESSAGE";
    break;
  case 0x0000058F:
    ans = L"ERROR_WINDOW_NOT_COMBOBOX";
    break;
  case 0x00000590:
    ans = L"ERROR_INVALID_EDIT_HEIGHT";
    break;
  case 0x00000591:
    ans = L"ERROR_DC_NOT_FOUND";
    break;
  case 0x00000592:
    ans = L"ERROR_INVALID_HOOK_FILTER";
    break;
  case 0x00000593:
    ans = L"ERROR_INVALID_FILTER_PROC";
    break;
  case 0x00000594:
    ans = L"ERROR_HOOK_NEEDS_HMOD";
    break;
  case 0x00000595:
    ans = L"ERROR_GLOBAL_ONLY_HOOK";
    break;
  case 0x00000596:
    ans = L"ERROR_JOURNAL_HOOK_SET";
    break;
  case 0x00000597:
    ans = L"ERROR_HOOK_NOT_INSTALLED";
    break;
  case 0x00000598:
    ans = L"ERROR_INVALID_LB_MESSAGE";
    break;
  case 0x00000599:
    ans = L"ERROR_SETCOUNT_ON_BAD_LB";
    break;
  case 0x0000059A:
    ans = L"ERROR_LB_WITHOUT_TABSTOPS";
    break;
  case 0x0000059B:
    ans = L"ERROR_DESTROY_OBJECT_OF_OTHER_THREAD";
    break;
  case 0x0000059C:
    ans = L"ERROR_CHILD_WINDOW_MENU";
    break;
  case 0x0000059D:
    ans = L"ERROR_NO_SYSTEM_MENU";
    break;
  case 0x0000059E:
    ans = L"ERROR_INVALID_MSGBOX_STYLE";
    break;
  case 0x0000059F:
    ans = L"ERROR_INVALID_SPI_VALUE";
    break;
  case 0x000005A0:
    ans = L"ERROR_SCREEN_ALREADY_LOCKED";
    break;
  case 0x000005A1:
    ans = L"ERROR_HWNDS_HAVE_DIFF_PARENT";
    break;
  case 0x000005A2:
    ans = L"ERROR_NOT_CHILD_WINDOW";
    break;
  case 0x000005A3:
    ans = L"ERROR_INVALID_GW_COMMAND";
    break;
  case 0x000005A4:
    ans = L"ERROR_INVALID_THREAD_ID";
    break;
  case 0x000005A5:
    ans = L"ERROR_NON_MDICHILD_WINDOW";
    break;
  case 0x000005A6:
    ans = L"ERROR_POPUP_ALREADY_ACTIVE";
    break;
  case 0x000005A7:
    ans = L"ERROR_NO_SCROLLBARS";
    break;
  case 0x000005A8:
    ans = L"ERROR_INVALID_SCROLLBAR_RANGE";
    break;
  case 0x000005A9:
    ans = L"ERROR_INVALID_SHOWWIN_COMMAND";
    break;
  case 0x000005AA:
    ans = L"ERROR_NO_SYSTEM_RESOURCES";
    break;
  case 0x000005AB:
    ans = L"ERROR_NONPAGED_SYSTEM_RESOURCES";
    break;
  case 0x000005AC:
    ans = L"ERROR_PAGED_SYSTEM_RESOURCES";
    break;
  case 0x000005AD:
    ans = L"ERROR_WORKING_SET_QUOTA";
    break;
  case 0x000005AE:
    ans = L"ERROR_PAGEFILE_QUOTA";
    break;
  case 0x000005AF:
    ans = L"ERROR_COMMITMENT_LIMIT";
    break;
  case 0x000005B0:
    ans = L"ERROR_MENU_ITEM_NOT_FOUND";
    break;
  case 0x000005B1:
    ans = L"ERROR_INVALID_KEYBOARD_HANDLE";
    break;
  case 0x000005B2:
    ans = L"ERROR_HOOK_TYPE_NOT_ALLOWED";
    break;
  case 0x000005B3:
    ans = L"ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION";
    break;
  case 0x000005B4:
    ans = L"ERROR_TIMEOUT";
    break;
  case 0x000005B5:
    ans = L"ERROR_INVALID_MONITOR_HANDLE";
    break;
  case 0x000005B6:
    ans = L"ERROR_INCORRECT_SIZE";
    break;
  case 0x000005B7:
    ans = L"ERROR_SYMLINK_CLASS_DISABLED";
    break;
  case 0x000005B8:
    ans = L"ERROR_SYMLINK_NOT_SUPPORTED";
    break;
  case 0x000005B9:
    ans = L"ERROR_XML_PARSE_ERROR";
    break;
  case 0x000005BA:
    ans = L"ERROR_XMLDSIG_ERROR";
    break;
  case 0x000005BB:
    ans = L"ERROR_RESTART_APPLICATION";
    break;
  case 0x000005BC:
    ans = L"ERROR_WRONG_COMPARTMENT";
    break;
  case 0x000005BD:
    ans = L"ERROR_AUTHIP_FAILURE";
    break;
  case 0x000005BE:
    ans = L"ERROR_NO_NVRAM_RESOURCES";
    break;
  case 0x000005BF:
    ans = L"ERROR_NOT_GUI_PROCESS";
    break;
  case 0x000005DC:
    ans = L"ERROR_EVENTLOG_FILE_CORRUPT";
    break;
  case 0x000005DD:
    ans = L"ERROR_EVENTLOG_CANT_START";
    break;
  case 0x000005DE:
    ans = L"ERROR_LOG_FILE_FULL";
    break;
  case 0x000005DF:
    ans = L"ERROR_EVENTLOG_FILE_CHANGED";
    break;
  case 0x000005E0:
    ans = L"ERROR_CONTAINER_ASSIGNED";
    break;
  case 0x000005E1:
    ans = L"ERROR_JOB_NO_CONTAINER";
    break;
  case 0x0000060E:
    ans = L"ERROR_INVALID_TASK_NAME";
    break;
  case 0x0000060F:
    ans = L"ERROR_INVALID_TASK_INDEX";
    break;
  case 0x00000610:
    ans = L"ERROR_THREAD_ALREADY_IN_TASK";
    break;
  case 0x00000641:
    ans = L"ERROR_INSTALL_SERVICE_FAILURE";
    break;
  case 0x00000642:
    ans = L"ERROR_INSTALL_USEREXIT";
    break;
  case 0x00000643:
    ans = L"ERROR_INSTALL_FAILURE";
    break;
  case 0x00000644:
    ans = L"ERROR_INSTALL_SUSPEND";
    break;
  case 0x00000645:
    ans = L"ERROR_UNKNOWN_PRODUCT";
    break;
  case 0x00000646:
    ans = L"ERROR_UNKNOWN_FEATURE";
    break;
  case 0x00000647:
    ans = L"ERROR_UNKNOWN_COMPONENT";
    break;
  case 0x00000648:
    ans = L"ERROR_UNKNOWN_PROPERTY";
    break;
  case 0x00000649:
    ans = L"ERROR_INVALID_HANDLE_STATE";
    break;
  case 0x0000064A:
    ans = L"ERROR_BAD_CONFIGURATION";
    break;
  case 0x0000064B:
    ans = L"ERROR_INDEX_ABSENT";
    break;
  case 0x0000064C:
    ans = L"ERROR_INSTALL_SOURCE_ABSENT";
    break;
  case 0x0000064D:
    ans = L"ERROR_INSTALL_PACKAGE_VERSION";
    break;
  case 0x0000064E:
    ans = L"ERROR_PRODUCT_UNINSTALLED";
    break;
  case 0x0000064F:
    ans = L"ERROR_BAD_QUERY_SYNTAX";
    break;
  case 0x00000650:
    ans = L"ERROR_INVALID_FIELD";
    break;
  case 0x00000651:
    ans = L"ERROR_DEVICE_REMOVED";
    break;
  case 0x00000652:
    ans = L"ERROR_INSTALL_ALREADY_RUNNING";
    break;
  case 0x00000653:
    ans = L"ERROR_INSTALL_PACKAGE_OPEN_FAILED";
    break;
  case 0x00000654:
    ans = L"ERROR_INSTALL_PACKAGE_INVALID";
    break;
  case 0x00000655:
    ans = L"ERROR_INSTALL_UI_FAILURE";
    break;
  case 0x00000656:
    ans = L"ERROR_INSTALL_LOG_FAILURE";
    break;
  case 0x00000657:
    ans = L"ERROR_INSTALL_LANGUAGE_UNSUPPORTED";
    break;
  case 0x00000658:
    ans = L"ERROR_INSTALL_TRANSFORM_FAILURE";
    break;
  case 0x00000659:
    ans = L"ERROR_INSTALL_PACKAGE_REJECTED";
    break;
  case 0x0000065A:
    ans = L"ERROR_FUNCTION_NOT_CALLED";
    break;
  case 0x0000065B:
    ans = L"ERROR_FUNCTION_FAILED";
    break;
  case 0x0000065C:
    ans = L"ERROR_INVALID_TABLE";
    break;
  case 0x0000065D:
    ans = L"ERROR_DATATYPE_MISMATCH";
    break;
  case 0x0000065E:
    ans = L"ERROR_UNSUPPORTED_TYPE";
    break;
  case 0x0000065F:
    ans = L"ERROR_CREATE_FAILED";
    break;
  case 0x00000660:
    ans = L"ERROR_INSTALL_TEMP_UNWRITABLE";
    break;
  case 0x00000661:
    ans = L"ERROR_INSTALL_PLATFORM_UNSUPPORTED";
    break;
  case 0x00000662:
    ans = L"ERROR_INSTALL_NOTUSED";
    break;
  case 0x00000663:
    ans = L"ERROR_PATCH_PACKAGE_OPEN_FAILED";
    break;
  case 0x00000664:
    ans = L"ERROR_PATCH_PACKAGE_INVALID";
    break;
  case 0x00000665:
    ans = L"ERROR_PATCH_PACKAGE_UNSUPPORTED";
    break;
  case 0x00000666:
    ans = L"ERROR_PRODUCT_VERSION";
    break;
  case 0x00000667:
    ans = L"ERROR_INVALID_COMMAND_LINE";
    break;
  case 0x00000668:
    ans = L"ERROR_INSTALL_REMOTE_DISALLOWED";
    break;
  case 0x00000669:
    ans = L"ERROR_SUCCESS_REBOOT_INITIATED";
    break;
  case 0x0000066A:
    ans = L"ERROR_PATCH_TARGET_NOT_FOUND";
    break;
  case 0x0000066B:
    ans = L"ERROR_PATCH_PACKAGE_REJECTED";
    break;
  case 0x0000066C:
    ans = L"ERROR_INSTALL_TRANSFORM_REJECTED";
    break;
  case 0x0000066D:
    ans = L"ERROR_INSTALL_REMOTE_PROHIBITED";
    break;
  case 0x0000066E:
    ans = L"ERROR_PATCH_REMOVAL_UNSUPPORTED";
    break;
  case 0x0000066F:
    ans = L"ERROR_UNKNOWN_PATCH";
    break;
  case 0x00000670:
    ans = L"ERROR_PATCH_NO_SEQUENCE";
    break;
  case 0x00000671:
    ans = L"ERROR_PATCH_REMOVAL_DISALLOWED";
    break;
  case 0x00000672:
    ans = L"ERROR_INVALID_PATCH_XML";
    break;
  case 0x00000673:
    ans = L"ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT";
    break;
  case 0x00000674:
    ans = L"ERROR_INSTALL_SERVICE_SAFEBOOT";
    break;
  case 0x00000675:
    ans = L"ERROR_FAIL_FAST_EXCEPTION";
    break;
  case 0x00000676:
    ans = L"ERROR_INSTALL_REJECTED";
    break;
  case 0x00000677:
    ans = L"ERROR_DYNAMIC_CODE_BLOCKED";
    break;
  case 0x00000678:
    ans = L"ERROR_NOT_SAME_OBJECT";
    break;
  case 0x00000679:
    ans = L"ERROR_STRICT_CFG_VIOLATION";
    break;
  case 0x0000067C:
    ans = L"ERROR_SET_CONTEXT_DENIED";
    break;
  case 0x0000067D:
    ans = L"ERROR_CROSS_PARTITION_VIOLATION";
    break;
  case 0x000006A4:
    ans = L"RPC_S_INVALID_STRING_BINDING";
    break;
  case 0x000006A5:
    ans = L"RPC_S_WRONG_KIND_OF_BINDING";
    break;
  case 0x000006A6:
    ans = L"RPC_S_INVALID_BINDING";
    break;
  case 0x000006A7:
    ans = L"RPC_S_PROTSEQ_NOT_SUPPORTED";
    break;
  case 0x000006A8:
    ans = L"RPC_S_INVALID_RPC_PROTSEQ";
    break;
  case 0x000006A9:
    ans = L"RPC_S_INVALID_STRING_UUID";
    break;
  case 0x000006AA:
    ans = L"RPC_S_INVALID_ENDPOINT_FORMAT";
    break;
  case 0x000006AB:
    ans = L"RPC_S_INVALID_NET_ADDR";
    break;
  case 0x000006AC:
    ans = L"RPC_S_NO_ENDPOINT_FOUND";
    break;
  case 0x000006AD:
    ans = L"RPC_S_INVALID_TIMEOUT";
    break;
  case 0x000006AE:
    ans = L"RPC_S_OBJECT_NOT_FOUND";
    break;
  case 0x000006AF:
    ans = L"RPC_S_ALREADY_REGISTERED";
    break;
  case 0x000006B0:
    ans = L"RPC_S_TYPE_ALREADY_REGISTERED";
    break;
  case 0x000006B1:
    ans = L"RPC_S_ALREADY_LISTENING";
    break;
  case 0x000006B2:
    ans = L"RPC_S_NO_PROTSEQS_REGISTERED";
    break;
  case 0x000006B3:
    ans = L"RPC_S_NOT_LISTENING";
    break;
  case 0x000006B4:
    ans = L"RPC_S_UNKNOWN_MGR_TYPE";
    break;
  case 0x000006B5:
    ans = L"RPC_S_UNKNOWN_IF";
    break;
  case 0x000006B6:
    ans = L"RPC_S_NO_BINDINGS";
    break;
  case 0x000006B7:
    ans = L"RPC_S_NO_PROTSEQS";
    break;
  case 0x000006B8:
    ans = L"RPC_S_CANT_CREATE_ENDPOINT";
    break;
  case 0x000006B9:
    ans = L"RPC_S_OUT_OF_RESOURCES";
    break;
  case 0x000006BA:
    ans = L"RPC_S_SERVER_UNAVAILABLE";
    break;
  case 0x000006BB:
    ans = L"RPC_S_SERVER_TOO_BUSY";
    break;
  case 0x000006BC:
    ans = L"RPC_S_INVALID_NETWORK_OPTIONS";
    break;
  case 0x000006BD:
    ans = L"RPC_S_NO_CALL_ACTIVE";
    break;
  case 0x000006BE:
    ans = L"RPC_S_CALL_FAILED";
    break;
  case 0x000006BF:
    ans = L"RPC_S_CALL_FAILED_DNE";
    break;
  case 0x000006C0:
    ans = L"RPC_S_PROTOCOL_ERROR";
    break;
  case 0x000006C1:
    ans = L"RPC_S_PROXY_ACCESS_DENIED";
    break;
  case 0x000006C2:
    ans = L"RPC_S_UNSUPPORTED_TRANS_SYN";
    break;
  case 0x000006C4:
    ans = L"RPC_S_UNSUPPORTED_TYPE";
    break;
  case 0x000006C5:
    ans = L"RPC_S_INVALID_TAG";
    break;
  case 0x000006C6:
    ans = L"RPC_S_INVALID_BOUND";
    break;
  case 0x000006C7:
    ans = L"RPC_S_NO_ENTRY_NAME";
    break;
  case 0x000006C8:
    ans = L"RPC_S_INVALID_NAME_SYNTAX";
    break;
  case 0x000006C9:
    ans = L"RPC_S_UNSUPPORTED_NAME_SYNTAX";
    break;
  case 0x000006CB:
    ans = L"RPC_S_UUID_NO_ADDRESS";
    break;
  case 0x000006CC:
    ans = L"RPC_S_DUPLICATE_ENDPOINT";
    break;
  case 0x000006CD:
    ans = L"RPC_S_UNKNOWN_AUTHN_TYPE";
    break;
  case 0x000006CE:
    ans = L"RPC_S_MAX_CALLS_TOO_SMALL";
    break;
  case 0x000006CF:
    ans = L"RPC_S_STRING_TOO_LONG";
    break;
  case 0x000006D0:
    ans = L"RPC_S_PROTSEQ_NOT_FOUND";
    break;
  case 0x000006D1:
    ans = L"RPC_S_PROCNUM_OUT_OF_RANGE";
    break;
  case 0x000006D2:
    ans = L"RPC_S_BINDING_HAS_NO_AUTH";
    break;
  case 0x000006D3:
    ans = L"RPC_S_UNKNOWN_AUTHN_SERVICE";
    break;
  case 0x000006D4:
    ans = L"RPC_S_UNKNOWN_AUTHN_LEVEL";
    break;
  case 0x000006D5:
    ans = L"RPC_S_INVALID_AUTH_IDENTITY";
    break;
  case 0x000006D6:
    ans = L"RPC_S_UNKNOWN_AUTHZ_SERVICE";
    break;
  case 0x000006D7:
    ans = L"EPT_S_INVALID_ENTRY";
    break;
  case 0x000006D8:
    ans = L"EPT_S_CANT_PERFORM_OP";
    break;
  case 0x000006D9:
    ans = L"EPT_S_NOT_REGISTERED";
    break;
  case 0x000006DA:
    ans = L"RPC_S_NOTHING_TO_EXPORT";
    break;
  case 0x000006DB:
    ans = L"RPC_S_INCOMPLETE_NAME";
    break;
  case 0x000006DC:
    ans = L"RPC_S_INVALID_VERS_OPTION";
    break;
  case 0x000006DD:
    ans = L"RPC_S_NO_MORE_MEMBERS";
    break;
  case 0x000006DE:
    ans = L"RPC_S_NOT_ALL_OBJS_UNEXPORTED";
    break;
  case 0x000006DF:
    ans = L"RPC_S_INTERFACE_NOT_FOUND";
    break;
  case 0x000006E0:
    ans = L"RPC_S_ENTRY_ALREADY_EXISTS";
    break;
  case 0x000006E1:
    ans = L"RPC_S_ENTRY_NOT_FOUND";
    break;
  case 0x000006E2:
    ans = L"RPC_S_NAME_SERVICE_UNAVAILABLE";
    break;
  case 0x000006E3:
    ans = L"RPC_S_INVALID_NAF_ID";
    break;
  case 0x000006E4:
    ans = L"RPC_S_CANNOT_SUPPORT";
    break;
  case 0x000006E5:
    ans = L"RPC_S_NO_CONTEXT_AVAILABLE";
    break;
  case 0x000006E6:
    ans = L"RPC_S_INTERNAL_ERROR";
    break;
  case 0x000006E7:
    ans = L"RPC_S_ZERO_DIVIDE";
    break;
  case 0x000006E8:
    ans = L"RPC_S_ADDRESS_ERROR";
    break;
  case 0x000006E9:
    ans = L"RPC_S_FP_DIV_ZERO";
    break;
  case 0x000006EA:
    ans = L"RPC_S_FP_UNDERFLOW";
    break;
  case 0x000006EB:
    ans = L"RPC_S_FP_OVERFLOW";
    break;
  case 0x000006EC:
    ans = L"RPC_X_NO_MORE_ENTRIES";
    break;
  case 0x000006ED:
    ans = L"RPC_X_SS_CHAR_TRANS_OPEN_FAIL";
    break;
  case 0x000006EE:
    ans = L"RPC_X_SS_CHAR_TRANS_SHORT_FILE";
    break;
  case 0x000006EF:
    ans = L"RPC_X_SS_IN_NULL_CONTEXT";
    break;
  case 0x000006F1:
    ans = L"RPC_X_SS_CONTEXT_DAMAGED";
    break;
  case 0x000006F2:
    ans = L"RPC_X_SS_HANDLES_MISMATCH";
    break;
  case 0x000006F3:
    ans = L"RPC_X_SS_CANNOT_GET_CALL_HANDLE";
    break;
  case 0x000006F4:
    ans = L"RPC_X_NULL_REF_POINTER";
    break;
  case 0x000006F5:
    ans = L"RPC_X_ENUM_VALUE_OUT_OF_RANGE";
    break;
  case 0x000006F6:
    ans = L"RPC_X_BYTE_COUNT_TOO_SMALL";
    break;
  case 0x000006F7:
    ans = L"RPC_X_BAD_STUB_DATA";
    break;
  case 0x000006F8:
    ans = L"ERROR_INVALID_USER_BUFFER";
    break;
  case 0x000006F9:
    ans = L"ERROR_UNRECOGNIZED_MEDIA";
    break;
  case 0x000006FA:
    ans = L"ERROR_NO_TRUST_LSA_SECRET";
    break;
  case 0x000006FB:
    ans = L"ERROR_NO_TRUST_SAM_ACCOUNT";
    break;
  case 0x000006FC:
    ans = L"ERROR_TRUSTED_DOMAIN_FAILURE";
    break;
  case 0x000006FD:
    ans = L"ERROR_TRUSTED_RELATIONSHIP_FAILURE";
    break;
  case 0x000006FE:
    ans = L"ERROR_TRUST_FAILURE";
    break;
  case 0x000006FF:
    ans = L"RPC_S_CALL_IN_PROGRESS";
    break;
  case 0x00000700:
    ans = L"ERROR_NETLOGON_NOT_STARTED";
    break;
  case 0x00000701:
    ans = L"ERROR_ACCOUNT_EXPIRED";
    break;
  case 0x00000702:
    ans = L"ERROR_REDIRECTOR_HAS_OPEN_HANDLES";
    break;
  case 0x00000703:
    ans = L"ERROR_PRINTER_DRIVER_ALREADY_INSTALLED";
    break;
  case 0x00000704:
    ans = L"ERROR_UNKNOWN_PORT";
    break;
  case 0x00000705:
    ans = L"ERROR_UNKNOWN_PRINTER_DRIVER";
    break;
  case 0x00000706:
    ans = L"ERROR_UNKNOWN_PRINTPROCESSOR";
    break;
  case 0x00000707:
    ans = L"ERROR_INVALID_SEPARATOR_FILE";
    break;
  case 0x00000708:
    ans = L"ERROR_INVALID_PRIORITY";
    break;
  case 0x00000709:
    ans = L"ERROR_INVALID_PRINTER_NAME";
    break;
  case 0x0000070A:
    ans = L"ERROR_PRINTER_ALREADY_EXISTS";
    break;
  case 0x0000070B:
    ans = L"ERROR_INVALID_PRINTER_COMMAND";
    break;
  case 0x0000070C:
    ans = L"ERROR_INVALID_DATATYPE";
    break;
  case 0x0000070D:
    ans = L"ERROR_INVALID_ENVIRONMENT";
    break;
  case 0x0000070E:
    ans = L"RPC_S_NO_MORE_BINDINGS";
    break;
  case 0x0000070F:
    ans = L"ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT";
    break;
  case 0x00000710:
    ans = L"ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT";
    break;
  case 0x00000711:
    ans = L"ERROR_NOLOGON_SERVER_TRUST_ACCOUNT";
    break;
  case 0x00000712:
    ans = L"ERROR_DOMAIN_TRUST_INCONSISTENT";
    break;
  case 0x00000713:
    ans = L"ERROR_SERVER_HAS_OPEN_HANDLES";
    break;
  case 0x00000714:
    ans = L"ERROR_RESOURCE_DATA_NOT_FOUND";
    break;
  case 0x00000715:
    ans = L"ERROR_RESOURCE_TYPE_NOT_FOUND";
    break;
  case 0x00000716:
    ans = L"ERROR_RESOURCE_NAME_NOT_FOUND";
    break;
  case 0x00000717:
    ans = L"ERROR_RESOURCE_LANG_NOT_FOUND";
    break;
  case 0x00000718:
    ans = L"ERROR_NOT_ENOUGH_QUOTA";
    break;
  case 0x00000719:
    ans = L"RPC_S_NO_INTERFACES";
    break;
  case 0x0000071A:
    ans = L"RPC_S_CALL_CANCELLED";
    break;
  case 0x0000071B:
    ans = L"RPC_S_BINDING_INCOMPLETE";
    break;
  case 0x0000071C:
    ans = L"RPC_S_COMM_FAILURE";
    break;
  case 0x0000071D:
    ans = L"RPC_S_UNSUPPORTED_AUTHN_LEVEL";
    break;
  case 0x0000071E:
    ans = L"RPC_S_NO_PRINC_NAME";
    break;
  case 0x0000071F:
    ans = L"RPC_S_NOT_RPC_ERROR";
    break;
  case 0x00000720:
    ans = L"RPC_S_UUID_LOCAL_ONLY";
    break;
  case 0x00000721:
    ans = L"RPC_S_SEC_PKG_ERROR";
    break;
  case 0x00000722:
    ans = L"RPC_S_NOT_CANCELLED";
    break;
  case 0x00000723:
    ans = L"RPC_X_INVALID_ES_ACTION";
    break;
  case 0x00000724:
    ans = L"RPC_X_WRONG_ES_VERSION";
    break;
  case 0x00000725:
    ans = L"RPC_X_WRONG_STUB_VERSION";
    break;
  case 0x00000726:
    ans = L"RPC_X_INVALID_PIPE_OBJECT";
    break;
  case 0x00000727:
    ans = L"RPC_X_WRONG_PIPE_ORDER";
    break;
  case 0x00000728:
    ans = L"RPC_X_WRONG_PIPE_VERSION";
    break;
  case 0x00000729:
    ans = L"RPC_S_COOKIE_AUTH_FAILED";
    break;
  case 0x0000072A:
    ans = L"RPC_S_DO_NOT_DISTURB";
    break;
  case 0x0000072B:
    ans = L"RPC_S_SYSTEM_HANDLE_COUNT_EXCEEDED";
    break;
  case 0x0000072C:
    ans = L"RPC_S_SYSTEM_HANDLE_TYPE_MISMATCH";
    break;
  case 0x0000076A:
    ans = L"RPC_S_GROUP_MEMBER_NOT_FOUND";
    break;
  case 0x0000076B:
    ans = L"EPT_S_CANT_CREATE";
    break;
  case 0x0000076C:
    ans = L"RPC_S_INVALID_OBJECT";
    break;
  case 0x0000076D:
    ans = L"ERROR_INVALID_TIME";
    break;
  case 0x0000076E:
    ans = L"ERROR_INVALID_FORM_NAME";
    break;
  case 0x0000076F:
    ans = L"ERROR_INVALID_FORM_SIZE";
    break;
  case 0x00000770:
    ans = L"ERROR_ALREADY_WAITING";
    break;
  case 0x00000771:
    ans = L"ERROR_PRINTER_DELETED";
    break;
  case 0x00000772:
    ans = L"ERROR_INVALID_PRINTER_STATE";
    break;
  case 0x00000773:
    ans = L"ERROR_PASSWORD_MUST_CHANGE";
    break;
  case 0x00000774:
    ans = L"ERROR_DOMAIN_CONTROLLER_NOT_FOUND";
    break;
  case 0x00000775:
    ans = L"ERROR_ACCOUNT_LOCKED_OUT";
    break;
  case 0x00000776:
    ans = L"OR_INVALID_OXID";
    break;
  case 0x00000777:
    ans = L"OR_INVALID_OID";
    break;
  case 0x00000778:
    ans = L"OR_INVALID_SET";
    break;
  case 0x00000779:
    ans = L"RPC_S_SEND_INCOMPLETE";
    break;
  case 0x0000077A:
    ans = L"RPC_S_INVALID_ASYNC_HANDLE";
    break;
  case 0x0000077B:
    ans = L"RPC_S_INVALID_ASYNC_CALL";
    break;
  case 0x0000077C:
    ans = L"RPC_X_PIPE_CLOSED";
    break;
  case 0x0000077D:
    ans = L"RPC_X_PIPE_DISCIPLINE_ERROR";
    break;
  case 0x0000077E:
    ans = L"RPC_X_PIPE_EMPTY";
    break;
  case 0x0000077F:
    ans = L"ERROR_NO_SITENAME";
    break;
  case 0x00000780:
    ans = L"ERROR_CANT_ACCESS_FILE";
    break;
  case 0x00000781:
    ans = L"ERROR_CANT_RESOLVE_FILENAME";
    break;
  case 0x00000782:
    ans = L"RPC_S_ENTRY_TYPE_MISMATCH";
    break;
  case 0x00000783:
    ans = L"RPC_S_NOT_ALL_OBJS_EXPORTED";
    break;
  case 0x00000784:
    ans = L"RPC_S_INTERFACE_NOT_EXPORTED";
    break;
  case 0x00000785:
    ans = L"RPC_S_PROFILE_NOT_ADDED";
    break;
  case 0x00000786:
    ans = L"RPC_S_PRF_ELT_NOT_ADDED";
    break;
  case 0x00000787:
    ans = L"RPC_S_PRF_ELT_NOT_REMOVED";
    break;
  case 0x00000788:
    ans = L"RPC_S_GRP_ELT_NOT_ADDED";
    break;
  case 0x00000789:
    ans = L"RPC_S_GRP_ELT_NOT_REMOVED";
    break;
  case 0x0000078A:
    ans = L"ERROR_KM_DRIVER_BLOCKED";
    break;
  case 0x0000078B:
    ans = L"ERROR_CONTEXT_EXPIRED";
    break;
  case 0x0000078C:
    ans = L"ERROR_PER_USER_TRUST_QUOTA_EXCEEDED";
    break;
  case 0x0000078D:
    ans = L"ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED";
    break;
  case 0x0000078E:
    ans = L"ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED";
    break;
  case 0x0000078F:
    ans = L"ERROR_AUTHENTICATION_FIREWALL_FAILED";
    break;
  case 0x00000790:
    ans = L"ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED";
    break;
  case 0x00000791:
    ans = L"ERROR_NTLM_BLOCKED";
    break;
  case 0x00000792:
    ans = L"ERROR_PASSWORD_CHANGE_REQUIRED";
    break;
  case 0x00000793:
    ans = L"ERROR_LOST_MODE_LOGON_RESTRICTION";
    break;
  case 0x000007D0:
    ans = L"ERROR_INVALID_PIXEL_FORMAT";
    break;
  case 0x000007D1:
    ans = L"ERROR_BAD_DRIVER";
    break;
  case 0x000007D2:
    ans = L"ERROR_INVALID_WINDOW_STYLE";
    break;
  case 0x000007D3:
    ans = L"ERROR_METAFILE_NOT_SUPPORTED";
    break;
  case 0x000007D4:
    ans = L"ERROR_TRANSFORM_NOT_SUPPORTED";
    break;
  case 0x000007D5:
    ans = L"ERROR_CLIPPING_NOT_SUPPORTED";
    break;
  case 0x000007DA:
    ans = L"ERROR_INVALID_CMM";
    break;
  case 0x000007DB:
    ans = L"ERROR_INVALID_PROFILE";
    break;
  case 0x000007DC:
    ans = L"ERROR_TAG_NOT_FOUND";
    break;
  case 0x000007DD:
    ans = L"ERROR_TAG_NOT_PRESENT";
    break;
  case 0x000007DE:
    ans = L"ERROR_DUPLICATE_TAG";
    break;
  case 0x000007DF:
    ans = L"ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE";
    break;
  case 0x000007E0:
    ans = L"ERROR_PROFILE_NOT_FOUND";
    break;
  case 0x000007E1:
    ans = L"ERROR_INVALID_COLORSPACE";
    break;
  case 0x000007E2:
    ans = L"ERROR_ICM_NOT_ENABLED";
    break;
  case 0x000007E3:
    ans = L"ERROR_DELETING_ICM_XFORM";
    break;
  case 0x000007E4:
    ans = L"ERROR_INVALID_TRANSFORM";
    break;
  case 0x000007E5:
    ans = L"ERROR_COLORSPACE_MISMATCH";
    break;
  case 0x000007E6:
    ans = L"ERROR_INVALID_COLORINDEX";
    break;
  case 0x000007E7:
    ans = L"ERROR_PROFILE_DOES_NOT_MATCH_DEVICE";
    break;
  case 0x0000083C:
    ans = L"ERROR_CONNECTED_OTHER_PASSWORD";
    break;
  case 0x0000083D:
    ans = L"ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT";
    break;
  case 0x0000089A:
    ans = L"ERROR_BAD_USERNAME";
    break;
  case 0x000008CA:
    ans = L"ERROR_NOT_CONNECTED";
    break;
  case 0x00000961:
    ans = L"ERROR_OPEN_FILES";
    break;
  case 0x00000962:
    ans = L"ERROR_ACTIVE_CONNECTIONS";
    break;
  case 0x00000964:
    ans = L"ERROR_DEVICE_IN_USE";
    break;
  case 0x00000BB8:
    ans = L"ERROR_UNKNOWN_PRINT_MONITOR";
    break;
  case 0x00000BB9:
    ans = L"ERROR_PRINTER_DRIVER_IN_USE";
    break;
  case 0x00000BBA:
    ans = L"ERROR_SPOOL_FILE_NOT_FOUND";
    break;
  case 0x00000BBB:
    ans = L"ERROR_SPL_NO_STARTDOC";
    break;
  case 0x00000BBC:
    ans = L"ERROR_SPL_NO_ADDJOB";
    break;
  case 0x00000BBD:
    ans = L"ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED";
    break;
  case 0x00000BBE:
    ans = L"ERROR_PRINT_MONITOR_ALREADY_INSTALLED";
    break;
  case 0x00000BBF:
    ans = L"ERROR_INVALID_PRINT_MONITOR";
    break;
  case 0x00000BC0:
    ans = L"ERROR_PRINT_MONITOR_IN_USE";
    break;
  case 0x00000BC1:
    ans = L"ERROR_PRINTER_HAS_JOBS_QUEUED";
    break;
  case 0x00000BC2:
    ans = L"ERROR_SUCCESS_REBOOT_REQUIRED";
    break;
  case 0x00000BC3:
    ans = L"ERROR_SUCCESS_RESTART_REQUIRED";
    break;
  case 0x00000BC4:
    ans = L"ERROR_PRINTER_NOT_FOUND";
    break;
  case 0x00000BC5:
    ans = L"ERROR_PRINTER_DRIVER_WARNED";
    break;
  case 0x00000BC6:
    ans = L"ERROR_PRINTER_DRIVER_BLOCKED";
    break;
  case 0x00000BC7:
    ans = L"ERROR_PRINTER_DRIVER_PACKAGE_IN_USE";
    break;
  case 0x00000BC8:
    ans = L"ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND";
    break;
  case 0x00000BC9:
    ans = L"ERROR_FAIL_REBOOT_REQUIRED";
    break;
  case 0x00000BCA:
    ans = L"ERROR_FAIL_REBOOT_INITIATED";
    break;
  case 0x00000BCB:
    ans = L"ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED";
    break;
  case 0x00000BCC:
    ans = L"ERROR_PRINT_JOB_RESTART_REQUIRED";
    break;
  case 0x00000BCD:
    ans = L"ERROR_INVALID_PRINTER_DRIVER_MANIFEST";
    break;
  case 0x00000BCE:
    ans = L"ERROR_PRINTER_NOT_SHAREABLE";
    break;
  case 0x00000BEA:
    ans = L"ERROR_REQUEST_PAUSED";
    break;
  case 0x00000BF4:
    ans = L"ERROR_APPEXEC_CONDITION_NOT_SATISFIED";
    break;
  case 0x00000BF5:
    ans = L"ERROR_APPEXEC_HANDLE_INVALIDATED";
    break;
  case 0x00000BF6:
    ans = L"ERROR_APPEXEC_INVALID_HOST_GENERATION";
    break;
  case 0x00000BF7:
    ans = L"ERROR_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION";
    break;
  case 0x00000BF8:
    ans = L"ERROR_APPEXEC_INVALID_HOST_STATE";
    break;
  case 0x00000BF9:
    ans = L"ERROR_APPEXEC_NO_DONOR";
    break;
  case 0x00000BFA:
    ans = L"ERROR_APPEXEC_HOST_ID_MISMATCH";
    break;
  case 0x00000BFB:
    ans = L"ERROR_APPEXEC_UNKNOWN_USER";
    break;
  case 0x00000F6E:
    ans = L"ERROR_IO_REISSUE_AS_CACHED";
    break;
  case 0x00000FA0:
    ans = L"ERROR_WINS_INTERNAL";
    break;
  case 0x00000FA1:
    ans = L"ERROR_CAN_NOT_DEL_LOCAL_WINS";
    break;
  case 0x00000FA2:
    ans = L"ERROR_STATIC_INIT";
    break;
  case 0x00000FA3:
    ans = L"ERROR_INC_BACKUP";
    break;
  case 0x00000FA4:
    ans = L"ERROR_FULL_BACKUP";
    break;
  case 0x00000FA5:
    ans = L"ERROR_REC_NON_EXISTENT";
    break;
  case 0x00000FA6:
    ans = L"ERROR_RPL_NOT_ALLOWED";
    break;
  case 0x00000FD2:
    ans = L"PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED";
    break;
  case 0x00000FD3:
    ans = L"PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO";
    break;
  case 0x00000FD4:
    ans = L"PEERDIST_ERROR_MISSING_DATA";
    break;
  case 0x00000FD5:
    ans = L"PEERDIST_ERROR_NO_MORE";
    break;
  case 0x00000FD6:
    ans = L"PEERDIST_ERROR_NOT_INITIALIZED";
    break;
  case 0x00000FD7:
    ans = L"PEERDIST_ERROR_ALREADY_INITIALIZED";
    break;
  case 0x00000FD8:
    ans = L"PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS";
    break;
  case 0x00000FD9:
    ans = L"PEERDIST_ERROR_INVALIDATED";
    break;
  case 0x00000FDA:
    ans = L"PEERDIST_ERROR_ALREADY_EXISTS";
    break;
  case 0x00000FDB:
    ans = L"PEERDIST_ERROR_OPERATION_NOTFOUND";
    break;
  case 0x00000FDC:
    ans = L"PEERDIST_ERROR_ALREADY_COMPLETED";
    break;
  case 0x00000FDD:
    ans = L"PEERDIST_ERROR_OUT_OF_BOUNDS";
    break;
  case 0x00000FDE:
    ans = L"PEERDIST_ERROR_VERSION_UNSUPPORTED";
    break;
  case 0x00000FDF:
    ans = L"PEERDIST_ERROR_INVALID_CONFIGURATION";
    break;
  case 0x00000FE0:
    ans = L"PEERDIST_ERROR_NOT_LICENSED";
    break;
  case 0x00000FE1:
    ans = L"PEERDIST_ERROR_SERVICE_UNAVAILABLE";
    break;
  case 0x00000FE2:
    ans = L"PEERDIST_ERROR_TRUST_FAILURE";
    break;
  case 0x00001004:
    ans = L"ERROR_DHCP_ADDRESS_CONFLICT";
    break;
  case 0x00001068:
    ans = L"ERROR_WMI_GUID_NOT_FOUND";
    break;
  case 0x00001069:
    ans = L"ERROR_WMI_INSTANCE_NOT_FOUND";
    break;
  case 0x0000106A:
    ans = L"ERROR_WMI_ITEMID_NOT_FOUND";
    break;
  case 0x0000106B:
    ans = L"ERROR_WMI_TRY_AGAIN";
    break;
  case 0x0000106C:
    ans = L"ERROR_WMI_DP_NOT_FOUND";
    break;
  case 0x0000106D:
    ans = L"ERROR_WMI_UNRESOLVED_INSTANCE_REF";
    break;
  case 0x0000106E:
    ans = L"ERROR_WMI_ALREADY_ENABLED";
    break;
  case 0x0000106F:
    ans = L"ERROR_WMI_GUID_DISCONNECTED";
    break;
  case 0x00001070:
    ans = L"ERROR_WMI_SERVER_UNAVAILABLE";
    break;
  case 0x00001071:
    ans = L"ERROR_WMI_DP_FAILED";
    break;
  case 0x00001072:
    ans = L"ERROR_WMI_INVALID_MOF";
    break;
  case 0x00001073:
    ans = L"ERROR_WMI_INVALID_REGINFO";
    break;
  case 0x00001074:
    ans = L"ERROR_WMI_ALREADY_DISABLED";
    break;
  case 0x00001075:
    ans = L"ERROR_WMI_READ_ONLY";
    break;
  case 0x00001076:
    ans = L"ERROR_WMI_SET_FAILURE";
    break;
  case 0x0000109A:
    ans = L"ERROR_NOT_APPCONTAINER";
    break;
  case 0x0000109B:
    ans = L"ERROR_APPCONTAINER_REQUIRED";
    break;
  case 0x0000109C:
    ans = L"ERROR_NOT_SUPPORTED_IN_APPCONTAINER";
    break;
  case 0x0000109D:
    ans = L"ERROR_INVALID_PACKAGE_SID_LENGTH";
    break;
  case 0x000010CC:
    ans = L"ERROR_INVALID_MEDIA";
    break;
  case 0x000010CD:
    ans = L"ERROR_INVALID_LIBRARY";
    break;
  case 0x000010CE:
    ans = L"ERROR_INVALID_MEDIA_POOL";
    break;
  case 0x000010CF:
    ans = L"ERROR_DRIVE_MEDIA_MISMATCH";
    break;
  case 0x000010D0:
    ans = L"ERROR_MEDIA_OFFLINE";
    break;
  case 0x000010D1:
    ans = L"ERROR_LIBRARY_OFFLINE";
    break;
  case 0x000010D2:
    ans = L"ERROR_EMPTY";
    break;
  case 0x000010D3:
    ans = L"ERROR_NOT_EMPTY";
    break;
  case 0x000010D4:
    ans = L"ERROR_MEDIA_UNAVAILABLE";
    break;
  case 0x000010D5:
    ans = L"ERROR_RESOURCE_DISABLED";
    break;
  case 0x000010D6:
    ans = L"ERROR_INVALID_CLEANER";
    break;
  case 0x000010D7:
    ans = L"ERROR_UNABLE_TO_CLEAN";
    break;
  case 0x000010D8:
    ans = L"ERROR_OBJECT_NOT_FOUND";
    break;
  case 0x000010D9:
    ans = L"ERROR_DATABASE_FAILURE";
    break;
  case 0x000010DA:
    ans = L"ERROR_DATABASE_FULL";
    break;
  case 0x000010DB:
    ans = L"ERROR_MEDIA_INCOMPATIBLE";
    break;
  case 0x000010DC:
    ans = L"ERROR_RESOURCE_NOT_PRESENT";
    break;
  case 0x000010DD:
    ans = L"ERROR_INVALID_OPERATION";
    break;
  case 0x000010DE:
    ans = L"ERROR_MEDIA_NOT_AVAILABLE";
    break;
  case 0x000010DF:
    ans = L"ERROR_DEVICE_NOT_AVAILABLE";
    break;
  case 0x000010E0:
    ans = L"ERROR_REQUEST_REFUSED";
    break;
  case 0x000010E1:
    ans = L"ERROR_INVALID_DRIVE_OBJECT";
    break;
  case 0x000010E2:
    ans = L"ERROR_LIBRARY_FULL";
    break;
  case 0x000010E3:
    ans = L"ERROR_MEDIUM_NOT_ACCESSIBLE";
    break;
  case 0x000010E4:
    ans = L"ERROR_UNABLE_TO_LOAD_MEDIUM";
    break;
  case 0x000010E5:
    ans = L"ERROR_UNABLE_TO_INVENTORY_DRIVE";
    break;
  case 0x000010E6:
    ans = L"ERROR_UNABLE_TO_INVENTORY_SLOT";
    break;
  case 0x000010E7:
    ans = L"ERROR_UNABLE_TO_INVENTORY_TRANSPORT";
    break;
  case 0x000010E8:
    ans = L"ERROR_TRANSPORT_FULL";
    break;
  case 0x000010E9:
    ans = L"ERROR_CONTROLLING_IEPORT";
    break;
  case 0x000010EA:
    ans = L"ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA";
    break;
  case 0x000010EB:
    ans = L"ERROR_CLEANER_SLOT_SET";
    break;
  case 0x000010EC:
    ans = L"ERROR_CLEANER_SLOT_NOT_SET";
    break;
  case 0x000010ED:
    ans = L"ERROR_CLEANER_CARTRIDGE_SPENT";
    break;
  case 0x000010EE:
    ans = L"ERROR_UNEXPECTED_OMID";
    break;
  case 0x000010EF:
    ans = L"ERROR_CANT_DELETE_LAST_ITEM";
    break;
  case 0x000010F0:
    ans = L"ERROR_MESSAGE_EXCEEDS_MAX_SIZE";
    break;
  case 0x000010F1:
    ans = L"ERROR_VOLUME_CONTAINS_SYS_FILES";
    break;
  case 0x000010F2:
    ans = L"ERROR_INDIGENOUS_TYPE";
    break;
  case 0x000010F3:
    ans = L"ERROR_NO_SUPPORTING_DRIVES";
    break;
  case 0x000010F4:
    ans = L"ERROR_CLEANER_CARTRIDGE_INSTALLED";
    break;
  case 0x000010F5:
    ans = L"ERROR_IEPORT_FULL";
    break;
  case 0x000010FE:
    ans = L"ERROR_FILE_OFFLINE";
    break;
  case 0x000010FF:
    ans = L"ERROR_REMOTE_STORAGE_NOT_ACTIVE";
    break;
  case 0x00001100:
    ans = L"ERROR_REMOTE_STORAGE_MEDIA_ERROR";
    break;
  case 0x00001126:
    ans = L"ERROR_NOT_A_REPARSE_POINT";
    break;
  case 0x00001127:
    ans = L"ERROR_REPARSE_ATTRIBUTE_CONFLICT";
    break;
  case 0x00001128:
    ans = L"ERROR_INVALID_REPARSE_DATA";
    break;
  case 0x00001129:
    ans = L"ERROR_REPARSE_TAG_INVALID";
    break;
  case 0x0000112A:
    ans = L"ERROR_REPARSE_TAG_MISMATCH";
    break;
  case 0x0000112B:
    ans = L"ERROR_REPARSE_POINT_ENCOUNTERED";
    break;
  case 0x00001130:
    ans = L"ERROR_APP_DATA_NOT_FOUND";
    break;
  case 0x00001131:
    ans = L"ERROR_APP_DATA_EXPIRED";
    break;
  case 0x00001132:
    ans = L"ERROR_APP_DATA_CORRUPT";
    break;
  case 0x00001133:
    ans = L"ERROR_APP_DATA_LIMIT_EXCEEDED";
    break;
  case 0x00001134:
    ans = L"ERROR_APP_DATA_REBOOT_REQUIRED";
    break;
  case 0x00001144:
    ans = L"ERROR_SECUREBOOT_ROLLBACK_DETECTED";
    break;
  case 0x00001145:
    ans = L"ERROR_SECUREBOOT_POLICY_VIOLATION";
    break;
  case 0x00001146:
    ans = L"ERROR_SECUREBOOT_INVALID_POLICY";
    break;
  case 0x00001147:
    ans = L"ERROR_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND";
    break;
  case 0x00001148:
    ans = L"ERROR_SECUREBOOT_POLICY_NOT_SIGNED";
    break;
  case 0x00001149:
    ans = L"ERROR_SECUREBOOT_NOT_ENABLED";
    break;
  case 0x0000114A:
    ans = L"ERROR_SECUREBOOT_FILE_REPLACED";
    break;
  case 0x0000114B:
    ans = L"ERROR_SECUREBOOT_POLICY_NOT_AUTHORIZED";
    break;
  case 0x0000114C:
    ans = L"ERROR_SECUREBOOT_POLICY_UNKNOWN";
    break;
  case 0x0000114D:
    ans = L"ERROR_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION";
    break;
  case 0x0000114E:
    ans = L"ERROR_SECUREBOOT_PLATFORM_ID_MISMATCH";
    break;
  case 0x0000114F:
    ans = L"ERROR_SECUREBOOT_POLICY_ROLLBACK_DETECTED";
    break;
  case 0x00001150:
    ans = L"ERROR_SECUREBOOT_POLICY_UPGRADE_MISMATCH";
    break;
  case 0x00001151:
    ans = L"ERROR_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING";
    break;
  case 0x00001152:
    ans = L"ERROR_SECUREBOOT_NOT_BASE_POLICY";
    break;
  case 0x00001153:
    ans = L"ERROR_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY";
    break;
  case 0x00001158:
    ans = L"ERROR_OFFLOAD_READ_FLT_NOT_SUPPORTED";
    break;
  case 0x00001159:
    ans = L"ERROR_OFFLOAD_WRITE_FLT_NOT_SUPPORTED";
    break;
  case 0x0000115A:
    ans = L"ERROR_OFFLOAD_READ_FILE_NOT_SUPPORTED";
    break;
  case 0x0000115B:
    ans = L"ERROR_OFFLOAD_WRITE_FILE_NOT_SUPPORTED";
    break;
  case 0x0000115C:
    ans = L"ERROR_ALREADY_HAS_STREAM_ID";
    break;
  case 0x0000115D:
    ans = L"ERROR_SMR_GARBAGE_COLLECTION_REQUIRED";
    break;
  case 0x0000115E:
    ans = L"ERROR_WOF_WIM_HEADER_CORRUPT";
    break;
  case 0x0000115F:
    ans = L"ERROR_WOF_WIM_RESOURCE_TABLE_CORRUPT";
    break;
  case 0x00001160:
    ans = L"ERROR_WOF_FILE_RESOURCE_TABLE_CORRUPT";
    break;
  case 0x00001194:
    ans = L"ERROR_VOLUME_NOT_SIS_ENABLED";
    break;
  case 0x000011C6:
    ans = L"ERROR_SYSTEM_INTEGRITY_ROLLBACK_DETECTED";
    break;
  case 0x000011C7:
    ans = L"ERROR_SYSTEM_INTEGRITY_POLICY_VIOLATION";
    break;
  case 0x000011C8:
    ans = L"ERROR_SYSTEM_INTEGRITY_INVALID_POLICY";
    break;
  case 0x000011C9:
    ans = L"ERROR_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED";
    break;
  case 0x000011D0:
    ans = L"ERROR_VSM_NOT_INITIALIZED";
    break;
  case 0x000011D1:
    ans = L"ERROR_VSM_DMA_PROTECTION_NOT_IN_USE";
    break;
  case 0x000011DA:
    ans = L"ERROR_PLATFORM_MANIFEST_NOT_AUTHORIZED";
    break;
  case 0x000011DB:
    ans = L"ERROR_PLATFORM_MANIFEST_INVALID";
    break;
  case 0x000011DC:
    ans = L"ERROR_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED";
    break;
  case 0x000011DD:
    ans = L"ERROR_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED";
    break;
  case 0x000011DE:
    ans = L"ERROR_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND";
    break;
  case 0x000011DF:
    ans = L"ERROR_PLATFORM_MANIFEST_NOT_ACTIVE";
    break;
  case 0x000011E0:
    ans = L"ERROR_PLATFORM_MANIFEST_NOT_SIGNED";
    break;
  case 0x00001389:
    ans = L"ERROR_DEPENDENT_RESOURCE_EXISTS";
    break;
  case 0x0000138A:
    ans = L"ERROR_DEPENDENCY_NOT_FOUND";
    break;
  case 0x0000138B:
    ans = L"ERROR_DEPENDENCY_ALREADY_EXISTS";
    break;
  case 0x0000138C:
    ans = L"ERROR_RESOURCE_NOT_ONLINE";
    break;
  case 0x0000138D:
    ans = L"ERROR_HOST_NODE_NOT_AVAILABLE";
    break;
  case 0x0000138E:
    ans = L"ERROR_RESOURCE_NOT_AVAILABLE";
    break;
  case 0x0000138F:
    ans = L"ERROR_RESOURCE_NOT_FOUND";
    break;
  case 0x00001390:
    ans = L"ERROR_SHUTDOWN_CLUSTER";
    break;
  case 0x00001391:
    ans = L"ERROR_CANT_EVICT_ACTIVE_NODE";
    break;
  case 0x00001392:
    ans = L"ERROR_OBJECT_ALREADY_EXISTS";
    break;
  case 0x00001393:
    ans = L"ERROR_OBJECT_IN_LIST";
    break;
  case 0x00001394:
    ans = L"ERROR_GROUP_NOT_AVAILABLE";
    break;
  case 0x00001395:
    ans = L"ERROR_GROUP_NOT_FOUND";
    break;
  case 0x00001396:
    ans = L"ERROR_GROUP_NOT_ONLINE";
    break;
  case 0x00001397:
    ans = L"ERROR_HOST_NODE_NOT_RESOURCE_OWNER";
    break;
  case 0x00001398:
    ans = L"ERROR_HOST_NODE_NOT_GROUP_OWNER";
    break;
  case 0x00001399:
    ans = L"ERROR_RESMON_CREATE_FAILED";
    break;
  case 0x0000139A:
    ans = L"ERROR_RESMON_ONLINE_FAILED";
    break;
  case 0x0000139B:
    ans = L"ERROR_RESOURCE_ONLINE";
    break;
  case 0x0000139C:
    ans = L"ERROR_QUORUM_RESOURCE";
    break;
  case 0x0000139D:
    ans = L"ERROR_NOT_QUORUM_CAPABLE";
    break;
  case 0x0000139E:
    ans = L"ERROR_CLUSTER_SHUTTING_DOWN";
    break;
  case 0x0000139F:
    ans = L"ERROR_INVALID_STATE";
    break;
  case 0x000013A0:
    ans = L"ERROR_RESOURCE_PROPERTIES_STORED";
    break;
  case 0x000013A1:
    ans = L"ERROR_NOT_QUORUM_CLASS";
    break;
  case 0x000013A2:
    ans = L"ERROR_CORE_RESOURCE";
    break;
  case 0x000013A3:
    ans = L"ERROR_QUORUM_RESOURCE_ONLINE_FAILED";
    break;
  case 0x000013A4:
    ans = L"ERROR_QUORUMLOG_OPEN_FAILED";
    break;
  case 0x000013A5:
    ans = L"ERROR_CLUSTERLOG_CORRUPT";
    break;
  case 0x000013A6:
    ans = L"ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE";
    break;
  case 0x000013A7:
    ans = L"ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE";
    break;
  case 0x000013A8:
    ans = L"ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND";
    break;
  case 0x000013A9:
    ans = L"ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE";
    break;
  case 0x000013AA:
    ans = L"ERROR_QUORUM_OWNER_ALIVE";
    break;
  case 0x000013AB:
    ans = L"ERROR_NETWORK_NOT_AVAILABLE";
    break;
  case 0x000013AC:
    ans = L"ERROR_NODE_NOT_AVAILABLE";
    break;
  case 0x000013AD:
    ans = L"ERROR_ALL_NODES_NOT_AVAILABLE";
    break;
  case 0x000013AE:
    ans = L"ERROR_RESOURCE_FAILED";
    break;
  case 0x000013AF:
    ans = L"ERROR_CLUSTER_INVALID_NODE";
    break;
  case 0x000013B0:
    ans = L"ERROR_CLUSTER_NODE_EXISTS";
    break;
  case 0x000013B1:
    ans = L"ERROR_CLUSTER_JOIN_IN_PROGRESS";
    break;
  case 0x000013B2:
    ans = L"ERROR_CLUSTER_NODE_NOT_FOUND";
    break;
  case 0x000013B3:
    ans = L"ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND";
    break;
  case 0x000013B4:
    ans = L"ERROR_CLUSTER_NETWORK_EXISTS";
    break;
  case 0x000013B5:
    ans = L"ERROR_CLUSTER_NETWORK_NOT_FOUND";
    break;
  case 0x000013B6:
    ans = L"ERROR_CLUSTER_NETINTERFACE_EXISTS";
    break;
  case 0x000013B7:
    ans = L"ERROR_CLUSTER_NETINTERFACE_NOT_FOUND";
    break;
  case 0x000013B8:
    ans = L"ERROR_CLUSTER_INVALID_REQUEST";
    break;
  case 0x000013B9:
    ans = L"ERROR_CLUSTER_INVALID_NETWORK_PROVIDER";
    break;
  case 0x000013BA:
    ans = L"ERROR_CLUSTER_NODE_DOWN";
    break;
  case 0x000013BB:
    ans = L"ERROR_CLUSTER_NODE_UNREACHABLE";
    break;
  case 0x000013BC:
    ans = L"ERROR_CLUSTER_NODE_NOT_MEMBER";
    break;
  case 0x000013BD:
    ans = L"ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS";
    break;
  case 0x000013BE:
    ans = L"ERROR_CLUSTER_INVALID_NETWORK";
    break;
  case 0x000013C0:
    ans = L"ERROR_CLUSTER_NODE_UP";
    break;
  case 0x000013C1:
    ans = L"ERROR_CLUSTER_IPADDR_IN_USE";
    break;
  case 0x000013C2:
    ans = L"ERROR_CLUSTER_NODE_NOT_PAUSED";
    break;
  case 0x000013C3:
    ans = L"ERROR_CLUSTER_NO_SECURITY_CONTEXT";
    break;
  case 0x000013C4:
    ans = L"ERROR_CLUSTER_NETWORK_NOT_INTERNAL";
    break;
  case 0x000013C5:
    ans = L"ERROR_CLUSTER_NODE_ALREADY_UP";
    break;
  case 0x000013C6:
    ans = L"ERROR_CLUSTER_NODE_ALREADY_DOWN";
    break;
  case 0x000013C7:
    ans = L"ERROR_CLUSTER_NETWORK_ALREADY_ONLINE";
    break;
  case 0x000013C8:
    ans = L"ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE";
    break;
  case 0x000013C9:
    ans = L"ERROR_CLUSTER_NODE_ALREADY_MEMBER";
    break;
  case 0x000013CA:
    ans = L"ERROR_CLUSTER_LAST_INTERNAL_NETWORK";
    break;
  case 0x000013CB:
    ans = L"ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS";
    break;
  case 0x000013CC:
    ans = L"ERROR_INVALID_OPERATION_ON_QUORUM";
    break;
  case 0x000013CD:
    ans = L"ERROR_DEPENDENCY_NOT_ALLOWED";
    break;
  case 0x000013CE:
    ans = L"ERROR_CLUSTER_NODE_PAUSED";
    break;
  case 0x000013CF:
    ans = L"ERROR_NODE_CANT_HOST_RESOURCE";
    break;
  case 0x000013D0:
    ans = L"ERROR_CLUSTER_NODE_NOT_READY";
    break;
  case 0x000013D1:
    ans = L"ERROR_CLUSTER_NODE_SHUTTING_DOWN";
    break;
  case 0x000013D2:
    ans = L"ERROR_CLUSTER_JOIN_ABORTED";
    break;
  case 0x000013D3:
    ans = L"ERROR_CLUSTER_INCOMPATIBLE_VERSIONS";
    break;
  case 0x000013D4:
    ans = L"ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED";
    break;
  case 0x000013D5:
    ans = L"ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED";
    break;
  case 0x000013D6:
    ans = L"ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND";
    break;
  case 0x000013D7:
    ans = L"ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED";
    break;
  case 0x000013D8:
    ans = L"ERROR_CLUSTER_RESNAME_NOT_FOUND";
    break;
  case 0x000013D9:
    ans = L"ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED";
    break;
  case 0x000013DA:
    ans = L"ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST";
    break;
  case 0x000013DB:
    ans = L"ERROR_CLUSTER_DATABASE_SEQMISMATCH";
    break;
  case 0x000013DC:
    ans = L"ERROR_RESMON_INVALID_STATE";
    break;
  case 0x000013DD:
    ans = L"ERROR_CLUSTER_GUM_NOT_LOCKER";
    break;
  case 0x000013DE:
    ans = L"ERROR_QUORUM_DISK_NOT_FOUND";
    break;
  case 0x000013DF:
    ans = L"ERROR_DATABASE_BACKUP_CORRUPT";
    break;
  case 0x000013E0:
    ans = L"ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT";
    break;
  case 0x000013E1:
    ans = L"ERROR_RESOURCE_PROPERTY_UNCHANGEABLE";
    break;
  case 0x000013E2:
    ans = L"ERROR_NO_ADMIN_ACCESS_POINT";
    break;
  case 0x00001702:
    ans = L"ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE";
    break;
  case 0x00001703:
    ans = L"ERROR_CLUSTER_QUORUMLOG_NOT_FOUND";
    break;
  case 0x00001704:
    ans = L"ERROR_CLUSTER_MEMBERSHIP_HALT";
    break;
  case 0x00001705:
    ans = L"ERROR_CLUSTER_INSTANCE_ID_MISMATCH";
    break;
  case 0x00001706:
    ans = L"ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP";
    break;
  case 0x00001707:
    ans = L"ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH";
    break;
  case 0x00001708:
    ans = L"ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP";
    break;
  case 0x00001709:
    ans = L"ERROR_CLUSTER_PARAMETER_MISMATCH";
    break;
  case 0x0000170A:
    ans = L"ERROR_NODE_CANNOT_BE_CLUSTERED";
    break;
  case 0x0000170B:
    ans = L"ERROR_CLUSTER_WRONG_OS_VERSION";
    break;
  case 0x0000170C:
    ans = L"ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME";
    break;
  case 0x0000170D:
    ans = L"ERROR_CLUSCFG_ALREADY_COMMITTED";
    break;
  case 0x0000170E:
    ans = L"ERROR_CLUSCFG_ROLLBACK_FAILED";
    break;
  case 0x0000170F:
    ans = L"ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT";
    break;
  case 0x00001710:
    ans = L"ERROR_CLUSTER_OLD_VERSION";
    break;
  case 0x00001711:
    ans = L"ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME";
    break;
  case 0x00001712:
    ans = L"ERROR_CLUSTER_NO_NET_ADAPTERS";
    break;
  case 0x00001713:
    ans = L"ERROR_CLUSTER_POISONED";
    break;
  case 0x00001714:
    ans = L"ERROR_CLUSTER_GROUP_MOVING";
    break;
  case 0x00001715:
    ans = L"ERROR_CLUSTER_RESOURCE_TYPE_BUSY";
    break;
  case 0x00001716:
    ans = L"ERROR_RESOURCE_CALL_TIMED_OUT";
    break;
  case 0x00001717:
    ans = L"ERROR_INVALID_CLUSTER_IPV6_ADDRESS";
    break;
  case 0x00001718:
    ans = L"ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION";
    break;
  case 0x00001719:
    ans = L"ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS";
    break;
  case 0x0000171A:
    ans = L"ERROR_CLUSTER_PARTIAL_SEND";
    break;
  case 0x0000171B:
    ans = L"ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION";
    break;
  case 0x0000171C:
    ans = L"ERROR_CLUSTER_INVALID_STRING_TERMINATION";
    break;
  case 0x0000171D:
    ans = L"ERROR_CLUSTER_INVALID_STRING_FORMAT";
    break;
  case 0x0000171E:
    ans = L"ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS";
    break;
  case 0x0000171F:
    ans = L"ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS";
    break;
  case 0x00001720:
    ans = L"ERROR_CLUSTER_NULL_DATA";
    break;
  case 0x00001721:
    ans = L"ERROR_CLUSTER_PARTIAL_READ";
    break;
  case 0x00001722:
    ans = L"ERROR_CLUSTER_PARTIAL_WRITE";
    break;
  case 0x00001723:
    ans = L"ERROR_CLUSTER_CANT_DESERIALIZE_DATA";
    break;
  case 0x00001724:
    ans = L"ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT";
    break;
  case 0x00001725:
    ans = L"ERROR_CLUSTER_NO_QUORUM";
    break;
  case 0x00001726:
    ans = L"ERROR_CLUSTER_INVALID_IPV6_NETWORK";
    break;
  case 0x00001727:
    ans = L"ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK";
    break;
  case 0x00001728:
    ans = L"ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP";
    break;
  case 0x00001729:
    ans = L"ERROR_DEPENDENCY_TREE_TOO_COMPLEX";
    break;
  case 0x0000172A:
    ans = L"ERROR_EXCEPTION_IN_RESOURCE_CALL";
    break;
  case 0x0000172B:
    ans = L"ERROR_CLUSTER_RHS_FAILED_INITIALIZATION";
    break;
  case 0x0000172C:
    ans = L"ERROR_CLUSTER_NOT_INSTALLED";
    break;
  case 0x0000172D:
    ans = L"ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE";
    break;
  case 0x0000172E:
    ans = L"ERROR_CLUSTER_MAX_NODES_IN_CLUSTER";
    break;
  case 0x0000172F:
    ans = L"ERROR_CLUSTER_TOO_MANY_NODES";
    break;
  case 0x00001730:
    ans = L"ERROR_CLUSTER_OBJECT_ALREADY_USED";
    break;
  case 0x00001731:
    ans = L"ERROR_NONCORE_GROUPS_FOUND";
    break;
  case 0x00001732:
    ans = L"ERROR_FILE_SHARE_RESOURCE_CONFLICT";
    break;
  case 0x00001733:
    ans = L"ERROR_CLUSTER_EVICT_INVALID_REQUEST";
    break;
  case 0x00001734:
    ans = L"ERROR_CLUSTER_SINGLETON_RESOURCE";
    break;
  case 0x00001735:
    ans = L"ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE";
    break;
  case 0x00001736:
    ans = L"ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED";
    break;
  case 0x00001737:
    ans = L"ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR";
    break;
  case 0x00001738:
    ans = L"ERROR_CLUSTER_GROUP_BUSY";
    break;
  case 0x00001739:
    ans = L"ERROR_CLUSTER_NOT_SHARED_VOLUME";
    break;
  case 0x0000173A:
    ans = L"ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR";
    break;
  case 0x0000173B:
    ans = L"ERROR_CLUSTER_SHARED_VOLUMES_IN_USE";
    break;
  case 0x0000173C:
    ans = L"ERROR_CLUSTER_USE_SHARED_VOLUMES_API";
    break;
  case 0x0000173D:
    ans = L"ERROR_CLUSTER_BACKUP_IN_PROGRESS";
    break;
  case 0x0000173E:
    ans = L"ERROR_NON_CSV_PATH";
    break;
  case 0x0000173F:
    ans = L"ERROR_CSV_VOLUME_NOT_LOCAL";
    break;
  case 0x00001740:
    ans = L"ERROR_CLUSTER_WATCHDOG_TERMINATING";
    break;
  case 0x00001741:
    ans = L"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_INCOMPATIBLE_NODES";
    break;
  case 0x00001742:
    ans = L"ERROR_CLUSTER_INVALID_NODE_WEIGHT";
    break;
  case 0x00001743:
    ans = L"ERROR_CLUSTER_RESOURCE_VETOED_CALL";
    break;
  case 0x00001744:
    ans = L"ERROR_RESMON_SYSTEM_RESOURCES_LACKING";
    break;
  case 0x00001745:
    ans = L"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_DESTINATION";
    break;
  case 0x00001746:
    ans = L"ERROR_CLUSTER_RESOURCE_VETOED_MOVE_NOT_ENOUGH_RESOURCES_ON_SOURCE";
    break;
  case 0x00001747:
    ans = L"ERROR_CLUSTER_GROUP_QUEUED";
    break;
  case 0x00001748:
    ans = L"ERROR_CLUSTER_RESOURCE_LOCKED_STATUS";
    break;
  case 0x00001749:
    ans = L"ERROR_CLUSTER_SHARED_VOLUME_FAILOVER_NOT_ALLOWED";
    break;
  case 0x0000174A:
    ans = L"ERROR_CLUSTER_NODE_DRAIN_IN_PROGRESS";
    break;
  case 0x0000174B:
    ans = L"ERROR_CLUSTER_DISK_NOT_CONNECTED";
    break;
  case 0x0000174C:
    ans = L"ERROR_DISK_NOT_CSV_CAPABLE";
    break;
  case 0x0000174D:
    ans = L"ERROR_RESOURCE_NOT_IN_AVAILABLE_STORAGE";
    break;
  case 0x0000174E:
    ans = L"ERROR_CLUSTER_SHARED_VOLUME_REDIRECTED";
    break;
  case 0x0000174F:
    ans = L"ERROR_CLUSTER_SHARED_VOLUME_NOT_REDIRECTED";
    break;
  case 0x00001750:
    ans = L"ERROR_CLUSTER_CANNOT_RETURN_PROPERTIES";
    break;
  case 0x00001751:
    ans = L"ERROR_CLUSTER_RESOURCE_CONTAINS_UNSUPPORTED_DIFF_AREA_FOR_SHARED_VOLUMES";
    break;
  case 0x00001752:
    ans = L"ERROR_CLUSTER_RESOURCE_IS_IN_MAINTENANCE_MODE";
    break;
  case 0x00001753:
    ans = L"ERROR_CLUSTER_AFFINITY_CONFLICT";
    break;
  case 0x00001754:
    ans = L"ERROR_CLUSTER_RESOURCE_IS_REPLICA_VIRTUAL_MACHINE";
    break;
  case 0x00001755:
    ans = L"ERROR_CLUSTER_UPGRADE_INCOMPATIBLE_VERSIONS";
    break;
  case 0x00001756:
    ans = L"ERROR_CLUSTER_UPGRADE_FIX_QUORUM_NOT_SUPPORTED";
    break;
  case 0x00001757:
    ans = L"ERROR_CLUSTER_UPGRADE_RESTART_REQUIRED";
    break;
  case 0x00001758:
    ans = L"ERROR_CLUSTER_UPGRADE_IN_PROGRESS";
    break;
  case 0x00001759:
    ans = L"ERROR_CLUSTER_UPGRADE_INCOMPLETE";
    break;
  case 0x0000175A:
    ans = L"ERROR_CLUSTER_NODE_IN_GRACE_PERIOD";
    break;
  case 0x0000175B:
    ans = L"ERROR_CLUSTER_CSV_IO_PAUSE_TIMEOUT";
    break;
  case 0x0000175C:
    ans = L"ERROR_NODE_NOT_ACTIVE_CLUSTER_MEMBER";
    break;
  case 0x0000175D:
    ans = L"ERROR_CLUSTER_RESOURCE_NOT_MONITORED";
    break;
  case 0x0000175E:
    ans = L"ERROR_CLUSTER_RESOURCE_DOES_NOT_SUPPORT_UNMONITORED";
    break;
  case 0x0000175F:
    ans = L"ERROR_CLUSTER_RESOURCE_IS_REPLICATED";
    break;
  case 0x00001760:
    ans = L"ERROR_CLUSTER_NODE_ISOLATED";
    break;
  case 0x00001761:
    ans = L"ERROR_CLUSTER_NODE_QUARANTINED";
    break;
  case 0x00001762:
    ans = L"ERROR_CLUSTER_DATABASE_UPDATE_CONDITION_FAILED";
    break;
  case 0x00001763:
    ans = L"ERROR_CLUSTER_SPACE_DEGRADED";
    break;
  case 0x00001764:
    ans = L"ERROR_CLUSTER_TOKEN_DELEGATION_NOT_SUPPORTED";
    break;
  case 0x00001765:
    ans = L"ERROR_CLUSTER_CSV_INVALID_HANDLE";
    break;
  case 0x00001766:
    ans = L"ERROR_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR";
    break;
  case 0x00001767:
    ans = L"ERROR_GROUPSET_NOT_AVAILABLE";
    break;
  case 0x00001768:
    ans = L"ERROR_GROUPSET_NOT_FOUND";
    break;
  case 0x00001769:
    ans = L"ERROR_GROUPSET_CANT_PROVIDE";
    break;
  case 0x0000176A:
    ans = L"ERROR_CLUSTER_FAULT_DOMAIN_PARENT_NOT_FOUND";
    break;
  case 0x0000176B:
    ans = L"ERROR_CLUSTER_FAULT_DOMAIN_INVALID_HIERARCHY";
    break;
  case 0x0000176C:
    ans = L"ERROR_CLUSTER_FAULT_DOMAIN_FAILED_S2D_VALIDATION";
    break;
  case 0x0000176D:
    ans = L"ERROR_CLUSTER_FAULT_DOMAIN_S2D_CONNECTIVITY_LOSS";
    break;
  case 0x0000176E:
    ans = L"ERROR_CLUSTER_INVALID_INFRASTRUCTURE_FILESERVER_NAME";
    break;
  case 0x0000176F:
    ans = L"ERROR_CLUSTERSET_MANAGEMENT_CLUSTER_UNREACHABLE";
    break;
  case 0x00001770:
    ans = L"ERROR_ENCRYPTION_FAILED";
    break;
  case 0x00001771:
    ans = L"ERROR_DECRYPTION_FAILED";
    break;
  case 0x00001772:
    ans = L"ERROR_FILE_ENCRYPTED";
    break;
  case 0x00001773:
    ans = L"ERROR_NO_RECOVERY_POLICY";
    break;
  case 0x00001774:
    ans = L"ERROR_NO_EFS";
    break;
  case 0x00001775:
    ans = L"ERROR_WRONG_EFS";
    break;
  case 0x00001776:
    ans = L"ERROR_NO_USER_KEYS";
    break;
  case 0x00001777:
    ans = L"ERROR_FILE_NOT_ENCRYPTED";
    break;
  case 0x00001778:
    ans = L"ERROR_NOT_EXPORT_FORMAT";
    break;
  case 0x00001779:
    ans = L"ERROR_FILE_READ_ONLY";
    break;
  case 0x0000177A:
    ans = L"ERROR_DIR_EFS_DISALLOWED";
    break;
  case 0x0000177B:
    ans = L"ERROR_EFS_SERVER_NOT_TRUSTED";
    break;
  case 0x0000177C:
    ans = L"ERROR_BAD_RECOVERY_POLICY";
    break;
  case 0x0000177D:
    ans = L"ERROR_EFS_ALG_BLOB_TOO_BIG";
    break;
  case 0x0000177E:
    ans = L"ERROR_VOLUME_NOT_SUPPORT_EFS";
    break;
  case 0x0000177F:
    ans = L"ERROR_EFS_DISABLED";
    break;
  case 0x00001780:
    ans = L"ERROR_EFS_VERSION_NOT_SUPPORT";
    break;
  case 0x00001781:
    ans = L"ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE";
    break;
  case 0x00001782:
    ans = L"ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER";
    break;
  case 0x00001783:
    ans = L"ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE";
    break;
  case 0x00001784:
    ans = L"ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE";
    break;
  case 0x00001785:
    ans = L"ERROR_CS_ENCRYPTION_FILE_NOT_CSE";
    break;
  case 0x00001786:
    ans = L"ERROR_ENCRYPTION_POLICY_DENIES_OPERATION";
    break;
  case 0x000017E6:
    ans = L"ERROR_NO_BROWSER_SERVERS_FOUND";
    break;
  case 0x00001838:
    ans = L"SCHED_E_SERVICE_NOT_LOCALSYSTEM";
    break;
  case 0x000019C8:
    ans = L"ERROR_LOG_SECTOR_INVALID";
    break;
  case 0x000019C9:
    ans = L"ERROR_LOG_SECTOR_PARITY_INVALID";
    break;
  case 0x000019CA:
    ans = L"ERROR_LOG_SECTOR_REMAPPED";
    break;
  case 0x000019CB:
    ans = L"ERROR_LOG_BLOCK_INCOMPLETE";
    break;
  case 0x000019CC:
    ans = L"ERROR_LOG_INVALID_RANGE";
    break;
  case 0x000019CD:
    ans = L"ERROR_LOG_BLOCKS_EXHAUSTED";
    break;
  case 0x000019CE:
    ans = L"ERROR_LOG_READ_CONTEXT_INVALID";
    break;
  case 0x000019CF:
    ans = L"ERROR_LOG_RESTART_INVALID";
    break;
  case 0x000019D0:
    ans = L"ERROR_LOG_BLOCK_VERSION";
    break;
  case 0x000019D1:
    ans = L"ERROR_LOG_BLOCK_INVALID";
    break;
  case 0x000019D2:
    ans = L"ERROR_LOG_READ_MODE_INVALID";
    break;
  case 0x000019D3:
    ans = L"ERROR_LOG_NO_RESTART";
    break;
  case 0x000019D4:
    ans = L"ERROR_LOG_METADATA_CORRUPT";
    break;
  case 0x000019D5:
    ans = L"ERROR_LOG_METADATA_INVALID";
    break;
  case 0x000019D6:
    ans = L"ERROR_LOG_METADATA_INCONSISTENT";
    break;
  case 0x000019D7:
    ans = L"ERROR_LOG_RESERVATION_INVALID";
    break;
  case 0x000019D8:
    ans = L"ERROR_LOG_CANT_DELETE";
    break;
  case 0x000019D9:
    ans = L"ERROR_LOG_CONTAINER_LIMIT_EXCEEDED";
    break;
  case 0x000019DA:
    ans = L"ERROR_LOG_START_OF_LOG";
    break;
  case 0x000019DB:
    ans = L"ERROR_LOG_POLICY_ALREADY_INSTALLED";
    break;
  case 0x000019DC:
    ans = L"ERROR_LOG_POLICY_NOT_INSTALLED";
    break;
  case 0x000019DD:
    ans = L"ERROR_LOG_POLICY_INVALID";
    break;
  case 0x000019DE:
    ans = L"ERROR_LOG_POLICY_CONFLICT";
    break;
  case 0x000019DF:
    ans = L"ERROR_LOG_PINNED_ARCHIVE_TAIL";
    break;
  case 0x000019E0:
    ans = L"ERROR_LOG_RECORD_NONEXISTENT";
    break;
  case 0x000019E1:
    ans = L"ERROR_LOG_RECORDS_RESERVED_INVALID";
    break;
  case 0x000019E2:
    ans = L"ERROR_LOG_SPACE_RESERVED_INVALID";
    break;
  case 0x000019E3:
    ans = L"ERROR_LOG_TAIL_INVALID";
    break;
  case 0x000019E4:
    ans = L"ERROR_LOG_FULL";
    break;
  case 0x000019E5:
    ans = L"ERROR_COULD_NOT_RESIZE_LOG";
    break;
  case 0x000019E6:
    ans = L"ERROR_LOG_MULTIPLEXED";
    break;
  case 0x000019E7:
    ans = L"ERROR_LOG_DEDICATED";
    break;
  case 0x000019E8:
    ans = L"ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS";
    break;
  case 0x000019E9:
    ans = L"ERROR_LOG_ARCHIVE_IN_PROGRESS";
    break;
  case 0x000019EA:
    ans = L"ERROR_LOG_EPHEMERAL";
    break;
  case 0x000019EB:
    ans = L"ERROR_LOG_NOT_ENOUGH_CONTAINERS";
    break;
  case 0x000019EC:
    ans = L"ERROR_LOG_CLIENT_ALREADY_REGISTERED";
    break;
  case 0x000019ED:
    ans = L"ERROR_LOG_CLIENT_NOT_REGISTERED";
    break;
  case 0x000019EE:
    ans = L"ERROR_LOG_FULL_HANDLER_IN_PROGRESS";
    break;
  case 0x000019EF:
    ans = L"ERROR_LOG_CONTAINER_READ_FAILED";
    break;
  case 0x000019F0:
    ans = L"ERROR_LOG_CONTAINER_WRITE_FAILED";
    break;
  case 0x000019F1:
    ans = L"ERROR_LOG_CONTAINER_OPEN_FAILED";
    break;
  case 0x000019F2:
    ans = L"ERROR_LOG_CONTAINER_STATE_INVALID";
    break;
  case 0x000019F3:
    ans = L"ERROR_LOG_STATE_INVALID";
    break;
  case 0x000019F4:
    ans = L"ERROR_LOG_PINNED";
    break;
  case 0x000019F5:
    ans = L"ERROR_LOG_METADATA_FLUSH_FAILED";
    break;
  case 0x000019F6:
    ans = L"ERROR_LOG_INCONSISTENT_SECURITY";
    break;
  case 0x000019F7:
    ans = L"ERROR_LOG_APPENDED_FLUSH_FAILED";
    break;
  case 0x000019F8:
    ans = L"ERROR_LOG_PINNED_RESERVATION";
    break;
  case 0x00001A2C:
    ans = L"ERROR_INVALID_TRANSACTION";
    break;
  case 0x00001A2D:
    ans = L"ERROR_TRANSACTION_NOT_ACTIVE";
    break;
  case 0x00001A2E:
    ans = L"ERROR_TRANSACTION_REQUEST_NOT_VALID";
    break;
  case 0x00001A2F:
    ans = L"ERROR_TRANSACTION_NOT_REQUESTED";
    break;
  case 0x00001A30:
    ans = L"ERROR_TRANSACTION_ALREADY_ABORTED";
    break;
  case 0x00001A31:
    ans = L"ERROR_TRANSACTION_ALREADY_COMMITTED";
    break;
  case 0x00001A32:
    ans = L"ERROR_TM_INITIALIZATION_FAILED";
    break;
  case 0x00001A33:
    ans = L"ERROR_RESOURCEMANAGER_READ_ONLY";
    break;
  case 0x00001A34:
    ans = L"ERROR_TRANSACTION_NOT_JOINED";
    break;
  case 0x00001A35:
    ans = L"ERROR_TRANSACTION_SUPERIOR_EXISTS";
    break;
  case 0x00001A36:
    ans = L"ERROR_CRM_PROTOCOL_ALREADY_EXISTS";
    break;
  case 0x00001A37:
    ans = L"ERROR_TRANSACTION_PROPAGATION_FAILED";
    break;
  case 0x00001A38:
    ans = L"ERROR_CRM_PROTOCOL_NOT_FOUND";
    break;
  case 0x00001A39:
    ans = L"ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER";
    break;
  case 0x00001A3A:
    ans = L"ERROR_CURRENT_TRANSACTION_NOT_VALID";
    break;
  case 0x00001A3B:
    ans = L"ERROR_TRANSACTION_NOT_FOUND";
    break;
  case 0x00001A3C:
    ans = L"ERROR_RESOURCEMANAGER_NOT_FOUND";
    break;
  case 0x00001A3D:
    ans = L"ERROR_ENLISTMENT_NOT_FOUND";
    break;
  case 0x00001A3E:
    ans = L"ERROR_TRANSACTIONMANAGER_NOT_FOUND";
    break;
  case 0x00001A3F:
    ans = L"ERROR_TRANSACTIONMANAGER_NOT_ONLINE";
    break;
  case 0x00001A40:
    ans = L"ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION";
    break;
  case 0x00001A41:
    ans = L"ERROR_TRANSACTION_NOT_ROOT";
    break;
  case 0x00001A42:
    ans = L"ERROR_TRANSACTION_OBJECT_EXPIRED";
    break;
  case 0x00001A43:
    ans = L"ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED";
    break;
  case 0x00001A44:
    ans = L"ERROR_TRANSACTION_RECORD_TOO_LONG";
    break;
  case 0x00001A45:
    ans = L"ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED";
    break;
  case 0x00001A46:
    ans = L"ERROR_TRANSACTION_INTEGRITY_VIOLATED";
    break;
  case 0x00001A47:
    ans = L"ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH";
    break;
  case 0x00001A48:
    ans = L"ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT";
    break;
  case 0x00001A49:
    ans = L"ERROR_TRANSACTION_MUST_WRITETHROUGH";
    break;
  case 0x00001A4A:
    ans = L"ERROR_TRANSACTION_NO_SUPERIOR";
    break;
  case 0x00001A4B:
    ans = L"ERROR_HEURISTIC_DAMAGE_POSSIBLE";
    break;
  case 0x00001A90:
    ans = L"ERROR_TRANSACTIONAL_CONFLICT";
    break;
  case 0x00001A91:
    ans = L"ERROR_RM_NOT_ACTIVE";
    break;
  case 0x00001A92:
    ans = L"ERROR_RM_METADATA_CORRUPT";
    break;
  case 0x00001A93:
    ans = L"ERROR_DIRECTORY_NOT_RM";
    break;
  case 0x00001A95:
    ans = L"ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE";
    break;
  case 0x00001A96:
    ans = L"ERROR_LOG_RESIZE_INVALID_SIZE";
    break;
  case 0x00001A97:
    ans = L"ERROR_OBJECT_NO_LONGER_EXISTS";
    break;
  case 0x00001A98:
    ans = L"ERROR_STREAM_MINIVERSION_NOT_FOUND";
    break;
  case 0x00001A99:
    ans = L"ERROR_STREAM_MINIVERSION_NOT_VALID";
    break;
  case 0x00001A9A:
    ans = L"ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION";
    break;
  case 0x00001A9B:
    ans = L"ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT";
    break;
  case 0x00001A9C:
    ans = L"ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS";
    break;
  case 0x00001A9E:
    ans = L"ERROR_REMOTE_FILE_VERSION_MISMATCH";
    break;
  case 0x00001A9F:
    ans = L"ERROR_HANDLE_NO_LONGER_VALID";
    break;
  case 0x00001AA0:
    ans = L"ERROR_NO_TXF_METADATA";
    break;
  case 0x00001AA1:
    ans = L"ERROR_LOG_CORRUPTION_DETECTED";
    break;
  case 0x00001AA2:
    ans = L"ERROR_CANT_RECOVER_WITH_HANDLE_OPEN";
    break;
  case 0x00001AA3:
    ans = L"ERROR_RM_DISCONNECTED";
    break;
  case 0x00001AA4:
    ans = L"ERROR_ENLISTMENT_NOT_SUPERIOR";
    break;
  case 0x00001AA5:
    ans = L"ERROR_RECOVERY_NOT_NEEDED";
    break;
  case 0x00001AA6:
    ans = L"ERROR_RM_ALREADY_STARTED";
    break;
  case 0x00001AA7:
    ans = L"ERROR_FILE_IDENTITY_NOT_PERSISTENT";
    break;
  case 0x00001AA8:
    ans = L"ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY";
    break;
  case 0x00001AA9:
    ans = L"ERROR_CANT_CROSS_RM_BOUNDARY";
    break;
  case 0x00001AAA:
    ans = L"ERROR_TXF_DIR_NOT_EMPTY";
    break;
  case 0x00001AAB:
    ans = L"ERROR_INDOUBT_TRANSACTIONS_EXIST";
    break;
  case 0x00001AAC:
    ans = L"ERROR_TM_VOLATILE";
    break;
  case 0x00001AAD:
    ans = L"ERROR_ROLLBACK_TIMER_EXPIRED";
    break;
  case 0x00001AAE:
    ans = L"ERROR_TXF_ATTRIBUTE_CORRUPT";
    break;
  case 0x00001AAF:
    ans = L"ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION";
    break;
  case 0x00001AB0:
    ans = L"ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED";
    break;
  case 0x00001AB1:
    ans = L"ERROR_LOG_GROWTH_FAILED";
    break;
  case 0x00001AB2:
    ans = L"ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE";
    break;
  case 0x00001AB3:
    ans = L"ERROR_TXF_METADATA_ALREADY_PRESENT";
    break;
  case 0x00001AB4:
    ans = L"ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET";
    break;
  case 0x00001AB5:
    ans = L"ERROR_TRANSACTION_REQUIRED_PROMOTION";
    break;
  case 0x00001AB6:
    ans = L"ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION";
    break;
  case 0x00001AB7:
    ans = L"ERROR_TRANSACTIONS_NOT_FROZEN";
    break;
  case 0x00001AB8:
    ans = L"ERROR_TRANSACTION_FREEZE_IN_PROGRESS";
    break;
  case 0x00001AB9:
    ans = L"ERROR_NOT_SNAPSHOT_VOLUME";
    break;
  case 0x00001ABA:
    ans = L"ERROR_NO_SAVEPOINT_WITH_OPEN_FILES";
    break;
  case 0x00001ABB:
    ans = L"ERROR_DATA_LOST_REPAIR";
    break;
  case 0x00001ABC:
    ans = L"ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION";
    break;
  case 0x00001ABD:
    ans = L"ERROR_TM_IDENTITY_MISMATCH";
    break;
  case 0x00001ABE:
    ans = L"ERROR_FLOATED_SECTION";
    break;
  case 0x00001ABF:
    ans = L"ERROR_CANNOT_ACCEPT_TRANSACTED_WORK";
    break;
  case 0x00001AC0:
    ans = L"ERROR_CANNOT_ABORT_TRANSACTIONS";
    break;
  case 0x00001AC1:
    ans = L"ERROR_BAD_CLUSTERS";
    break;
  case 0x00001AC2:
    ans = L"ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION";
    break;
  case 0x00001AC3:
    ans = L"ERROR_VOLUME_DIRTY";
    break;
  case 0x00001AC4:
    ans = L"ERROR_NO_LINK_TRACKING_IN_TRANSACTION";
    break;
  case 0x00001AC5:
    ans = L"ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION";
    break;
  case 0x00001AC6:
    ans = L"ERROR_EXPIRED_HANDLE";
    break;
  case 0x00001AC7:
    ans = L"ERROR_TRANSACTION_NOT_ENLISTED";
    break;
  case 0x00001B59:
    ans = L"ERROR_CTX_WINSTATION_NAME_INVALID";
    break;
  case 0x00001B5A:
    ans = L"ERROR_CTX_INVALID_PD";
    break;
  case 0x00001B5B:
    ans = L"ERROR_CTX_PD_NOT_FOUND";
    break;
  case 0x00001B5C:
    ans = L"ERROR_CTX_WD_NOT_FOUND";
    break;
  case 0x00001B5D:
    ans = L"ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY";
    break;
  case 0x00001B5E:
    ans = L"ERROR_CTX_SERVICE_NAME_COLLISION";
    break;
  case 0x00001B5F:
    ans = L"ERROR_CTX_CLOSE_PENDING";
    break;
  case 0x00001B60:
    ans = L"ERROR_CTX_NO_OUTBUF";
    break;
  case 0x00001B61:
    ans = L"ERROR_CTX_MODEM_INF_NOT_FOUND";
    break;
  case 0x00001B62:
    ans = L"ERROR_CTX_INVALID_MODEMNAME";
    break;
  case 0x00001B63:
    ans = L"ERROR_CTX_MODEM_RESPONSE_ERROR";
    break;
  case 0x00001B64:
    ans = L"ERROR_CTX_MODEM_RESPONSE_TIMEOUT";
    break;
  case 0x00001B65:
    ans = L"ERROR_CTX_MODEM_RESPONSE_NO_CARRIER";
    break;
  case 0x00001B66:
    ans = L"ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE";
    break;
  case 0x00001B67:
    ans = L"ERROR_CTX_MODEM_RESPONSE_BUSY";
    break;
  case 0x00001B68:
    ans = L"ERROR_CTX_MODEM_RESPONSE_VOICE";
    break;
  case 0x00001B69:
    ans = L"ERROR_CTX_TD_ERROR";
    break;
  case 0x00001B6E:
    ans = L"ERROR_CTX_WINSTATION_NOT_FOUND";
    break;
  case 0x00001B6F:
    ans = L"ERROR_CTX_WINSTATION_ALREADY_EXISTS";
    break;
  case 0x00001B70:
    ans = L"ERROR_CTX_WINSTATION_BUSY";
    break;
  case 0x00001B71:
    ans = L"ERROR_CTX_BAD_VIDEO_MODE";
    break;
  case 0x00001B7B:
    ans = L"ERROR_CTX_GRAPHICS_INVALID";
    break;
  case 0x00001B7D:
    ans = L"ERROR_CTX_LOGON_DISABLED";
    break;
  case 0x00001B7E:
    ans = L"ERROR_CTX_NOT_CONSOLE";
    break;
  case 0x00001B80:
    ans = L"ERROR_CTX_CLIENT_QUERY_TIMEOUT";
    break;
  case 0x00001B81:
    ans = L"ERROR_CTX_CONSOLE_DISCONNECT";
    break;
  case 0x00001B82:
    ans = L"ERROR_CTX_CONSOLE_CONNECT";
    break;
  case 0x00001B84:
    ans = L"ERROR_CTX_SHADOW_DENIED";
    break;
  case 0x00001B85:
    ans = L"ERROR_CTX_WINSTATION_ACCESS_DENIED";
    break;
  case 0x00001B89:
    ans = L"ERROR_CTX_INVALID_WD";
    break;
  case 0x00001B8A:
    ans = L"ERROR_CTX_SHADOW_INVALID";
    break;
  case 0x00001B8B:
    ans = L"ERROR_CTX_SHADOW_DISABLED";
    break;
  case 0x00001B8C:
    ans = L"ERROR_CTX_CLIENT_LICENSE_IN_USE";
    break;
  case 0x00001B8D:
    ans = L"ERROR_CTX_CLIENT_LICENSE_NOT_SET";
    break;
  case 0x00001B8E:
    ans = L"ERROR_CTX_LICENSE_NOT_AVAILABLE";
    break;
  case 0x00001B8F:
    ans = L"ERROR_CTX_LICENSE_CLIENT_INVALID";
    break;
  case 0x00001B90:
    ans = L"ERROR_CTX_LICENSE_EXPIRED";
    break;
  case 0x00001B91:
    ans = L"ERROR_CTX_SHADOW_NOT_RUNNING";
    break;
  case 0x00001B92:
    ans = L"ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE";
    break;
  case 0x00001B93:
    ans = L"ERROR_ACTIVATION_COUNT_EXCEEDED";
    break;
  case 0x00001B94:
    ans = L"ERROR_CTX_WINSTATIONS_DISABLED";
    break;
  case 0x00001B95:
    ans = L"ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED";
    break;
  case 0x00001B96:
    ans = L"ERROR_CTX_SESSION_IN_USE";
    break;
  case 0x00001B97:
    ans = L"ERROR_CTX_NO_FORCE_LOGOFF";
    break;
  case 0x00001B98:
    ans = L"ERROR_CTX_ACCOUNT_RESTRICTION";
    break;
  case 0x00001B99:
    ans = L"ERROR_RDP_PROTOCOL_ERROR";
    break;
  case 0x00001B9A:
    ans = L"ERROR_CTX_CDM_CONNECT";
    break;
  case 0x00001B9B:
    ans = L"ERROR_CTX_CDM_DISCONNECT";
    break;
  case 0x00001B9C:
    ans = L"ERROR_CTX_SECURITY_LAYER_ERROR";
    break;
  case 0x00001B9D:
    ans = L"ERROR_TS_INCOMPATIBLE_SESSIONS";
    break;
  case 0x00001B9E:
    ans = L"ERROR_TS_VIDEO_SUBSYSTEM_ERROR";
    break;
  case 0x00001F41:
    ans = L"FRS_ERR_INVALID_API_SEQUENCE";
    break;
  case 0x00001F42:
    ans = L"FRS_ERR_STARTING_SERVICE";
    break;
  case 0x00001F43:
    ans = L"FRS_ERR_STOPPING_SERVICE";
    break;
  case 0x00001F44:
    ans = L"FRS_ERR_INTERNAL_API";
    break;
  case 0x00001F45:
    ans = L"FRS_ERR_INTERNAL";
    break;
  case 0x00001F46:
    ans = L"FRS_ERR_SERVICE_COMM";
    break;
  case 0x00001F47:
    ans = L"FRS_ERR_INSUFFICIENT_PRIV";
    break;
  case 0x00001F48:
    ans = L"FRS_ERR_AUTHENTICATION";
    break;
  case 0x00001F49:
    ans = L"FRS_ERR_PARENT_INSUFFICIENT_PRIV";
    break;
  case 0x00001F4A:
    ans = L"FRS_ERR_PARENT_AUTHENTICATION";
    break;
  case 0x00001F4B:
    ans = L"FRS_ERR_CHILD_TO_PARENT_COMM";
    break;
  case 0x00001F4C:
    ans = L"FRS_ERR_PARENT_TO_CHILD_COMM";
    break;
  case 0x00001F4D:
    ans = L"FRS_ERR_SYSVOL_POPULATE";
    break;
  case 0x00001F4E:
    ans = L"FRS_ERR_SYSVOL_POPULATE_TIMEOUT";
    break;
  case 0x00001F4F:
    ans = L"FRS_ERR_SYSVOL_IS_BUSY";
    break;
  case 0x00001F50:
    ans = L"FRS_ERR_SYSVOL_DEMOTE";
    break;
  case 0x00001F51:
    ans = L"FRS_ERR_INVALID_SERVICE_PARAMETER";
    break;
  case 0x00002008:
    ans = L"ERROR_DS_NOT_INSTALLED";
    break;
  case 0x00002009:
    ans = L"ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY";
    break;
  case 0x0000200A:
    ans = L"ERROR_DS_NO_ATTRIBUTE_OR_VALUE";
    break;
  case 0x0000200B:
    ans = L"ERROR_DS_INVALID_ATTRIBUTE_SYNTAX";
    break;
  case 0x0000200C:
    ans = L"ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED";
    break;
  case 0x0000200D:
    ans = L"ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS";
    break;
  case 0x0000200E:
    ans = L"ERROR_DS_BUSY";
    break;
  case 0x0000200F:
    ans = L"ERROR_DS_UNAVAILABLE";
    break;
  case 0x00002010:
    ans = L"ERROR_DS_NO_RIDS_ALLOCATED";
    break;
  case 0x00002011:
    ans = L"ERROR_DS_NO_MORE_RIDS";
    break;
  case 0x00002012:
    ans = L"ERROR_DS_INCORRECT_ROLE_OWNER";
    break;
  case 0x00002013:
    ans = L"ERROR_DS_RIDMGR_INIT_ERROR";
    break;
  case 0x00002014:
    ans = L"ERROR_DS_OBJ_CLASS_VIOLATION";
    break;
  case 0x00002015:
    ans = L"ERROR_DS_CANT_ON_NON_LEAF";
    break;
  case 0x00002016:
    ans = L"ERROR_DS_CANT_ON_RDN";
    break;
  case 0x00002017:
    ans = L"ERROR_DS_CANT_MOD_OBJ_CLASS";
    break;
  case 0x00002018:
    ans = L"ERROR_DS_CROSS_DOM_MOVE_ERROR";
    break;
  case 0x00002019:
    ans = L"ERROR_DS_GC_NOT_AVAILABLE";
    break;
  case 0x0000201A:
    ans = L"ERROR_SHARED_POLICY";
    break;
  case 0x0000201B:
    ans = L"ERROR_POLICY_OBJECT_NOT_FOUND";
    break;
  case 0x0000201C:
    ans = L"ERROR_POLICY_ONLY_IN_DS";
    break;
  case 0x0000201D:
    ans = L"ERROR_PROMOTION_ACTIVE";
    break;
  case 0x0000201E:
    ans = L"ERROR_NO_PROMOTION_ACTIVE";
    break;
  case 0x00002020:
    ans = L"ERROR_DS_OPERATIONS_ERROR";
    break;
  case 0x00002021:
    ans = L"ERROR_DS_PROTOCOL_ERROR";
    break;
  case 0x00002022:
    ans = L"ERROR_DS_TIMELIMIT_EXCEEDED";
    break;
  case 0x00002023:
    ans = L"ERROR_DS_SIZELIMIT_EXCEEDED";
    break;
  case 0x00002024:
    ans = L"ERROR_DS_ADMIN_LIMIT_EXCEEDED";
    break;
  case 0x00002025:
    ans = L"ERROR_DS_COMPARE_FALSE";
    break;
  case 0x00002026:
    ans = L"ERROR_DS_COMPARE_TRUE";
    break;
  case 0x00002027:
    ans = L"ERROR_DS_AUTH_METHOD_NOT_SUPPORTED";
    break;
  case 0x00002028:
    ans = L"ERROR_DS_STRONG_AUTH_REQUIRED";
    break;
  case 0x00002029:
    ans = L"ERROR_DS_INAPPROPRIATE_AUTH";
    break;
  case 0x0000202A:
    ans = L"ERROR_DS_AUTH_UNKNOWN";
    break;
  case 0x0000202B:
    ans = L"ERROR_DS_REFERRAL";
    break;
  case 0x0000202C:
    ans = L"ERROR_DS_UNAVAILABLE_CRIT_EXTENSION";
    break;
  case 0x0000202D:
    ans = L"ERROR_DS_CONFIDENTIALITY_REQUIRED";
    break;
  case 0x0000202E:
    ans = L"ERROR_DS_INAPPROPRIATE_MATCHING";
    break;
  case 0x0000202F:
    ans = L"ERROR_DS_CONSTRAINT_VIOLATION";
    break;
  case 0x00002030:
    ans = L"ERROR_DS_NO_SUCH_OBJECT";
    break;
  case 0x00002031:
    ans = L"ERROR_DS_ALIAS_PROBLEM";
    break;
  case 0x00002032:
    ans = L"ERROR_DS_INVALID_DN_SYNTAX";
    break;
  case 0x00002033:
    ans = L"ERROR_DS_IS_LEAF";
    break;
  case 0x00002034:
    ans = L"ERROR_DS_ALIAS_DEREF_PROBLEM";
    break;
  case 0x00002035:
    ans = L"ERROR_DS_UNWILLING_TO_PERFORM";
    break;
  case 0x00002036:
    ans = L"ERROR_DS_LOOP_DETECT";
    break;
  case 0x00002037:
    ans = L"ERROR_DS_NAMING_VIOLATION";
    break;
  case 0x00002038:
    ans = L"ERROR_DS_OBJECT_RESULTS_TOO_LARGE";
    break;
  case 0x00002039:
    ans = L"ERROR_DS_AFFECTS_MULTIPLE_DSAS";
    break;
  case 0x0000203A:
    ans = L"ERROR_DS_SERVER_DOWN";
    break;
  case 0x0000203B:
    ans = L"ERROR_DS_LOCAL_ERROR";
    break;
  case 0x0000203C:
    ans = L"ERROR_DS_ENCODING_ERROR";
    break;
  case 0x0000203D:
    ans = L"ERROR_DS_DECODING_ERROR";
    break;
  case 0x0000203E:
    ans = L"ERROR_DS_FILTER_UNKNOWN";
    break;
  case 0x0000203F:
    ans = L"ERROR_DS_PARAM_ERROR";
    break;
  case 0x00002040:
    ans = L"ERROR_DS_NOT_SUPPORTED";
    break;
  case 0x00002041:
    ans = L"ERROR_DS_NO_RESULTS_RETURNED";
    break;
  case 0x00002042:
    ans = L"ERROR_DS_CONTROL_NOT_FOUND";
    break;
  case 0x00002043:
    ans = L"ERROR_DS_CLIENT_LOOP";
    break;
  case 0x00002044:
    ans = L"ERROR_DS_REFERRAL_LIMIT_EXCEEDED";
    break;
  case 0x00002045:
    ans = L"ERROR_DS_SORT_CONTROL_MISSING";
    break;
  case 0x00002046:
    ans = L"ERROR_DS_OFFSET_RANGE_ERROR";
    break;
  case 0x00002047:
    ans = L"ERROR_DS_RIDMGR_DISABLED";
    break;
  case 0x0000206D:
    ans = L"ERROR_DS_ROOT_MUST_BE_NC";
    break;
  case 0x0000206E:
    ans = L"ERROR_DS_ADD_REPLICA_INHIBITED";
    break;
  case 0x0000206F:
    ans = L"ERROR_DS_ATT_NOT_DEF_IN_SCHEMA";
    break;
  case 0x00002070:
    ans = L"ERROR_DS_MAX_OBJ_SIZE_EXCEEDED";
    break;
  case 0x00002071:
    ans = L"ERROR_DS_OBJ_STRING_NAME_EXISTS";
    break;
  case 0x00002072:
    ans = L"ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA";
    break;
  case 0x00002073:
    ans = L"ERROR_DS_RDN_DOESNT_MATCH_SCHEMA";
    break;
  case 0x00002074:
    ans = L"ERROR_DS_NO_REQUESTED_ATTS_FOUND";
    break;
  case 0x00002075:
    ans = L"ERROR_DS_USER_BUFFER_TO_SMALL";
    break;
  case 0x00002076:
    ans = L"ERROR_DS_ATT_IS_NOT_ON_OBJ";
    break;
  case 0x00002077:
    ans = L"ERROR_DS_ILLEGAL_MOD_OPERATION";
    break;
  case 0x00002078:
    ans = L"ERROR_DS_OBJ_TOO_LARGE";
    break;
  case 0x00002079:
    ans = L"ERROR_DS_BAD_INSTANCE_TYPE";
    break;
  case 0x0000207A:
    ans = L"ERROR_DS_MASTERDSA_REQUIRED";
    break;
  case 0x0000207B:
    ans = L"ERROR_DS_OBJECT_CLASS_REQUIRED";
    break;
  case 0x0000207C:
    ans = L"ERROR_DS_MISSING_REQUIRED_ATT";
    break;
  case 0x0000207D:
    ans = L"ERROR_DS_ATT_NOT_DEF_FOR_CLASS";
    break;
  case 0x0000207E:
    ans = L"ERROR_DS_ATT_ALREADY_EXISTS";
    break;
  case 0x00002080:
    ans = L"ERROR_DS_CANT_ADD_ATT_VALUES";
    break;
  case 0x00002081:
    ans = L"ERROR_DS_SINGLE_VALUE_CONSTRAINT";
    break;
  case 0x00002082:
    ans = L"ERROR_DS_RANGE_CONSTRAINT";
    break;
  case 0x00002083:
    ans = L"ERROR_DS_ATT_VAL_ALREADY_EXISTS";
    break;
  case 0x00002084:
    ans = L"ERROR_DS_CANT_REM_MISSING_ATT";
    break;
  case 0x00002085:
    ans = L"ERROR_DS_CANT_REM_MISSING_ATT_VAL";
    break;
  case 0x00002086:
    ans = L"ERROR_DS_ROOT_CANT_BE_SUBREF";
    break;
  case 0x00002087:
    ans = L"ERROR_DS_NO_CHAINING";
    break;
  case 0x00002088:
    ans = L"ERROR_DS_NO_CHAINED_EVAL";
    break;
  case 0x00002089:
    ans = L"ERROR_DS_NO_PARENT_OBJECT";
    break;
  case 0x0000208A:
    ans = L"ERROR_DS_PARENT_IS_AN_ALIAS";
    break;
  case 0x0000208B:
    ans = L"ERROR_DS_CANT_MIX_MASTER_AND_REPS";
    break;
  case 0x0000208C:
    ans = L"ERROR_DS_CHILDREN_EXIST";
    break;
  case 0x0000208D:
    ans = L"ERROR_DS_OBJ_NOT_FOUND";
    break;
  case 0x0000208E:
    ans = L"ERROR_DS_ALIASED_OBJ_MISSING";
    break;
  case 0x0000208F:
    ans = L"ERROR_DS_BAD_NAME_SYNTAX";
    break;
  case 0x00002090:
    ans = L"ERROR_DS_ALIAS_POINTS_TO_ALIAS";
    break;
  case 0x00002091:
    ans = L"ERROR_DS_CANT_DEREF_ALIAS";
    break;
  case 0x00002092:
    ans = L"ERROR_DS_OUT_OF_SCOPE";
    break;
  case 0x00002093:
    ans = L"ERROR_DS_OBJECT_BEING_REMOVED";
    break;
  case 0x00002094:
    ans = L"ERROR_DS_CANT_DELETE_DSA_OBJ";
    break;
  case 0x00002095:
    ans = L"ERROR_DS_GENERIC_ERROR";
    break;
  case 0x00002096:
    ans = L"ERROR_DS_DSA_MUST_BE_INT_MASTER";
    break;
  case 0x00002097:
    ans = L"ERROR_DS_CLASS_NOT_DSA";
    break;
  case 0x00002098:
    ans = L"ERROR_DS_INSUFF_ACCESS_RIGHTS";
    break;
  case 0x00002099:
    ans = L"ERROR_DS_ILLEGAL_SUPERIOR";
    break;
  case 0x0000209A:
    ans = L"ERROR_DS_ATTRIBUTE_OWNED_BY_SAM";
    break;
  case 0x0000209B:
    ans = L"ERROR_DS_NAME_TOO_MANY_PARTS";
    break;
  case 0x0000209C:
    ans = L"ERROR_DS_NAME_TOO_LONG";
    break;
  case 0x0000209D:
    ans = L"ERROR_DS_NAME_VALUE_TOO_LONG";
    break;
  case 0x0000209E:
    ans = L"ERROR_DS_NAME_UNPARSEABLE";
    break;
  case 0x0000209F:
    ans = L"ERROR_DS_NAME_TYPE_UNKNOWN";
    break;
  case 0x000020A0:
    ans = L"ERROR_DS_NOT_AN_OBJECT";
    break;
  case 0x000020A1:
    ans = L"ERROR_DS_SEC_DESC_TOO_SHORT";
    break;
  case 0x000020A2:
    ans = L"ERROR_DS_SEC_DESC_INVALID";
    break;
  case 0x000020A3:
    ans = L"ERROR_DS_NO_DELETED_NAME";
    break;
  case 0x000020A4:
    ans = L"ERROR_DS_SUBREF_MUST_HAVE_PARENT";
    break;
  case 0x000020A5:
    ans = L"ERROR_DS_NCNAME_MUST_BE_NC";
    break;
  case 0x000020A6:
    ans = L"ERROR_DS_CANT_ADD_SYSTEM_ONLY";
    break;
  case 0x000020A7:
    ans = L"ERROR_DS_CLASS_MUST_BE_CONCRETE";
    break;
  case 0x000020A8:
    ans = L"ERROR_DS_INVALID_DMD";
    break;
  case 0x000020A9:
    ans = L"ERROR_DS_OBJ_GUID_EXISTS";
    break;
  case 0x000020AA:
    ans = L"ERROR_DS_NOT_ON_BACKLINK";
    break;
  case 0x000020AB:
    ans = L"ERROR_DS_NO_CROSSREF_FOR_NC";
    break;
  case 0x000020AC:
    ans = L"ERROR_DS_SHUTTING_DOWN";
    break;
  case 0x000020AD:
    ans = L"ERROR_DS_UNKNOWN_OPERATION";
    break;
  case 0x000020AE:
    ans = L"ERROR_DS_INVALID_ROLE_OWNER";
    break;
  case 0x000020AF:
    ans = L"ERROR_DS_COULDNT_CONTACT_FSMO";
    break;
  case 0x000020B0:
    ans = L"ERROR_DS_CROSS_NC_DN_RENAME";
    break;
  case 0x000020B1:
    ans = L"ERROR_DS_CANT_MOD_SYSTEM_ONLY";
    break;
  case 0x000020B2:
    ans = L"ERROR_DS_REPLICATOR_ONLY";
    break;
  case 0x000020B3:
    ans = L"ERROR_DS_OBJ_CLASS_NOT_DEFINED";
    break;
  case 0x000020B4:
    ans = L"ERROR_DS_OBJ_CLASS_NOT_SUBCLASS";
    break;
  case 0x000020B5:
    ans = L"ERROR_DS_NAME_REFERENCE_INVALID";
    break;
  case 0x000020B6:
    ans = L"ERROR_DS_CROSS_REF_EXISTS";
    break;
  case 0x000020B7:
    ans = L"ERROR_DS_CANT_DEL_MASTER_CROSSREF";
    break;
  case 0x000020B8:
    ans = L"ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD";
    break;
  case 0x000020B9:
    ans = L"ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX";
    break;
  case 0x000020BA:
    ans = L"ERROR_DS_DUP_RDN";
    break;
  case 0x000020BB:
    ans = L"ERROR_DS_DUP_OID";
    break;
  case 0x000020BC:
    ans = L"ERROR_DS_DUP_MAPI_ID";
    break;
  case 0x000020BD:
    ans = L"ERROR_DS_DUP_SCHEMA_ID_GUID";
    break;
  case 0x000020BE:
    ans = L"ERROR_DS_DUP_LDAP_DISPLAY_NAME";
    break;
  case 0x000020BF:
    ans = L"ERROR_DS_SEMANTIC_ATT_TEST";
    break;
  case 0x000020C0:
    ans = L"ERROR_DS_SYNTAX_MISMATCH";
    break;
  case 0x000020C1:
    ans = L"ERROR_DS_EXISTS_IN_MUST_HAVE";
    break;
  case 0x000020C2:
    ans = L"ERROR_DS_EXISTS_IN_MAY_HAVE";
    break;
  case 0x000020C3:
    ans = L"ERROR_DS_NONEXISTENT_MAY_HAVE";
    break;
  case 0x000020C4:
    ans = L"ERROR_DS_NONEXISTENT_MUST_HAVE";
    break;
  case 0x000020C5:
    ans = L"ERROR_DS_AUX_CLS_TEST_FAIL";
    break;
  case 0x000020C6:
    ans = L"ERROR_DS_NONEXISTENT_POSS_SUP";
    break;
  case 0x000020C7:
    ans = L"ERROR_DS_SUB_CLS_TEST_FAIL";
    break;
  case 0x000020C8:
    ans = L"ERROR_DS_BAD_RDN_ATT_ID_SYNTAX";
    break;
  case 0x000020C9:
    ans = L"ERROR_DS_EXISTS_IN_AUX_CLS";
    break;
  case 0x000020CA:
    ans = L"ERROR_DS_EXISTS_IN_SUB_CLS";
    break;
  case 0x000020CB:
    ans = L"ERROR_DS_EXISTS_IN_POSS_SUP";
    break;
  case 0x000020CC:
    ans = L"ERROR_DS_RECALCSCHEMA_FAILED";
    break;
  case 0x000020CD:
    ans = L"ERROR_DS_TREE_DELETE_NOT_FINISHED";
    break;
  case 0x000020CE:
    ans = L"ERROR_DS_CANT_DELETE";
    break;
  case 0x000020CF:
    ans = L"ERROR_DS_ATT_SCHEMA_REQ_ID";
    break;
  case 0x000020D0:
    ans = L"ERROR_DS_BAD_ATT_SCHEMA_SYNTAX";
    break;
  case 0x000020D1:
    ans = L"ERROR_DS_CANT_CACHE_ATT";
    break;
  case 0x000020D2:
    ans = L"ERROR_DS_CANT_CACHE_CLASS";
    break;
  case 0x000020D3:
    ans = L"ERROR_DS_CANT_REMOVE_ATT_CACHE";
    break;
  case 0x000020D4:
    ans = L"ERROR_DS_CANT_REMOVE_CLASS_CACHE";
    break;
  case 0x000020D5:
    ans = L"ERROR_DS_CANT_RETRIEVE_DN";
    break;
  case 0x000020D6:
    ans = L"ERROR_DS_MISSING_SUPREF";
    break;
  case 0x000020D7:
    ans = L"ERROR_DS_CANT_RETRIEVE_INSTANCE";
    break;
  case 0x000020D8:
    ans = L"ERROR_DS_CODE_INCONSISTENCY";
    break;
  case 0x000020D9:
    ans = L"ERROR_DS_DATABASE_ERROR";
    break;
  case 0x000020DA:
    ans = L"ERROR_DS_GOVERNSID_MISSING";
    break;
  case 0x000020DB:
    ans = L"ERROR_DS_MISSING_EXPECTED_ATT";
    break;
  case 0x000020DC:
    ans = L"ERROR_DS_NCNAME_MISSING_CR_REF";
    break;
  case 0x000020DD:
    ans = L"ERROR_DS_SECURITY_CHECKING_ERROR";
    break;
  case 0x000020DE:
    ans = L"ERROR_DS_SCHEMA_NOT_LOADED";
    break;
  case 0x000020DF:
    ans = L"ERROR_DS_SCHEMA_ALLOC_FAILED";
    break;
  case 0x000020E0:
    ans = L"ERROR_DS_ATT_SCHEMA_REQ_SYNTAX";
    break;
  case 0x000020E1:
    ans = L"ERROR_DS_GCVERIFY_ERROR";
    break;
  case 0x000020E2:
    ans = L"ERROR_DS_DRA_SCHEMA_MISMATCH";
    break;
  case 0x000020E3:
    ans = L"ERROR_DS_CANT_FIND_DSA_OBJ";
    break;
  case 0x000020E4:
    ans = L"ERROR_DS_CANT_FIND_EXPECTED_NC";
    break;
  case 0x000020E5:
    ans = L"ERROR_DS_CANT_FIND_NC_IN_CACHE";
    break;
  case 0x000020E6:
    ans = L"ERROR_DS_CANT_RETRIEVE_CHILD";
    break;
  case 0x000020E7:
    ans = L"ERROR_DS_SECURITY_ILLEGAL_MODIFY";
    break;
  case 0x000020E8:
    ans = L"ERROR_DS_CANT_REPLACE_HIDDEN_REC";
    break;
  case 0x000020E9:
    ans = L"ERROR_DS_BAD_HIERARCHY_FILE";
    break;
  case 0x000020EA:
    ans = L"ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED";
    break;
  case 0x000020EB:
    ans = L"ERROR_DS_CONFIG_PARAM_MISSING";
    break;
  case 0x000020EC:
    ans = L"ERROR_DS_COUNTING_AB_INDICES_FAILED";
    break;
  case 0x000020ED:
    ans = L"ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED";
    break;
  case 0x000020EE:
    ans = L"ERROR_DS_INTERNAL_FAILURE";
    break;
  case 0x000020EF:
    ans = L"ERROR_DS_UNKNOWN_ERROR";
    break;
  case 0x000020F0:
    ans = L"ERROR_DS_ROOT_REQUIRES_CLASS_TOP";
    break;
  case 0x000020F1:
    ans = L"ERROR_DS_REFUSING_FSMO_ROLES";
    break;
  case 0x000020F2:
    ans = L"ERROR_DS_MISSING_FSMO_SETTINGS";
    break;
  case 0x000020F3:
    ans = L"ERROR_DS_UNABLE_TO_SURRENDER_ROLES";
    break;
  case 0x000020F4:
    ans = L"ERROR_DS_DRA_GENERIC";
    break;
  case 0x000020F5:
    ans = L"ERROR_DS_DRA_INVALID_PARAMETER";
    break;
  case 0x000020F6:
    ans = L"ERROR_DS_DRA_BUSY";
    break;
  case 0x000020F7:
    ans = L"ERROR_DS_DRA_BAD_DN";
    break;
  case 0x000020F8:
    ans = L"ERROR_DS_DRA_BAD_NC";
    break;
  case 0x000020F9:
    ans = L"ERROR_DS_DRA_DN_EXISTS";
    break;
  case 0x000020FA:
    ans = L"ERROR_DS_DRA_INTERNAL_ERROR";
    break;
  case 0x000020FB:
    ans = L"ERROR_DS_DRA_INCONSISTENT_DIT";
    break;
  case 0x000020FC:
    ans = L"ERROR_DS_DRA_CONNECTION_FAILED";
    break;
  case 0x000020FD:
    ans = L"ERROR_DS_DRA_BAD_INSTANCE_TYPE";
    break;
  case 0x000020FE:
    ans = L"ERROR_DS_DRA_OUT_OF_MEM";
    break;
  case 0x000020FF:
    ans = L"ERROR_DS_DRA_MAIL_PROBLEM";
    break;
  case 0x00002100:
    ans = L"ERROR_DS_DRA_REF_ALREADY_EXISTS";
    break;
  case 0x00002101:
    ans = L"ERROR_DS_DRA_REF_NOT_FOUND";
    break;
  case 0x00002102:
    ans = L"ERROR_DS_DRA_OBJ_IS_REP_SOURCE";
    break;
  case 0x00002103:
    ans = L"ERROR_DS_DRA_DB_ERROR";
    break;
  case 0x00002104:
    ans = L"ERROR_DS_DRA_NO_REPLICA";
    break;
  case 0x00002105:
    ans = L"ERROR_DS_DRA_ACCESS_DENIED";
    break;
  case 0x00002106:
    ans = L"ERROR_DS_DRA_NOT_SUPPORTED";
    break;
  case 0x00002107:
    ans = L"ERROR_DS_DRA_RPC_CANCELLED";
    break;
  case 0x00002108:
    ans = L"ERROR_DS_DRA_SOURCE_DISABLED";
    break;
  case 0x00002109:
    ans = L"ERROR_DS_DRA_SINK_DISABLED";
    break;
  case 0x0000210A:
    ans = L"ERROR_DS_DRA_NAME_COLLISION";
    break;
  case 0x0000210B:
    ans = L"ERROR_DS_DRA_SOURCE_REINSTALLED";
    break;
  case 0x0000210C:
    ans = L"ERROR_DS_DRA_MISSING_PARENT";
    break;
  case 0x0000210D:
    ans = L"ERROR_DS_DRA_PREEMPTED";
    break;
  case 0x0000210E:
    ans = L"ERROR_DS_DRA_ABANDON_SYNC";
    break;
  case 0x0000210F:
    ans = L"ERROR_DS_DRA_SHUTDOWN";
    break;
  case 0x00002110:
    ans = L"ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET";
    break;
  case 0x00002111:
    ans = L"ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA";
    break;
  case 0x00002112:
    ans = L"ERROR_DS_DRA_EXTN_CONNECTION_FAILED";
    break;
  case 0x00002113:
    ans = L"ERROR_DS_INSTALL_SCHEMA_MISMATCH";
    break;
  case 0x00002114:
    ans = L"ERROR_DS_DUP_LINK_ID";
    break;
  case 0x00002115:
    ans = L"ERROR_DS_NAME_ERROR_RESOLVING";
    break;
  case 0x00002116:
    ans = L"ERROR_DS_NAME_ERROR_NOT_FOUND";
    break;
  case 0x00002117:
    ans = L"ERROR_DS_NAME_ERROR_NOT_UNIQUE";
    break;
  case 0x00002118:
    ans = L"ERROR_DS_NAME_ERROR_NO_MAPPING";
    break;
  case 0x00002119:
    ans = L"ERROR_DS_NAME_ERROR_DOMAIN_ONLY";
    break;
  case 0x0000211A:
    ans = L"ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING";
    break;
  case 0x0000211B:
    ans = L"ERROR_DS_CONSTRUCTED_ATT_MOD";
    break;
  case 0x0000211C:
    ans = L"ERROR_DS_WRONG_OM_OBJ_CLASS";
    break;
  case 0x0000211D:
    ans = L"ERROR_DS_DRA_REPL_PENDING";
    break;
  case 0x0000211E:
    ans = L"ERROR_DS_DS_REQUIRED";
    break;
  case 0x0000211F:
    ans = L"ERROR_DS_INVALID_LDAP_DISPLAY_NAME";
    break;
  case 0x00002120:
    ans = L"ERROR_DS_NON_BASE_SEARCH";
    break;
  case 0x00002121:
    ans = L"ERROR_DS_CANT_RETRIEVE_ATTS";
    break;
  case 0x00002122:
    ans = L"ERROR_DS_BACKLINK_WITHOUT_LINK";
    break;
  case 0x00002123:
    ans = L"ERROR_DS_EPOCH_MISMATCH";
    break;
  case 0x00002124:
    ans = L"ERROR_DS_SRC_NAME_MISMATCH";
    break;
  case 0x00002125:
    ans = L"ERROR_DS_SRC_AND_DST_NC_IDENTICAL";
    break;
  case 0x00002126:
    ans = L"ERROR_DS_DST_NC_MISMATCH";
    break;
  case 0x00002127:
    ans = L"ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC";
    break;
  case 0x00002128:
    ans = L"ERROR_DS_SRC_GUID_MISMATCH";
    break;
  case 0x00002129:
    ans = L"ERROR_DS_CANT_MOVE_DELETED_OBJECT";
    break;
  case 0x0000212A:
    ans = L"ERROR_DS_PDC_OPERATION_IN_PROGRESS";
    break;
  case 0x0000212B:
    ans = L"ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD";
    break;
  case 0x0000212C:
    ans = L"ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION";
    break;
  case 0x0000212D:
    ans = L"ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS";
    break;
  case 0x0000212E:
    ans = L"ERROR_DS_NC_MUST_HAVE_NC_PARENT";
    break;
  case 0x0000212F:
    ans = L"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE";
    break;
  case 0x00002130:
    ans = L"ERROR_DS_DST_DOMAIN_NOT_NATIVE";
    break;
  case 0x00002131:
    ans = L"ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER";
    break;
  case 0x00002132:
    ans = L"ERROR_DS_CANT_MOVE_ACCOUNT_GROUP";
    break;
  case 0x00002133:
    ans = L"ERROR_DS_CANT_MOVE_RESOURCE_GROUP";
    break;
  case 0x00002134:
    ans = L"ERROR_DS_INVALID_SEARCH_FLAG";
    break;
  case 0x00002135:
    ans = L"ERROR_DS_NO_TREE_DELETE_ABOVE_NC";
    break;
  case 0x00002136:
    ans = L"ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE";
    break;
  case 0x00002137:
    ans = L"ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE";
    break;
  case 0x00002138:
    ans = L"ERROR_DS_SAM_INIT_FAILURE";
    break;
  case 0x00002139:
    ans = L"ERROR_DS_SENSITIVE_GROUP_VIOLATION";
    break;
  case 0x0000213A:
    ans = L"ERROR_DS_CANT_MOD_PRIMARYGROUPID";
    break;
  case 0x0000213B:
    ans = L"ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD";
    break;
  case 0x0000213C:
    ans = L"ERROR_DS_NONSAFE_SCHEMA_CHANGE";
    break;
  case 0x0000213D:
    ans = L"ERROR_DS_SCHEMA_UPDATE_DISALLOWED";
    break;
  case 0x0000213E:
    ans = L"ERROR_DS_CANT_CREATE_UNDER_SCHEMA";
    break;
  case 0x0000213F:
    ans = L"ERROR_DS_INSTALL_NO_SRC_SCH_VERSION";
    break;
  case 0x00002140:
    ans = L"ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE";
    break;
  case 0x00002141:
    ans = L"ERROR_DS_INVALID_GROUP_TYPE";
    break;
  case 0x00002142:
    ans = L"ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN";
    break;
  case 0x00002143:
    ans = L"ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN";
    break;
  case 0x00002144:
    ans = L"ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER";
    break;
  case 0x00002145:
    ans = L"ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER";
    break;
  case 0x00002146:
    ans = L"ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER";
    break;
  case 0x00002147:
    ans = L"ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER";
    break;
  case 0x00002148:
    ans = L"ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER";
    break;
  case 0x00002149:
    ans = L"ERROR_DS_HAVE_PRIMARY_MEMBERS";
    break;
  case 0x0000214A:
    ans = L"ERROR_DS_STRING_SD_CONVERSION_FAILED";
    break;
  case 0x0000214B:
    ans = L"ERROR_DS_NAMING_MASTER_GC";
    break;
  case 0x0000214C:
    ans = L"ERROR_DS_DNS_LOOKUP_FAILURE";
    break;
  case 0x0000214D:
    ans = L"ERROR_DS_COULDNT_UPDATE_SPNS";
    break;
  case 0x0000214E:
    ans = L"ERROR_DS_CANT_RETRIEVE_SD";
    break;
  case 0x0000214F:
    ans = L"ERROR_DS_KEY_NOT_UNIQUE";
    break;
  case 0x00002150:
    ans = L"ERROR_DS_WRONG_LINKED_ATT_SYNTAX";
    break;
  case 0x00002151:
    ans = L"ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD";
    break;
  case 0x00002152:
    ans = L"ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY";
    break;
  case 0x00002153:
    ans = L"ERROR_DS_CANT_START";
    break;
  case 0x00002154:
    ans = L"ERROR_DS_INIT_FAILURE";
    break;
  case 0x00002155:
    ans = L"ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION";
    break;
  case 0x00002156:
    ans = L"ERROR_DS_SOURCE_DOMAIN_IN_FOREST";
    break;
  case 0x00002157:
    ans = L"ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST";
    break;
  case 0x00002158:
    ans = L"ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED";
    break;
  case 0x00002159:
    ans = L"ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN";
    break;
  case 0x0000215A:
    ans = L"ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER";
    break;
  case 0x0000215B:
    ans = L"ERROR_DS_SRC_SID_EXISTS_IN_FOREST";
    break;
  case 0x0000215C:
    ans = L"ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH";
    break;
  case 0x0000215D:
    ans = L"ERROR_SAM_INIT_FAILURE";
    break;
  case 0x0000215E:
    ans = L"ERROR_DS_DRA_SCHEMA_INFO_SHIP";
    break;
  case 0x0000215F:
    ans = L"ERROR_DS_DRA_SCHEMA_CONFLICT";
    break;
  case 0x00002160:
    ans = L"ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT";
    break;
  case 0x00002161:
    ans = L"ERROR_DS_DRA_OBJ_NC_MISMATCH";
    break;
  case 0x00002162:
    ans = L"ERROR_DS_NC_STILL_HAS_DSAS";
    break;
  case 0x00002163:
    ans = L"ERROR_DS_GC_REQUIRED";
    break;
  case 0x00002164:
    ans = L"ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY";
    break;
  case 0x00002165:
    ans = L"ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS";
    break;
  case 0x00002166:
    ans = L"ERROR_DS_CANT_ADD_TO_GC";
    break;
  case 0x00002167:
    ans = L"ERROR_DS_NO_CHECKPOINT_WITH_PDC";
    break;
  case 0x00002168:
    ans = L"ERROR_DS_SOURCE_AUDITING_NOT_ENABLED";
    break;
  case 0x00002169:
    ans = L"ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC";
    break;
  case 0x0000216A:
    ans = L"ERROR_DS_INVALID_NAME_FOR_SPN";
    break;
  case 0x0000216B:
    ans = L"ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS";
    break;
  case 0x0000216C:
    ans = L"ERROR_DS_UNICODEPWD_NOT_IN_QUOTES";
    break;
  case 0x0000216D:
    ans = L"ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED";
    break;
  case 0x0000216E:
    ans = L"ERROR_DS_MUST_BE_RUN_ON_DST_DC";
    break;
  case 0x0000216F:
    ans = L"ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER";
    break;
  case 0x00002170:
    ans = L"ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ";
    break;
  case 0x00002171:
    ans = L"ERROR_DS_INIT_FAILURE_CONSOLE";
    break;
  case 0x00002172:
    ans = L"ERROR_DS_SAM_INIT_FAILURE_CONSOLE";
    break;
  case 0x00002173:
    ans = L"ERROR_DS_FOREST_VERSION_TOO_HIGH";
    break;
  case 0x00002174:
    ans = L"ERROR_DS_DOMAIN_VERSION_TOO_HIGH";
    break;
  case 0x00002175:
    ans = L"ERROR_DS_FOREST_VERSION_TOO_LOW";
    break;
  case 0x00002176:
    ans = L"ERROR_DS_DOMAIN_VERSION_TOO_LOW";
    break;
  case 0x00002177:
    ans = L"ERROR_DS_INCOMPATIBLE_VERSION";
    break;
  case 0x00002178:
    ans = L"ERROR_DS_LOW_DSA_VERSION";
    break;
  case 0x00002179:
    ans = L"ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN";
    break;
  case 0x0000217A:
    ans = L"ERROR_DS_NOT_SUPPORTED_SORT_ORDER";
    break;
  case 0x0000217B:
    ans = L"ERROR_DS_NAME_NOT_UNIQUE";
    break;
  case 0x0000217C:
    ans = L"ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4";
    break;
  case 0x0000217D:
    ans = L"ERROR_DS_OUT_OF_VERSION_STORE";
    break;
  case 0x0000217E:
    ans = L"ERROR_DS_INCOMPATIBLE_CONTROLS_USED";
    break;
  case 0x0000217F:
    ans = L"ERROR_DS_NO_REF_DOMAIN";
    break;
  case 0x00002180:
    ans = L"ERROR_DS_RESERVED_LINK_ID";
    break;
  case 0x00002181:
    ans = L"ERROR_DS_LINK_ID_NOT_AVAILABLE";
    break;
  case 0x00002182:
    ans = L"ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER";
    break;
  case 0x00002183:
    ans = L"ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE";
    break;
  case 0x00002184:
    ans = L"ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC";
    break;
  case 0x00002185:
    ans = L"ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG";
    break;
  case 0x00002186:
    ans = L"ERROR_DS_MODIFYDN_WRONG_GRANDPARENT";
    break;
  case 0x00002187:
    ans = L"ERROR_DS_NAME_ERROR_TRUST_REFERRAL";
    break;
  case 0x00002188:
    ans = L"ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER";
    break;
  case 0x00002189:
    ans = L"ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD";
    break;
  case 0x0000218A:
    ans = L"ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2";
    break;
  case 0x0000218B:
    ans = L"ERROR_DS_THREAD_LIMIT_EXCEEDED";
    break;
  case 0x0000218C:
    ans = L"ERROR_DS_NOT_CLOSEST";
    break;
  case 0x0000218D:
    ans = L"ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF";
    break;
  case 0x0000218E:
    ans = L"ERROR_DS_SINGLE_USER_MODE_FAILED";
    break;
  case 0x0000218F:
    ans = L"ERROR_DS_NTDSCRIPT_SYNTAX_ERROR";
    break;
  case 0x00002190:
    ans = L"ERROR_DS_NTDSCRIPT_PROCESS_ERROR";
    break;
  case 0x00002191:
    ans = L"ERROR_DS_DIFFERENT_REPL_EPOCHS";
    break;
  case 0x00002192:
    ans = L"ERROR_DS_DRS_EXTENSIONS_CHANGED";
    break;
  case 0x00002193:
    ans = L"ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR";
    break;
  case 0x00002194:
    ans = L"ERROR_DS_NO_MSDS_INTID";
    break;
  case 0x00002195:
    ans = L"ERROR_DS_DUP_MSDS_INTID";
    break;
  case 0x00002196:
    ans = L"ERROR_DS_EXISTS_IN_RDNATTID";
    break;
  case 0x00002197:
    ans = L"ERROR_DS_AUTHORIZATION_FAILED";
    break;
  case 0x00002198:
    ans = L"ERROR_DS_INVALID_SCRIPT";
    break;
  case 0x00002199:
    ans = L"ERROR_DS_REMOTE_CROSSREF_OP_FAILED";
    break;
  case 0x0000219A:
    ans = L"ERROR_DS_CROSS_REF_BUSY";
    break;
  case 0x0000219B:
    ans = L"ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN";
    break;
  case 0x0000219C:
    ans = L"ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC";
    break;
  case 0x0000219D:
    ans = L"ERROR_DS_DUPLICATE_ID_FOUND";
    break;
  case 0x0000219E:
    ans = L"ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT";
    break;
  case 0x0000219F:
    ans = L"ERROR_DS_GROUP_CONVERSION_ERROR";
    break;
  case 0x000021A0:
    ans = L"ERROR_DS_CANT_MOVE_APP_BASIC_GROUP";
    break;
  case 0x000021A1:
    ans = L"ERROR_DS_CANT_MOVE_APP_QUERY_GROUP";
    break;
  case 0x000021A2:
    ans = L"ERROR_DS_ROLE_NOT_VERIFIED";
    break;
  case 0x000021A3:
    ans = L"ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL";
    break;
  case 0x000021A4:
    ans = L"ERROR_DS_DOMAIN_RENAME_IN_PROGRESS";
    break;
  case 0x000021A5:
    ans = L"ERROR_DS_EXISTING_AD_CHILD_NC";
    break;
  case 0x000021A6:
    ans = L"ERROR_DS_REPL_LIFETIME_EXCEEDED";
    break;
  case 0x000021A7:
    ans = L"ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER";
    break;
  case 0x000021A8:
    ans = L"ERROR_DS_LDAP_SEND_QUEUE_FULL";
    break;
  case 0x000021A9:
    ans = L"ERROR_DS_DRA_OUT_SCHEDULE_WINDOW";
    break;
  case 0x000021AA:
    ans = L"ERROR_DS_POLICY_NOT_KNOWN";
    break;
  case 0x000021AB:
    ans = L"ERROR_NO_SITE_SETTINGS_OBJECT";
    break;
  case 0x000021AC:
    ans = L"ERROR_NO_SECRETS";
    break;
  case 0x000021AD:
    ans = L"ERROR_NO_WRITABLE_DC_FOUND";
    break;
  case 0x000021AE:
    ans = L"ERROR_DS_NO_SERVER_OBJECT";
    break;
  case 0x000021AF:
    ans = L"ERROR_DS_NO_NTDSA_OBJECT";
    break;
  case 0x000021B0:
    ans = L"ERROR_DS_NON_ASQ_SEARCH";
    break;
  case 0x000021B1:
    ans = L"ERROR_DS_AUDIT_FAILURE";
    break;
  case 0x000021B2:
    ans = L"ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE";
    break;
  case 0x000021B3:
    ans = L"ERROR_DS_INVALID_SEARCH_FLAG_TUPLE";
    break;
  case 0x000021B4:
    ans = L"ERROR_DS_HIERARCHY_TABLE_TOO_DEEP";
    break;
  case 0x000021B5:
    ans = L"ERROR_DS_DRA_CORRUPT_UTD_VECTOR";
    break;
  case 0x000021B6:
    ans = L"ERROR_DS_DRA_SECRETS_DENIED";
    break;
  case 0x000021B7:
    ans = L"ERROR_DS_RESERVED_MAPI_ID";
    break;
  case 0x000021B8:
    ans = L"ERROR_DS_MAPI_ID_NOT_AVAILABLE";
    break;
  case 0x000021B9:
    ans = L"ERROR_DS_DRA_MISSING_KRBTGT_SECRET";
    break;
  case 0x000021BA:
    ans = L"ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST";
    break;
  case 0x000021BB:
    ans = L"ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST";
    break;
  case 0x000021BC:
    ans = L"ERROR_INVALID_USER_PRINCIPAL_NAME";
    break;
  case 0x000021BD:
    ans = L"ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS";
    break;
  case 0x000021BE:
    ans = L"ERROR_DS_OID_NOT_FOUND";
    break;
  case 0x000021BF:
    ans = L"ERROR_DS_DRA_RECYCLED_TARGET";
    break;
  case 0x000021C0:
    ans = L"ERROR_DS_DISALLOWED_NC_REDIRECT";
    break;
  case 0x000021C1:
    ans = L"ERROR_DS_HIGH_ADLDS_FFL";
    break;
  case 0x000021C2:
    ans = L"ERROR_DS_HIGH_DSA_VERSION";
    break;
  case 0x000021C3:
    ans = L"ERROR_DS_LOW_ADLDS_FFL";
    break;
  case 0x000021C4:
    ans = L"ERROR_DOMAIN_SID_SAME_AS_LOCAL_WORKSTATION";
    break;
  case 0x000021C5:
    ans = L"ERROR_DS_UNDELETE_SAM_VALIDATION_FAILED";
    break;
  case 0x000021C6:
    ans = L"ERROR_INCORRECT_ACCOUNT_TYPE";
    break;
  case 0x000021C7:
    ans = L"ERROR_DS_SPN_VALUE_NOT_UNIQUE_IN_FOREST";
    break;
  case 0x000021C8:
    ans = L"ERROR_DS_UPN_VALUE_NOT_UNIQUE_IN_FOREST";
    break;
  case 0x000021C9:
    ans = L"ERROR_DS_MISSING_FOREST_TRUST";
    break;
  case 0x000021CA:
    ans = L"ERROR_DS_VALUE_KEY_NOT_UNIQUE";
    break;
  case 0x00002329:
    ans = L"DNS_ERROR_RCODE_FORMAT_ERROR";
    break;
  case 0x0000232A:
    ans = L"DNS_ERROR_RCODE_SERVER_FAILURE";
    break;
  case 0x0000232B:
    ans = L"DNS_ERROR_RCODE_NAME_ERROR";
    break;
  case 0x0000232C:
    ans = L"DNS_ERROR_RCODE_NOT_IMPLEMENTED";
    break;
  case 0x0000232D:
    ans = L"DNS_ERROR_RCODE_REFUSED";
    break;
  case 0x0000232E:
    ans = L"DNS_ERROR_RCODE_YXDOMAIN";
    break;
  case 0x0000232F:
    ans = L"DNS_ERROR_RCODE_YXRRSET";
    break;
  case 0x00002330:
    ans = L"DNS_ERROR_RCODE_NXRRSET";
    break;
  case 0x00002331:
    ans = L"DNS_ERROR_RCODE_NOTAUTH";
    break;
  case 0x00002332:
    ans = L"DNS_ERROR_RCODE_NOTZONE";
    break;
  case 0x00002338:
    ans = L"DNS_ERROR_RCODE_BADSIG";
    break;
  case 0x00002339:
    ans = L"DNS_ERROR_RCODE_BADKEY";
    break;
  case 0x0000233A:
    ans = L"DNS_ERROR_RCODE_BADTIME";
    break;
  case 0x0000238D:
    ans = L"DNS_ERROR_KEYMASTER_REQUIRED";
    break;
  case 0x0000238E:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_SIGNED_ZONE";
    break;
  case 0x0000238F:
    ans = L"DNS_ERROR_NSEC3_INCOMPATIBLE_WITH_RSA_SHA1";
    break;
  case 0x00002390:
    ans = L"DNS_ERROR_NOT_ENOUGH_SIGNING_KEY_DESCRIPTORS";
    break;
  case 0x00002391:
    ans = L"DNS_ERROR_UNSUPPORTED_ALGORITHM";
    break;
  case 0x00002392:
    ans = L"DNS_ERROR_INVALID_KEY_SIZE";
    break;
  case 0x00002393:
    ans = L"DNS_ERROR_SIGNING_KEY_NOT_ACCESSIBLE";
    break;
  case 0x00002394:
    ans = L"DNS_ERROR_KSP_DOES_NOT_SUPPORT_PROTECTION";
    break;
  case 0x00002395:
    ans = L"DNS_ERROR_UNEXPECTED_DATA_PROTECTION_ERROR";
    break;
  case 0x00002396:
    ans = L"DNS_ERROR_UNEXPECTED_CNG_ERROR";
    break;
  case 0x00002397:
    ans = L"DNS_ERROR_UNKNOWN_SIGNING_PARAMETER_VERSION";
    break;
  case 0x00002398:
    ans = L"DNS_ERROR_KSP_NOT_ACCESSIBLE";
    break;
  case 0x00002399:
    ans = L"DNS_ERROR_TOO_MANY_SKDS";
    break;
  case 0x0000239A:
    ans = L"DNS_ERROR_INVALID_ROLLOVER_PERIOD";
    break;
  case 0x0000239B:
    ans = L"DNS_ERROR_INVALID_INITIAL_ROLLOVER_OFFSET";
    break;
  case 0x0000239C:
    ans = L"DNS_ERROR_ROLLOVER_IN_PROGRESS";
    break;
  case 0x0000239D:
    ans = L"DNS_ERROR_STANDBY_KEY_NOT_PRESENT";
    break;
  case 0x0000239E:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_ZSK";
    break;
  case 0x0000239F:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_ACTIVE_SKD";
    break;
  case 0x000023A0:
    ans = L"DNS_ERROR_ROLLOVER_ALREADY_QUEUED";
    break;
  case 0x000023A1:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_UNSIGNED_ZONE";
    break;
  case 0x000023A2:
    ans = L"DNS_ERROR_BAD_KEYMASTER";
    break;
  case 0x000023A3:
    ans = L"DNS_ERROR_INVALID_SIGNATURE_VALIDITY_PERIOD";
    break;
  case 0x000023A4:
    ans = L"DNS_ERROR_INVALID_NSEC3_ITERATION_COUNT";
    break;
  case 0x000023A5:
    ans = L"DNS_ERROR_DNSSEC_IS_DISABLED";
    break;
  case 0x000023A6:
    ans = L"DNS_ERROR_INVALID_XML";
    break;
  case 0x000023A7:
    ans = L"DNS_ERROR_NO_VALID_TRUST_ANCHORS";
    break;
  case 0x000023A8:
    ans = L"DNS_ERROR_ROLLOVER_NOT_POKEABLE";
    break;
  case 0x000023A9:
    ans = L"DNS_ERROR_NSEC3_NAME_COLLISION";
    break;
  case 0x000023AA:
    ans = L"DNS_ERROR_NSEC_INCOMPATIBLE_WITH_NSEC3_RSA_SHA1";
    break;
  case 0x0000251D:
    ans = L"DNS_INFO_NO_RECORDS";
    break;
  case 0x0000251E:
    ans = L"DNS_ERROR_BAD_PACKET";
    break;
  case 0x0000251F:
    ans = L"DNS_ERROR_NO_PACKET";
    break;
  case 0x00002520:
    ans = L"DNS_ERROR_RCODE";
    break;
  case 0x00002521:
    ans = L"DNS_ERROR_UNSECURE_PACKET";
    break;
  case 0x00002522:
    ans = L"DNS_REQUEST_PENDING";
    break;
  case 0x0000254F:
    ans = L"DNS_ERROR_INVALID_TYPE";
    break;
  case 0x00002550:
    ans = L"DNS_ERROR_INVALID_IP_ADDRESS";
    break;
  case 0x00002551:
    ans = L"DNS_ERROR_INVALID_PROPERTY";
    break;
  case 0x00002552:
    ans = L"DNS_ERROR_TRY_AGAIN_LATER";
    break;
  case 0x00002553:
    ans = L"DNS_ERROR_NOT_UNIQUE";
    break;
  case 0x00002554:
    ans = L"DNS_ERROR_NON_RFC_NAME";
    break;
  case 0x00002555:
    ans = L"DNS_STATUS_FQDN";
    break;
  case 0x00002556:
    ans = L"DNS_STATUS_DOTTED_NAME";
    break;
  case 0x00002557:
    ans = L"DNS_STATUS_SINGLE_PART_NAME";
    break;
  case 0x00002558:
    ans = L"DNS_ERROR_INVALID_NAME_CHAR";
    break;
  case 0x00002559:
    ans = L"DNS_ERROR_NUMERIC_NAME";
    break;
  case 0x0000255A:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER";
    break;
  case 0x0000255B:
    ans = L"DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION";
    break;
  case 0x0000255C:
    ans = L"DNS_ERROR_CANNOT_FIND_ROOT_HINTS";
    break;
  case 0x0000255D:
    ans = L"DNS_ERROR_INCONSISTENT_ROOT_HINTS";
    break;
  case 0x0000255E:
    ans = L"DNS_ERROR_DWORD_VALUE_TOO_SMALL";
    break;
  case 0x0000255F:
    ans = L"DNS_ERROR_DWORD_VALUE_TOO_LARGE";
    break;
  case 0x00002560:
    ans = L"DNS_ERROR_BACKGROUND_LOADING";
    break;
  case 0x00002561:
    ans = L"DNS_ERROR_NOT_ALLOWED_ON_RODC";
    break;
  case 0x00002562:
    ans = L"DNS_ERROR_NOT_ALLOWED_UNDER_DNAME";
    break;
  case 0x00002563:
    ans = L"DNS_ERROR_DELEGATION_REQUIRED";
    break;
  case 0x00002564:
    ans = L"DNS_ERROR_INVALID_POLICY_TABLE";
    break;
  case 0x00002565:
    ans = L"DNS_ERROR_ADDRESS_REQUIRED";
    break;
  case 0x00002581:
    ans = L"DNS_ERROR_ZONE_DOES_NOT_EXIST";
    break;
  case 0x00002582:
    ans = L"DNS_ERROR_NO_ZONE_INFO";
    break;
  case 0x00002583:
    ans = L"DNS_ERROR_INVALID_ZONE_OPERATION";
    break;
  case 0x00002584:
    ans = L"DNS_ERROR_ZONE_CONFIGURATION_ERROR";
    break;
  case 0x00002585:
    ans = L"DNS_ERROR_ZONE_HAS_NO_SOA_RECORD";
    break;
  case 0x00002586:
    ans = L"DNS_ERROR_ZONE_HAS_NO_NS_RECORDS";
    break;
  case 0x00002587:
    ans = L"DNS_ERROR_ZONE_LOCKED";
    break;
  case 0x00002588:
    ans = L"DNS_ERROR_ZONE_CREATION_FAILED";
    break;
  case 0x00002589:
    ans = L"DNS_ERROR_ZONE_ALREADY_EXISTS";
    break;
  case 0x0000258A:
    ans = L"DNS_ERROR_AUTOZONE_ALREADY_EXISTS";
    break;
  case 0x0000258B:
    ans = L"DNS_ERROR_INVALID_ZONE_TYPE";
    break;
  case 0x0000258C:
    ans = L"DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP";
    break;
  case 0x0000258D:
    ans = L"DNS_ERROR_ZONE_NOT_SECONDARY";
    break;
  case 0x0000258E:
    ans = L"DNS_ERROR_NEED_SECONDARY_ADDRESSES";
    break;
  case 0x0000258F:
    ans = L"DNS_ERROR_WINS_INIT_FAILED";
    break;
  case 0x00002590:
    ans = L"DNS_ERROR_NEED_WINS_SERVERS";
    break;
  case 0x00002591:
    ans = L"DNS_ERROR_NBSTAT_INIT_FAILED";
    break;
  case 0x00002592:
    ans = L"DNS_ERROR_SOA_DELETE_INVALID";
    break;
  case 0x00002593:
    ans = L"DNS_ERROR_FORWARDER_ALREADY_EXISTS";
    break;
  case 0x00002594:
    ans = L"DNS_ERROR_ZONE_REQUIRES_MASTER_IP";
    break;
  case 0x00002595:
    ans = L"DNS_ERROR_ZONE_IS_SHUTDOWN";
    break;
  case 0x00002596:
    ans = L"DNS_ERROR_ZONE_LOCKED_FOR_SIGNING";
    break;
  case 0x000025B3:
    ans = L"DNS_ERROR_PRIMARY_REQUIRES_DATAFILE";
    break;
  case 0x000025B4:
    ans = L"DNS_ERROR_INVALID_DATAFILE_NAME";
    break;
  case 0x000025B5:
    ans = L"DNS_ERROR_DATAFILE_OPEN_FAILURE";
    break;
  case 0x000025B6:
    ans = L"DNS_ERROR_FILE_WRITEBACK_FAILED";
    break;
  case 0x000025B7:
    ans = L"DNS_ERROR_DATAFILE_PARSING";
    break;
  case 0x000025E5:
    ans = L"DNS_ERROR_RECORD_DOES_NOT_EXIST";
    break;
  case 0x000025E6:
    ans = L"DNS_ERROR_RECORD_FORMAT";
    break;
  case 0x000025E7:
    ans = L"DNS_ERROR_NODE_CREATION_FAILED";
    break;
  case 0x000025E8:
    ans = L"DNS_ERROR_UNKNOWN_RECORD_TYPE";
    break;
  case 0x000025E9:
    ans = L"DNS_ERROR_RECORD_TIMED_OUT";
    break;
  case 0x000025EA:
    ans = L"DNS_ERROR_NAME_NOT_IN_ZONE";
    break;
  case 0x000025EB:
    ans = L"DNS_ERROR_CNAME_LOOP";
    break;
  case 0x000025EC:
    ans = L"DNS_ERROR_NODE_IS_CNAME";
    break;
  case 0x000025ED:
    ans = L"DNS_ERROR_CNAME_COLLISION";
    break;
  case 0x000025EE:
    ans = L"DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT";
    break;
  case 0x000025EF:
    ans = L"DNS_ERROR_RECORD_ALREADY_EXISTS";
    break;
  case 0x000025F0:
    ans = L"DNS_ERROR_SECONDARY_DATA";
    break;
  case 0x000025F1:
    ans = L"DNS_ERROR_NO_CREATE_CACHE_DATA";
    break;
  case 0x000025F2:
    ans = L"DNS_ERROR_NAME_DOES_NOT_EXIST";
    break;
  case 0x000025F3:
    ans = L"DNS_WARNING_PTR_CREATE_FAILED";
    break;
  case 0x000025F4:
    ans = L"DNS_WARNING_DOMAIN_UNDELETED";
    break;
  case 0x000025F5:
    ans = L"DNS_ERROR_DS_UNAVAILABLE";
    break;
  case 0x000025F6:
    ans = L"DNS_ERROR_DS_ZONE_ALREADY_EXISTS";
    break;
  case 0x000025F7:
    ans = L"DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE";
    break;
  case 0x000025F8:
    ans = L"DNS_ERROR_NODE_IS_DNAME";
    break;
  case 0x000025F9:
    ans = L"DNS_ERROR_DNAME_COLLISION";
    break;
  case 0x000025FA:
    ans = L"DNS_ERROR_ALIAS_LOOP";
    break;
  case 0x00002617:
    ans = L"DNS_INFO_AXFR_COMPLETE";
    break;
  case 0x00002618:
    ans = L"DNS_ERROR_AXFR";
    break;
  case 0x00002619:
    ans = L"DNS_INFO_ADDED_LOCAL_WINS";
    break;
  case 0x00002649:
    ans = L"DNS_STATUS_CONTINUE_NEEDED";
    break;
  case 0x0000267B:
    ans = L"DNS_ERROR_NO_TCPIP";
    break;
  case 0x0000267C:
    ans = L"DNS_ERROR_NO_DNS_SERVERS";
    break;
  case 0x000026AD:
    ans = L"DNS_ERROR_DP_DOES_NOT_EXIST";
    break;
  case 0x000026AE:
    ans = L"DNS_ERROR_DP_ALREADY_EXISTS";
    break;
  case 0x000026AF:
    ans = L"DNS_ERROR_DP_NOT_ENLISTED";
    break;
  case 0x000026B0:
    ans = L"DNS_ERROR_DP_ALREADY_ENLISTED";
    break;
  case 0x000026B1:
    ans = L"DNS_ERROR_DP_NOT_AVAILABLE";
    break;
  case 0x000026B2:
    ans = L"DNS_ERROR_DP_FSMO_ERROR";
    break;
  case 0x000026B7:
    ans = L"DNS_ERROR_RRL_NOT_ENABLED";
    break;
  case 0x000026B8:
    ans = L"DNS_ERROR_RRL_INVALID_WINDOW_SIZE";
    break;
  case 0x000026B9:
    ans = L"DNS_ERROR_RRL_INVALID_IPV4_PREFIX";
    break;
  case 0x000026BA:
    ans = L"DNS_ERROR_RRL_INVALID_IPV6_PREFIX";
    break;
  case 0x000026BB:
    ans = L"DNS_ERROR_RRL_INVALID_TC_RATE";
    break;
  case 0x000026BC:
    ans = L"DNS_ERROR_RRL_INVALID_LEAK_RATE";
    break;
  case 0x000026BD:
    ans = L"DNS_ERROR_RRL_LEAK_RATE_LESSTHAN_TC_RATE";
    break;
  case 0x000026C1:
    ans = L"DNS_ERROR_VIRTUALIZATION_INSTANCE_ALREADY_EXISTS";
    break;
  case 0x000026C2:
    ans = L"DNS_ERROR_VIRTUALIZATION_INSTANCE_DOES_NOT_EXIST";
    break;
  case 0x000026C3:
    ans = L"DNS_ERROR_VIRTUALIZATION_TREE_LOCKED";
    break;
  case 0x000026C4:
    ans = L"DNS_ERROR_INVAILD_VIRTUALIZATION_INSTANCE_NAME";
    break;
  case 0x000026C5:
    ans = L"DNS_ERROR_DEFAULT_VIRTUALIZATION_INSTANCE";
    break;
  case 0x000026DF:
    ans = L"DNS_ERROR_ZONESCOPE_ALREADY_EXISTS";
    break;
  case 0x000026E0:
    ans = L"DNS_ERROR_ZONESCOPE_DOES_NOT_EXIST";
    break;
  case 0x000026E1:
    ans = L"DNS_ERROR_DEFAULT_ZONESCOPE";
    break;
  case 0x000026E2:
    ans = L"DNS_ERROR_INVALID_ZONESCOPE_NAME";
    break;
  case 0x000026E3:
    ans = L"DNS_ERROR_NOT_ALLOWED_WITH_ZONESCOPES";
    break;
  case 0x000026E4:
    ans = L"DNS_ERROR_LOAD_ZONESCOPE_FAILED";
    break;
  case 0x000026E5:
    ans = L"DNS_ERROR_ZONESCOPE_FILE_WRITEBACK_FAILED";
    break;
  case 0x000026E6:
    ans = L"DNS_ERROR_INVALID_SCOPE_NAME";
    break;
  case 0x000026E7:
    ans = L"DNS_ERROR_SCOPE_DOES_NOT_EXIST";
    break;
  case 0x000026E8:
    ans = L"DNS_ERROR_DEFAULT_SCOPE";
    break;
  case 0x000026E9:
    ans = L"DNS_ERROR_INVALID_SCOPE_OPERATION";
    break;
  case 0x000026EA:
    ans = L"DNS_ERROR_SCOPE_LOCKED";
    break;
  case 0x000026EB:
    ans = L"DNS_ERROR_SCOPE_ALREADY_EXISTS";
    break;
  case 0x000026F3:
    ans = L"DNS_ERROR_POLICY_ALREADY_EXISTS";
    break;
  case 0x000026F4:
    ans = L"DNS_ERROR_POLICY_DOES_NOT_EXIST";
    break;
  case 0x000026F5:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA";
    break;
  case 0x000026F6:
    ans = L"DNS_ERROR_POLICY_INVALID_SETTINGS";
    break;
  case 0x000026F7:
    ans = L"DNS_ERROR_CLIENT_SUBNET_IS_ACCESSED";
    break;
  case 0x000026F8:
    ans = L"DNS_ERROR_CLIENT_SUBNET_DOES_NOT_EXIST";
    break;
  case 0x000026F9:
    ans = L"DNS_ERROR_CLIENT_SUBNET_ALREADY_EXISTS";
    break;
  case 0x000026FA:
    ans = L"DNS_ERROR_SUBNET_DOES_NOT_EXIST";
    break;
  case 0x000026FB:
    ans = L"DNS_ERROR_SUBNET_ALREADY_EXISTS";
    break;
  case 0x000026FC:
    ans = L"DNS_ERROR_POLICY_LOCKED";
    break;
  case 0x000026FD:
    ans = L"DNS_ERROR_POLICY_INVALID_WEIGHT";
    break;
  case 0x000026FE:
    ans = L"DNS_ERROR_POLICY_INVALID_NAME";
    break;
  case 0x000026FF:
    ans = L"DNS_ERROR_POLICY_MISSING_CRITERIA";
    break;
  case 0x00002700:
    ans = L"DNS_ERROR_INVALID_CLIENT_SUBNET_NAME";
    break;
  case 0x00002701:
    ans = L"DNS_ERROR_POLICY_PROCESSING_ORDER_INVALID";
    break;
  case 0x00002702:
    ans = L"DNS_ERROR_POLICY_SCOPE_MISSING";
    break;
  case 0x00002703:
    ans = L"DNS_ERROR_POLICY_SCOPE_NOT_ALLOWED";
    break;
  case 0x00002704:
    ans = L"DNS_ERROR_SERVERSCOPE_IS_REFERENCED";
    break;
  case 0x00002705:
    ans = L"DNS_ERROR_ZONESCOPE_IS_REFERENCED";
    break;
  case 0x00002706:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_CLIENT_SUBNET";
    break;
  case 0x00002707:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_TRANSPORT_PROTOCOL";
    break;
  case 0x00002708:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_NETWORK_PROTOCOL";
    break;
  case 0x00002709:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_INTERFACE";
    break;
  case 0x0000270A:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_FQDN";
    break;
  case 0x0000270B:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_QUERY_TYPE";
    break;
  case 0x0000270C:
    ans = L"DNS_ERROR_POLICY_INVALID_CRITERIA_TIME_OF_DAY";
    break;
  case 0x00002714:
    ans = L"WSAEINTR";
    break;
  case 0x00002719:
    ans = L"WSAEBADF";
    break;
  case 0x0000271D:
    ans = L"WSAEACCES";
    break;
  case 0x0000271E:
    ans = L"WSAEFAULT";
    break;
  case 0x00002726:
    ans = L"WSAEINVAL";
    break;
  case 0x00002728:
    ans = L"WSAEMFILE";
    break;
  case 0x00002733:
    ans = L"WSAEWOULDBLOCK";
    break;
  case 0x00002734:
    ans = L"WSAEINPROGRESS";
    break;
  case 0x00002735:
    ans = L"WSAEALREADY";
    break;
  case 0x00002736:
    ans = L"WSAENOTSOCK";
    break;
  case 0x00002737:
    ans = L"WSAEDESTADDRREQ";
    break;
  case 0x00002738:
    ans = L"WSAEMSGSIZE";
    break;
  case 0x00002739:
    ans = L"WSAEPROTOTYPE";
    break;
  case 0x0000273A:
    ans = L"WSAENOPROTOOPT";
    break;
  case 0x0000273B:
    ans = L"WSAEPROTONOSUPPORT";
    break;
  case 0x0000273C:
    ans = L"WSAESOCKTNOSUPPORT";
    break;
  case 0x0000273D:
    ans = L"WSAEOPNOTSUPP";
    break;
  case 0x0000273E:
    ans = L"WSAEPFNOSUPPORT";
    break;
  case 0x0000273F:
    ans = L"WSAEAFNOSUPPORT";
    break;
  case 0x00002740:
    ans = L"WSAEADDRINUSE";
    break;
  case 0x00002741:
    ans = L"WSAEADDRNOTAVAIL";
    break;
  case 0x00002742:
    ans = L"WSAENETDOWN";
    break;
  case 0x00002743:
    ans = L"WSAENETUNREACH";
    break;
  case 0x00002744:
    ans = L"WSAENETRESET";
    break;
  case 0x00002745:
    ans = L"WSAECONNABORTED";
    break;
  case 0x00002746:
    ans = L"WSAECONNRESET";
    break;
  case 0x00002747:
    ans = L"WSAENOBUFS";
    break;
  case 0x00002748:
    ans = L"WSAEISCONN";
    break;
  case 0x00002749:
    ans = L"WSAENOTCONN";
    break;
  case 0x0000274A:
    ans = L"WSAESHUTDOWN";
    break;
  case 0x0000274B:
    ans = L"WSAETOOMANYREFS";
    break;
  case 0x0000274C:
    ans = L"WSAETIMEDOUT";
    break;
  case 0x0000274D:
    ans = L"WSAECONNREFUSED";
    break;
  case 0x0000274E:
    ans = L"WSAELOOP";
    break;
  case 0x0000274F:
    ans = L"WSAENAMETOOLONG";
    break;
  case 0x00002750:
    ans = L"WSAEHOSTDOWN";
    break;
  case 0x00002751:
    ans = L"WSAEHOSTUNREACH";
    break;
  case 0x00002752:
    ans = L"WSAENOTEMPTY";
    break;
  case 0x00002753:
    ans = L"WSAEPROCLIM";
    break;
  case 0x00002754:
    ans = L"WSAEUSERS";
    break;
  case 0x00002755:
    ans = L"WSAEDQUOT";
    break;
  case 0x00002756:
    ans = L"WSAESTALE";
    break;
  case 0x00002757:
    ans = L"WSAEREMOTE";
    break;
  case 0x0000276B:
    ans = L"WSASYSNOTREADY";
    break;
  case 0x0000276C:
    ans = L"WSAVERNOTSUPPORTED";
    break;
  case 0x0000276D:
    ans = L"WSANOTINITIALISED";
    break;
  case 0x00002775:
    ans = L"WSAEDISCON";
    break;
  case 0x00002776:
    ans = L"WSAENOMORE";
    break;
  case 0x00002777:
    ans = L"WSAECANCELLED";
    break;
  case 0x00002778:
    ans = L"WSAEINVALIDPROCTABLE";
    break;
  case 0x00002779:
    ans = L"WSAEINVALIDPROVIDER";
    break;
  case 0x0000277A:
    ans = L"WSAEPROVIDERFAILEDINIT";
    break;
  case 0x0000277B:
    ans = L"WSASYSCALLFAILURE";
    break;
  case 0x0000277C:
    ans = L"WSASERVICE_NOT_FOUND";
    break;
  case 0x0000277D:
    ans = L"WSATYPE_NOT_FOUND";
    break;
  case 0x0000277E:
    ans = L"WSA_E_NO_MORE";
    break;
  case 0x0000277F:
    ans = L"WSA_E_CANCELLED";
    break;
  case 0x00002780:
    ans = L"WSAEREFUSED";
    break;
  case 0x00002AF9:
    ans = L"WSAHOST_NOT_FOUND";
    break;
  case 0x00002AFA:
    ans = L"WSATRY_AGAIN";
    break;
  case 0x00002AFB:
    ans = L"WSANO_RECOVERY";
    break;
  case 0x00002AFC:
    ans = L"WSANO_DATA";
    break;
  case 0x00002AFD:
    ans = L"WSA_QOS_RECEIVERS";
    break;
  case 0x00002AFE:
    ans = L"WSA_QOS_SENDERS";
    break;
  case 0x00002AFF:
    ans = L"WSA_QOS_NO_SENDERS";
    break;
  case 0x00002B00:
    ans = L"WSA_QOS_NO_RECEIVERS";
    break;
  case 0x00002B01:
    ans = L"WSA_QOS_REQUEST_CONFIRMED";
    break;
  case 0x00002B02:
    ans = L"WSA_QOS_ADMISSION_FAILURE";
    break;
  case 0x00002B03:
    ans = L"WSA_QOS_POLICY_FAILURE";
    break;
  case 0x00002B04:
    ans = L"WSA_QOS_BAD_STYLE";
    break;
  case 0x00002B05:
    ans = L"WSA_QOS_BAD_OBJECT";
    break;
  case 0x00002B06:
    ans = L"WSA_QOS_TRAFFIC_CTRL_ERROR";
    break;
  case 0x00002B07:
    ans = L"WSA_QOS_GENERIC_ERROR";
    break;
  case 0x00002B08:
    ans = L"WSA_QOS_ESERVICETYPE";
    break;
  case 0x00002B09:
    ans = L"WSA_QOS_EFLOWSPEC";
    break;
  case 0x00002B0A:
    ans = L"WSA_QOS_EPROVSPECBUF";
    break;
  case 0x00002B0B:
    ans = L"WSA_QOS_EFILTERSTYLE";
    break;
  case 0x00002B0C:
    ans = L"WSA_QOS_EFILTERTYPE";
    break;
  case 0x00002B0D:
    ans = L"WSA_QOS_EFILTERCOUNT";
    break;
  case 0x00002B0E:
    ans = L"WSA_QOS_EOBJLENGTH";
    break;
  case 0x00002B0F:
    ans = L"WSA_QOS_EFLOWCOUNT";
    break;
  case 0x00002B10:
    ans = L"WSA_QOS_EUNKOWNPSOBJ";
    break;
  case 0x00002B11:
    ans = L"WSA_QOS_EPOLICYOBJ";
    break;
  case 0x00002B12:
    ans = L"WSA_QOS_EFLOWDESC";
    break;
  case 0x00002B13:
    ans = L"WSA_QOS_EPSFLOWSPEC";
    break;
  case 0x00002B14:
    ans = L"WSA_QOS_EPSFILTERSPEC";
    break;
  case 0x00002B15:
    ans = L"WSA_QOS_ESDMODEOBJ";
    break;
  case 0x00002B16:
    ans = L"WSA_QOS_ESHAPERATEOBJ";
    break;
  case 0x00002B17:
    ans = L"WSA_QOS_RESERVED_PETYPE";
    break;
  case 0x00002B18:
    ans = L"WSA_SECURE_HOST_NOT_FOUND";
    break;
  case 0x00002B19:
    ans = L"WSA_IPSEC_NAME_POLICY_ERROR";
    break;
  case 0x000032C8:
    ans = L"ERROR_IPSEC_QM_POLICY_EXISTS";
    break;
  case 0x000032C9:
    ans = L"ERROR_IPSEC_QM_POLICY_NOT_FOUND";
    break;
  case 0x000032CA:
    ans = L"ERROR_IPSEC_QM_POLICY_IN_USE";
    break;
  case 0x000032CB:
    ans = L"ERROR_IPSEC_MM_POLICY_EXISTS";
    break;
  case 0x000032CC:
    ans = L"ERROR_IPSEC_MM_POLICY_NOT_FOUND";
    break;
  case 0x000032CD:
    ans = L"ERROR_IPSEC_MM_POLICY_IN_USE";
    break;
  case 0x000032CE:
    ans = L"ERROR_IPSEC_MM_FILTER_EXISTS";
    break;
  case 0x000032CF:
    ans = L"ERROR_IPSEC_MM_FILTER_NOT_FOUND";
    break;
  case 0x000032D0:
    ans = L"ERROR_IPSEC_TRANSPORT_FILTER_EXISTS";
    break;
  case 0x000032D1:
    ans = L"ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND";
    break;
  case 0x000032D2:
    ans = L"ERROR_IPSEC_MM_AUTH_EXISTS";
    break;
  case 0x000032D3:
    ans = L"ERROR_IPSEC_MM_AUTH_NOT_FOUND";
    break;
  case 0x000032D4:
    ans = L"ERROR_IPSEC_MM_AUTH_IN_USE";
    break;
  case 0x000032D5:
    ans = L"ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND";
    break;
  case 0x000032D6:
    ans = L"ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND";
    break;
  case 0x000032D7:
    ans = L"ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND";
    break;
  case 0x000032D8:
    ans = L"ERROR_IPSEC_TUNNEL_FILTER_EXISTS";
    break;
  case 0x000032D9:
    ans = L"ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND";
    break;
  case 0x000032DA:
    ans = L"ERROR_IPSEC_MM_FILTER_PENDING_DELETION";
    break;
  case 0x000032DB:
    ans = L"ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION";
    break;
  case 0x000032DC:
    ans = L"ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION";
    break;
  case 0x000032DD:
    ans = L"ERROR_IPSEC_MM_POLICY_PENDING_DELETION";
    break;
  case 0x000032DE:
    ans = L"ERROR_IPSEC_MM_AUTH_PENDING_DELETION";
    break;
  case 0x000032DF:
    ans = L"ERROR_IPSEC_QM_POLICY_PENDING_DELETION";
    break;
  case 0x000032E0:
    ans = L"WARNING_IPSEC_MM_POLICY_PRUNED";
    break;
  case 0x000032E1:
    ans = L"WARNING_IPSEC_QM_POLICY_PRUNED";
    break;
  case 0x000035E8:
    ans = L"ERROR_IPSEC_IKE_NEG_STATUS_BEGIN";
    break;
  case 0x000035E9:
    ans = L"ERROR_IPSEC_IKE_AUTH_FAIL";
    break;
  case 0x000035EA:
    ans = L"ERROR_IPSEC_IKE_ATTRIB_FAIL";
    break;
  case 0x000035EB:
    ans = L"ERROR_IPSEC_IKE_NEGOTIATION_PENDING";
    break;
  case 0x000035EC:
    ans = L"ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR";
    break;
  case 0x000035ED:
    ans = L"ERROR_IPSEC_IKE_TIMED_OUT";
    break;
  case 0x000035EE:
    ans = L"ERROR_IPSEC_IKE_NO_CERT";
    break;
  case 0x000035EF:
    ans = L"ERROR_IPSEC_IKE_SA_DELETED";
    break;
  case 0x000035F0:
    ans = L"ERROR_IPSEC_IKE_SA_REAPED";
    break;
  case 0x000035F1:
    ans = L"ERROR_IPSEC_IKE_MM_ACQUIRE_DROP";
    break;
  case 0x000035F2:
    ans = L"ERROR_IPSEC_IKE_QM_ACQUIRE_DROP";
    break;
  case 0x000035F3:
    ans = L"ERROR_IPSEC_IKE_QUEUE_DROP_MM";
    break;
  case 0x000035F4:
    ans = L"ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM";
    break;
  case 0x000035F5:
    ans = L"ERROR_IPSEC_IKE_DROP_NO_RESPONSE";
    break;
  case 0x000035F6:
    ans = L"ERROR_IPSEC_IKE_MM_DELAY_DROP";
    break;
  case 0x000035F7:
    ans = L"ERROR_IPSEC_IKE_QM_DELAY_DROP";
    break;
  case 0x000035F8:
    ans = L"ERROR_IPSEC_IKE_ERROR";
    break;
  case 0x000035F9:
    ans = L"ERROR_IPSEC_IKE_CRL_FAILED";
    break;
  case 0x000035FA:
    ans = L"ERROR_IPSEC_IKE_INVALID_KEY_USAGE";
    break;
  case 0x000035FB:
    ans = L"ERROR_IPSEC_IKE_INVALID_CERT_TYPE";
    break;
  case 0x000035FC:
    ans = L"ERROR_IPSEC_IKE_NO_PRIVATE_KEY";
    break;
  case 0x000035FD:
    ans = L"ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY";
    break;
  case 0x000035FE:
    ans = L"ERROR_IPSEC_IKE_DH_FAIL";
    break;
  case 0x000035FF:
    ans = L"ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED";
    break;
  case 0x00003600:
    ans = L"ERROR_IPSEC_IKE_INVALID_HEADER";
    break;
  case 0x00003601:
    ans = L"ERROR_IPSEC_IKE_NO_POLICY";
    break;
  case 0x00003602:
    ans = L"ERROR_IPSEC_IKE_INVALID_SIGNATURE";
    break;
  case 0x00003603:
    ans = L"ERROR_IPSEC_IKE_KERBEROS_ERROR";
    break;
  case 0x00003604:
    ans = L"ERROR_IPSEC_IKE_NO_PUBLIC_KEY";
    break;
  case 0x00003605:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR";
    break;
  case 0x00003606:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_SA";
    break;
  case 0x00003607:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_PROP";
    break;
  case 0x00003608:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_TRANS";
    break;
  case 0x00003609:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_KE";
    break;
  case 0x0000360A:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_ID";
    break;
  case 0x0000360B:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_CERT";
    break;
  case 0x0000360C:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ";
    break;
  case 0x0000360D:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_HASH";
    break;
  case 0x0000360E:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_SIG";
    break;
  case 0x0000360F:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_NONCE";
    break;
  case 0x00003610:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY";
    break;
  case 0x00003611:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_DELETE";
    break;
  case 0x00003612:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR";
    break;
  case 0x00003613:
    ans = L"ERROR_IPSEC_IKE_INVALID_PAYLOAD";
    break;
  case 0x00003614:
    ans = L"ERROR_IPSEC_IKE_LOAD_SOFT_SA";
    break;
  case 0x00003615:
    ans = L"ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN";
    break;
  case 0x00003616:
    ans = L"ERROR_IPSEC_IKE_INVALID_COOKIE";
    break;
  case 0x00003617:
    ans = L"ERROR_IPSEC_IKE_NO_PEER_CERT";
    break;
  case 0x00003618:
    ans = L"ERROR_IPSEC_IKE_PEER_CRL_FAILED";
    break;
  case 0x00003619:
    ans = L"ERROR_IPSEC_IKE_POLICY_CHANGE";
    break;
  case 0x0000361A:
    ans = L"ERROR_IPSEC_IKE_NO_MM_POLICY";
    break;
  case 0x0000361B:
    ans = L"ERROR_IPSEC_IKE_NOTCBPRIV";
    break;
  case 0x0000361C:
    ans = L"ERROR_IPSEC_IKE_SECLOADFAIL";
    break;
  case 0x0000361D:
    ans = L"ERROR_IPSEC_IKE_FAILSSPINIT";
    break;
  case 0x0000361E:
    ans = L"ERROR_IPSEC_IKE_FAILQUERYSSP";
    break;
  case 0x0000361F:
    ans = L"ERROR_IPSEC_IKE_SRVACQFAIL";
    break;
  case 0x00003620:
    ans = L"ERROR_IPSEC_IKE_SRVQUERYCRED";
    break;
  case 0x00003621:
    ans = L"ERROR_IPSEC_IKE_GETSPIFAIL";
    break;
  case 0x00003622:
    ans = L"ERROR_IPSEC_IKE_INVALID_FILTER";
    break;
  case 0x00003623:
    ans = L"ERROR_IPSEC_IKE_OUT_OF_MEMORY";
    break;
  case 0x00003624:
    ans = L"ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED";
    break;
  case 0x00003625:
    ans = L"ERROR_IPSEC_IKE_INVALID_POLICY";
    break;
  case 0x00003626:
    ans = L"ERROR_IPSEC_IKE_UNKNOWN_DOI";
    break;
  case 0x00003627:
    ans = L"ERROR_IPSEC_IKE_INVALID_SITUATION";
    break;
  case 0x00003628:
    ans = L"ERROR_IPSEC_IKE_DH_FAILURE";
    break;
  case 0x00003629:
    ans = L"ERROR_IPSEC_IKE_INVALID_GROUP";
    break;
  case 0x0000362A:
    ans = L"ERROR_IPSEC_IKE_ENCRYPT";
    break;
  case 0x0000362B:
    ans = L"ERROR_IPSEC_IKE_DECRYPT";
    break;
  case 0x0000362C:
    ans = L"ERROR_IPSEC_IKE_POLICY_MATCH";
    break;
  case 0x0000362D:
    ans = L"ERROR_IPSEC_IKE_UNSUPPORTED_ID";
    break;
  case 0x0000362E:
    ans = L"ERROR_IPSEC_IKE_INVALID_HASH";
    break;
  case 0x0000362F:
    ans = L"ERROR_IPSEC_IKE_INVALID_HASH_ALG";
    break;
  case 0x00003630:
    ans = L"ERROR_IPSEC_IKE_INVALID_HASH_SIZE";
    break;
  case 0x00003631:
    ans = L"ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG";
    break;
  case 0x00003632:
    ans = L"ERROR_IPSEC_IKE_INVALID_AUTH_ALG";
    break;
  case 0x00003633:
    ans = L"ERROR_IPSEC_IKE_INVALID_SIG";
    break;
  case 0x00003634:
    ans = L"ERROR_IPSEC_IKE_LOAD_FAILED";
    break;
  case 0x00003635:
    ans = L"ERROR_IPSEC_IKE_RPC_DELETE";
    break;
  case 0x00003636:
    ans = L"ERROR_IPSEC_IKE_BENIGN_REINIT";
    break;
  case 0x00003637:
    ans = L"ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY";
    break;
  case 0x00003638:
    ans = L"ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION";
    break;
  case 0x00003639:
    ans = L"ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN";
    break;
  case 0x0000363A:
    ans = L"ERROR_IPSEC_IKE_MM_LIMIT";
    break;
  case 0x0000363B:
    ans = L"ERROR_IPSEC_IKE_NEGOTIATION_DISABLED";
    break;
  case 0x0000363C:
    ans = L"ERROR_IPSEC_IKE_QM_LIMIT";
    break;
  case 0x0000363D:
    ans = L"ERROR_IPSEC_IKE_MM_EXPIRED";
    break;
  case 0x0000363E:
    ans = L"ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID";
    break;
  case 0x0000363F:
    ans = L"ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH";
    break;
  case 0x00003640:
    ans = L"ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID";
    break;
  case 0x00003641:
    ans = L"ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD";
    break;
  case 0x00003642:
    ans = L"ERROR_IPSEC_IKE_DOS_COOKIE_SENT";
    break;
  case 0x00003643:
    ans = L"ERROR_IPSEC_IKE_SHUTTING_DOWN";
    break;
  case 0x00003644:
    ans = L"ERROR_IPSEC_IKE_CGA_AUTH_FAILED";
    break;
  case 0x00003645:
    ans = L"ERROR_IPSEC_IKE_PROCESS_ERR_NATOA";
    break;
  case 0x00003646:
    ans = L"ERROR_IPSEC_IKE_INVALID_MM_FOR_QM";
    break;
  case 0x00003647:
    ans = L"ERROR_IPSEC_IKE_QM_EXPIRED";
    break;
  case 0x00003648:
    ans = L"ERROR_IPSEC_IKE_TOO_MANY_FILTERS";
    break;
  case 0x00003649:
    ans = L"ERROR_IPSEC_IKE_NEG_STATUS_END";
    break;
  case 0x0000364A:
    ans = L"ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL";
    break;
  case 0x0000364B:
    ans = L"ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE";
    break;
  case 0x0000364C:
    ans = L"ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING";
    break;
  case 0x0000364D:
    ans = L"ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING";
    break;
  case 0x0000364E:
    ans = L"ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS";
    break;
  case 0x0000364F:
    ans = L"ERROR_IPSEC_IKE_RATELIMIT_DROP";
    break;
  case 0x00003650:
    ans = L"ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE";
    break;
  case 0x00003651:
    ans = L"ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE";
    break;
  case 0x00003652:
    ans = L"ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE";
    break;
  case 0x00003653:
    ans = L"ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY";
    break;
  case 0x00003654:
    ans = L"ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE";
    break;
  case 0x00003655:
    ans = L"ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END";
    break;
  case 0x00003656:
    ans = L"ERROR_IPSEC_BAD_SPI";
    break;
  case 0x00003657:
    ans = L"ERROR_IPSEC_SA_LIFETIME_EXPIRED";
    break;
  case 0x00003658:
    ans = L"ERROR_IPSEC_WRONG_SA";
    break;
  case 0x00003659:
    ans = L"ERROR_IPSEC_REPLAY_CHECK_FAILED";
    break;
  case 0x0000365A:
    ans = L"ERROR_IPSEC_INVALID_PACKET";
    break;
  case 0x0000365B:
    ans = L"ERROR_IPSEC_INTEGRITY_CHECK_FAILED";
    break;
  case 0x0000365C:
    ans = L"ERROR_IPSEC_CLEAR_TEXT_DROP";
    break;
  case 0x0000365D:
    ans = L"ERROR_IPSEC_AUTH_FIREWALL_DROP";
    break;
  case 0x0000365E:
    ans = L"ERROR_IPSEC_THROTTLE_DROP";
    break;
  case 0x00003665:
    ans = L"ERROR_IPSEC_DOSP_BLOCK";
    break;
  case 0x00003666:
    ans = L"ERROR_IPSEC_DOSP_RECEIVED_MULTICAST";
    break;
  case 0x00003667:
    ans = L"ERROR_IPSEC_DOSP_INVALID_PACKET";
    break;
  case 0x00003668:
    ans = L"ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED";
    break;
  case 0x00003669:
    ans = L"ERROR_IPSEC_DOSP_MAX_ENTRIES";
    break;
  case 0x0000366A:
    ans = L"ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED";
    break;
  case 0x0000366B:
    ans = L"ERROR_IPSEC_DOSP_NOT_INSTALLED";
    break;
  case 0x0000366C:
    ans = L"ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES";
    break;
  case 0x000036B0:
    ans = L"ERROR_SXS_SECTION_NOT_FOUND";
    break;
  case 0x000036B1:
    ans = L"ERROR_SXS_CANT_GEN_ACTCTX";
    break;
  case 0x000036B2:
    ans = L"ERROR_SXS_INVALID_ACTCTXDATA_FORMAT";
    break;
  case 0x000036B3:
    ans = L"ERROR_SXS_ASSEMBLY_NOT_FOUND";
    break;
  case 0x000036B4:
    ans = L"ERROR_SXS_MANIFEST_FORMAT_ERROR";
    break;
  case 0x000036B5:
    ans = L"ERROR_SXS_MANIFEST_PARSE_ERROR";
    break;
  case 0x000036B6:
    ans = L"ERROR_SXS_ACTIVATION_CONTEXT_DISABLED";
    break;
  case 0x000036B7:
    ans = L"ERROR_SXS_KEY_NOT_FOUND";
    break;
  case 0x000036B8:
    ans = L"ERROR_SXS_VERSION_CONFLICT";
    break;
  case 0x000036B9:
    ans = L"ERROR_SXS_WRONG_SECTION_TYPE";
    break;
  case 0x000036BA:
    ans = L"ERROR_SXS_THREAD_QUERIES_DISABLED";
    break;
  case 0x000036BB:
    ans = L"ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET";
    break;
  case 0x000036BC:
    ans = L"ERROR_SXS_UNKNOWN_ENCODING_GROUP";
    break;
  case 0x000036BD:
    ans = L"ERROR_SXS_UNKNOWN_ENCODING";
    break;
  case 0x000036BE:
    ans = L"ERROR_SXS_INVALID_XML_NAMESPACE_URI";
    break;
  case 0x000036BF:
    ans = L"ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED";
    break;
  case 0x000036C0:
    ans = L"ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED";
    break;
  case 0x000036C1:
    ans = L"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE";
    break;
  case 0x000036C2:
    ans = L"ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE";
    break;
  case 0x000036C3:
    ans = L"ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE";
    break;
  case 0x000036C4:
    ans = L"ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT";
    break;
  case 0x000036C5:
    ans = L"ERROR_SXS_DUPLICATE_DLL_NAME";
    break;
  case 0x000036C6:
    ans = L"ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME";
    break;
  case 0x000036C7:
    ans = L"ERROR_SXS_DUPLICATE_CLSID";
    break;
  case 0x000036C8:
    ans = L"ERROR_SXS_DUPLICATE_IID";
    break;
  case 0x000036C9:
    ans = L"ERROR_SXS_DUPLICATE_TLBID";
    break;
  case 0x000036CA:
    ans = L"ERROR_SXS_DUPLICATE_PROGID";
    break;
  case 0x000036CB:
    ans = L"ERROR_SXS_DUPLICATE_ASSEMBLY_NAME";
    break;
  case 0x000036CC:
    ans = L"ERROR_SXS_FILE_HASH_MISMATCH";
    break;
  case 0x000036CD:
    ans = L"ERROR_SXS_POLICY_PARSE_ERROR";
    break;
  case 0x000036CE:
    ans = L"ERROR_SXS_XML_E_MISSINGQUOTE";
    break;
  case 0x000036CF:
    ans = L"ERROR_SXS_XML_E_COMMENTSYNTAX";
    break;
  case 0x000036D0:
    ans = L"ERROR_SXS_XML_E_BADSTARTNAMECHAR";
    break;
  case 0x000036D1:
    ans = L"ERROR_SXS_XML_E_BADNAMECHAR";
    break;
  case 0x000036D2:
    ans = L"ERROR_SXS_XML_E_BADCHARINSTRING";
    break;
  case 0x000036D3:
    ans = L"ERROR_SXS_XML_E_XMLDECLSYNTAX";
    break;
  case 0x000036D4:
    ans = L"ERROR_SXS_XML_E_BADCHARDATA";
    break;
  case 0x000036D5:
    ans = L"ERROR_SXS_XML_E_MISSINGWHITESPACE";
    break;
  case 0x000036D6:
    ans = L"ERROR_SXS_XML_E_EXPECTINGTAGEND";
    break;
  case 0x000036D7:
    ans = L"ERROR_SXS_XML_E_MISSINGSEMICOLON";
    break;
  case 0x000036D8:
    ans = L"ERROR_SXS_XML_E_UNBALANCEDPAREN";
    break;
  case 0x000036D9:
    ans = L"ERROR_SXS_XML_E_INTERNALERROR";
    break;
  case 0x000036DA:
    ans = L"ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE";
    break;
  case 0x000036DB:
    ans = L"ERROR_SXS_XML_E_INCOMPLETE_ENCODING";
    break;
  case 0x000036DC:
    ans = L"ERROR_SXS_XML_E_MISSING_PAREN";
    break;
  case 0x000036DD:
    ans = L"ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE";
    break;
  case 0x000036DE:
    ans = L"ERROR_SXS_XML_E_MULTIPLE_COLONS";
    break;
  case 0x000036DF:
    ans = L"ERROR_SXS_XML_E_INVALID_DECIMAL";
    break;
  case 0x000036E0:
    ans = L"ERROR_SXS_XML_E_INVALID_HEXIDECIMAL";
    break;
  case 0x000036E1:
    ans = L"ERROR_SXS_XML_E_INVALID_UNICODE";
    break;
  case 0x000036E2:
    ans = L"ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK";
    break;
  case 0x000036E3:
    ans = L"ERROR_SXS_XML_E_UNEXPECTEDENDTAG";
    break;
  case 0x000036E4:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDTAG";
    break;
  case 0x000036E5:
    ans = L"ERROR_SXS_XML_E_DUPLICATEATTRIBUTE";
    break;
  case 0x000036E6:
    ans = L"ERROR_SXS_XML_E_MULTIPLEROOTS";
    break;
  case 0x000036E7:
    ans = L"ERROR_SXS_XML_E_INVALIDATROOTLEVEL";
    break;
  case 0x000036E8:
    ans = L"ERROR_SXS_XML_E_BADXMLDECL";
    break;
  case 0x000036E9:
    ans = L"ERROR_SXS_XML_E_MISSINGROOT";
    break;
  case 0x000036EA:
    ans = L"ERROR_SXS_XML_E_UNEXPECTEDEOF";
    break;
  case 0x000036EB:
    ans = L"ERROR_SXS_XML_E_BADPEREFINSUBSET";
    break;
  case 0x000036EC:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDSTARTTAG";
    break;
  case 0x000036ED:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDENDTAG";
    break;
  case 0x000036EE:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDSTRING";
    break;
  case 0x000036EF:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDCOMMENT";
    break;
  case 0x000036F0:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDDECL";
    break;
  case 0x000036F1:
    ans = L"ERROR_SXS_XML_E_UNCLOSEDCDATA";
    break;
  case 0x000036F2:
    ans = L"ERROR_SXS_XML_E_RESERVEDNAMESPACE";
    break;
  case 0x000036F3:
    ans = L"ERROR_SXS_XML_E_INVALIDENCODING";
    break;
  case 0x000036F4:
    ans = L"ERROR_SXS_XML_E_INVALIDSWITCH";
    break;
  case 0x000036F5:
    ans = L"ERROR_SXS_XML_E_BADXMLCASE";
    break;
  case 0x000036F6:
    ans = L"ERROR_SXS_XML_E_INVALID_STANDALONE";
    break;
  case 0x000036F7:
    ans = L"ERROR_SXS_XML_E_UNEXPECTED_STANDALONE";
    break;
  case 0x000036F8:
    ans = L"ERROR_SXS_XML_E_INVALID_VERSION";
    break;
  case 0x000036F9:
    ans = L"ERROR_SXS_XML_E_MISSINGEQUALS";
    break;
  case 0x000036FA:
    ans = L"ERROR_SXS_PROTECTION_RECOVERY_FAILED";
    break;
  case 0x000036FB:
    ans = L"ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT";
    break;
  case 0x000036FC:
    ans = L"ERROR_SXS_PROTECTION_CATALOG_NOT_VALID";
    break;
  case 0x000036FD:
    ans = L"ERROR_SXS_UNTRANSLATABLE_HRESULT";
    break;
  case 0x000036FE:
    ans = L"ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING";
    break;
  case 0x000036FF:
    ans = L"ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE";
    break;
  case 0x00003700:
    ans = L"ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME";
    break;
  case 0x00003701:
    ans = L"ERROR_SXS_ASSEMBLY_MISSING";
    break;
  case 0x00003702:
    ans = L"ERROR_SXS_CORRUPT_ACTIVATION_STACK";
    break;
  case 0x00003703:
    ans = L"ERROR_SXS_CORRUPTION";
    break;
  case 0x00003704:
    ans = L"ERROR_SXS_EARLY_DEACTIVATION";
    break;
  case 0x00003705:
    ans = L"ERROR_SXS_INVALID_DEACTIVATION";
    break;
  case 0x00003706:
    ans = L"ERROR_SXS_MULTIPLE_DEACTIVATION";
    break;
  case 0x00003707:
    ans = L"ERROR_SXS_PROCESS_TERMINATION_REQUESTED";
    break;
  case 0x00003708:
    ans = L"ERROR_SXS_RELEASE_ACTIVATION_CONTEXT";
    break;
  case 0x00003709:
    ans = L"ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY";
    break;
  case 0x0000370A:
    ans = L"ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE";
    break;
  case 0x0000370B:
    ans = L"ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME";
    break;
  case 0x0000370C:
    ans = L"ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE";
    break;
  case 0x0000370D:
    ans = L"ERROR_SXS_IDENTITY_PARSE_ERROR";
    break;
  case 0x0000370E:
    ans = L"ERROR_MALFORMED_SUBSTITUTION_STRING";
    break;
  case 0x0000370F:
    ans = L"ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN";
    break;
  case 0x00003710:
    ans = L"ERROR_UNMAPPED_SUBSTITUTION_STRING";
    break;
  case 0x00003711:
    ans = L"ERROR_SXS_ASSEMBLY_NOT_LOCKED";
    break;
  case 0x00003712:
    ans = L"ERROR_SXS_COMPONENT_STORE_CORRUPT";
    break;
  case 0x00003713:
    ans = L"ERROR_ADVANCED_INSTALLER_FAILED";
    break;
  case 0x00003714:
    ans = L"ERROR_XML_ENCODING_MISMATCH";
    break;
  case 0x00003715:
    ans = L"ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT";
    break;
  case 0x00003716:
    ans = L"ERROR_SXS_IDENTITIES_DIFFERENT";
    break;
  case 0x00003717:
    ans = L"ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT";
    break;
  case 0x00003718:
    ans = L"ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY";
    break;
  case 0x00003719:
    ans = L"ERROR_SXS_MANIFEST_TOO_BIG";
    break;
  case 0x0000371A:
    ans = L"ERROR_SXS_SETTING_NOT_REGISTERED";
    break;
  case 0x0000371B:
    ans = L"ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE";
    break;
  case 0x0000371C:
    ans = L"ERROR_SMI_PRIMITIVE_INSTALLER_FAILED";
    break;
  case 0x0000371D:
    ans = L"ERROR_GENERIC_COMMAND_FAILED";
    break;
  case 0x0000371E:
    ans = L"ERROR_SXS_FILE_HASH_MISSING";
    break;
  case 0x00003A98:
    ans = L"ERROR_EVT_INVALID_CHANNEL_PATH";
    break;
  case 0x00003A99:
    ans = L"ERROR_EVT_INVALID_QUERY";
    break;
  case 0x00003A9A:
    ans = L"ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND";
    break;
  case 0x00003A9B:
    ans = L"ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND";
    break;
  case 0x00003A9C:
    ans = L"ERROR_EVT_INVALID_PUBLISHER_NAME";
    break;
  case 0x00003A9D:
    ans = L"ERROR_EVT_INVALID_EVENT_DATA";
    break;
  case 0x00003A9F:
    ans = L"ERROR_EVT_CHANNEL_NOT_FOUND";
    break;
  case 0x00003AA0:
    ans = L"ERROR_EVT_MALFORMED_XML_TEXT";
    break;
  case 0x00003AA1:
    ans = L"ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL";
    break;
  case 0x00003AA2:
    ans = L"ERROR_EVT_CONFIGURATION_ERROR";
    break;
  case 0x00003AA3:
    ans = L"ERROR_EVT_QUERY_RESULT_STALE";
    break;
  case 0x00003AA4:
    ans = L"ERROR_EVT_QUERY_RESULT_INVALID_POSITION";
    break;
  case 0x00003AA5:
    ans = L"ERROR_EVT_NON_VALIDATING_MSXML";
    break;
  case 0x00003AA6:
    ans = L"ERROR_EVT_FILTER_ALREADYSCOPED";
    break;
  case 0x00003AA7:
    ans = L"ERROR_EVT_FILTER_NOTELTSET";
    break;
  case 0x00003AA8:
    ans = L"ERROR_EVT_FILTER_INVARG";
    break;
  case 0x00003AA9:
    ans = L"ERROR_EVT_FILTER_INVTEST";
    break;
  case 0x00003AAA:
    ans = L"ERROR_EVT_FILTER_INVTYPE";
    break;
  case 0x00003AAB:
    ans = L"ERROR_EVT_FILTER_PARSEERR";
    break;
  case 0x00003AAC:
    ans = L"ERROR_EVT_FILTER_UNSUPPORTEDOP";
    break;
  case 0x00003AAD:
    ans = L"ERROR_EVT_FILTER_UNEXPECTEDTOKEN";
    break;
  case 0x00003AAE:
    ans = L"ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL";
    break;
  case 0x00003AAF:
    ans = L"ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE";
    break;
  case 0x00003AB0:
    ans = L"ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE";
    break;
  case 0x00003AB1:
    ans = L"ERROR_EVT_CHANNEL_CANNOT_ACTIVATE";
    break;
  case 0x00003AB2:
    ans = L"ERROR_EVT_FILTER_TOO_COMPLEX";
    break;
  case 0x00003AB3:
    ans = L"ERROR_EVT_MESSAGE_NOT_FOUND";
    break;
  case 0x00003AB4:
    ans = L"ERROR_EVT_MESSAGE_ID_NOT_FOUND";
    break;
  case 0x00003AB5:
    ans = L"ERROR_EVT_UNRESOLVED_VALUE_INSERT";
    break;
  case 0x00003AB6:
    ans = L"ERROR_EVT_UNRESOLVED_PARAMETER_INSERT";
    break;
  case 0x00003AB7:
    ans = L"ERROR_EVT_MAX_INSERTS_REACHED";
    break;
  case 0x00003AB8:
    ans = L"ERROR_EVT_EVENT_DEFINITION_NOT_FOUND";
    break;
  case 0x00003AB9:
    ans = L"ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND";
    break;
  case 0x00003ABA:
    ans = L"ERROR_EVT_VERSION_TOO_OLD";
    break;
  case 0x00003ABB:
    ans = L"ERROR_EVT_VERSION_TOO_NEW";
    break;
  case 0x00003ABC:
    ans = L"ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY";
    break;
  case 0x00003ABD:
    ans = L"ERROR_EVT_PUBLISHER_DISABLED";
    break;
  case 0x00003ABE:
    ans = L"ERROR_EVT_FILTER_OUT_OF_RANGE";
    break;
  case 0x00003AE8:
    ans = L"ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE";
    break;
  case 0x00003AE9:
    ans = L"ERROR_EC_LOG_DISABLED";
    break;
  case 0x00003AEA:
    ans = L"ERROR_EC_CIRCULAR_FORWARDING";
    break;
  case 0x00003AEB:
    ans = L"ERROR_EC_CREDSTORE_FULL";
    break;
  case 0x00003AEC:
    ans = L"ERROR_EC_CRED_NOT_FOUND";
    break;
  case 0x00003AED:
    ans = L"ERROR_EC_NO_ACTIVE_CHANNEL";
    break;
  case 0x00003AFC:
    ans = L"ERROR_MUI_FILE_NOT_FOUND";
    break;
  case 0x00003AFD:
    ans = L"ERROR_MUI_INVALID_FILE";
    break;
  case 0x00003AFE:
    ans = L"ERROR_MUI_INVALID_RC_CONFIG";
    break;
  case 0x00003AFF:
    ans = L"ERROR_MUI_INVALID_LOCALE_NAME";
    break;
  case 0x00003B00:
    ans = L"ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME";
    break;
  case 0x00003B01:
    ans = L"ERROR_MUI_FILE_NOT_LOADED";
    break;
  case 0x00003B02:
    ans = L"ERROR_RESOURCE_ENUM_USER_STOP";
    break;
  case 0x00003B03:
    ans = L"ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED";
    break;
  case 0x00003B04:
    ans = L"ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME";
    break;
  case 0x00003B06:
    ans = L"ERROR_MRM_RUNTIME_NO_DEFAULT_OR_NEUTRAL_RESOURCE";
    break;
  case 0x00003B07:
    ans = L"ERROR_MRM_INVALID_PRICONFIG";
    break;
  case 0x00003B08:
    ans = L"ERROR_MRM_INVALID_FILE_TYPE";
    break;
  case 0x00003B09:
    ans = L"ERROR_MRM_UNKNOWN_QUALIFIER";
    break;
  case 0x00003B0A:
    ans = L"ERROR_MRM_INVALID_QUALIFIER_VALUE";
    break;
  case 0x00003B0B:
    ans = L"ERROR_MRM_NO_CANDIDATE";
    break;
  case 0x00003B0C:
    ans = L"ERROR_MRM_NO_MATCH_OR_DEFAULT_CANDIDATE";
    break;
  case 0x00003B0D:
    ans = L"ERROR_MRM_RESOURCE_TYPE_MISMATCH";
    break;
  case 0x00003B0E:
    ans = L"ERROR_MRM_DUPLICATE_MAP_NAME";
    break;
  case 0x00003B0F:
    ans = L"ERROR_MRM_DUPLICATE_ENTRY";
    break;
  case 0x00003B10:
    ans = L"ERROR_MRM_INVALID_RESOURCE_IDENTIFIER";
    break;
  case 0x00003B11:
    ans = L"ERROR_MRM_FILEPATH_TOO_LONG";
    break;
  case 0x00003B12:
    ans = L"ERROR_MRM_UNSUPPORTED_DIRECTORY_TYPE";
    break;
  case 0x00003B16:
    ans = L"ERROR_MRM_INVALID_PRI_FILE";
    break;
  case 0x00003B17:
    ans = L"ERROR_MRM_NAMED_RESOURCE_NOT_FOUND";
    break;
  case 0x00003B1F:
    ans = L"ERROR_MRM_MAP_NOT_FOUND";
    break;
  case 0x00003B20:
    ans = L"ERROR_MRM_UNSUPPORTED_PROFILE_TYPE";
    break;
  case 0x00003B21:
    ans = L"ERROR_MRM_INVALID_QUALIFIER_OPERATOR";
    break;
  case 0x00003B22:
    ans = L"ERROR_MRM_INDETERMINATE_QUALIFIER_VALUE";
    break;
  case 0x00003B23:
    ans = L"ERROR_MRM_AUTOMERGE_ENABLED";
    break;
  case 0x00003B24:
    ans = L"ERROR_MRM_TOO_MANY_RESOURCES";
    break;
  case 0x00003B25:
    ans = L"ERROR_MRM_UNSUPPORTED_FILE_TYPE_FOR_MERGE";
    break;
  case 0x00003B26:
    ans = L"ERROR_MRM_UNSUPPORTED_FILE_TYPE_FOR_LOAD_UNLOAD_PRI_FILE";
    break;
  case 0x00003B27:
    ans = L"ERROR_MRM_NO_CURRENT_VIEW_ON_THREAD";
    break;
  case 0x00003B28:
    ans = L"ERROR_DIFFERENT_PROFILE_RESOURCE_MANAGER_EXIST";
    break;
  case 0x00003B29:
    ans = L"ERROR_OPERATION_NOT_ALLOWED_FROM_SYSTEM_COMPONENT";
    break;
  case 0x00003B2A:
    ans = L"ERROR_MRM_DIRECT_REF_TO_NON_DEFAULT_RESOURCE";
    break;
  case 0x00003B2B:
    ans = L"ERROR_MRM_GENERATION_COUNT_MISMATCH";
    break;
  case 0x00003B2C:
    ans = L"ERROR_PRI_MERGE_VERSION_MISMATCH";
    break;
  case 0x00003B2D:
    ans = L"ERROR_PRI_MERGE_MISSING_SCHEMA";
    break;
  case 0x00003B2E:
    ans = L"ERROR_PRI_MERGE_LOAD_FILE_FAILED";
    break;
  case 0x00003B2F:
    ans = L"ERROR_PRI_MERGE_ADD_FILE_FAILED";
    break;
  case 0x00003B30:
    ans = L"ERROR_PRI_MERGE_WRITE_FILE_FAILED";
    break;
  case 0x00003B31:
    ans = L"ERROR_PRI_MERGE_MULTIPLE_PACKAGE_FAMILIES_NOT_ALLOWED";
    break;
  case 0x00003B32:
    ans = L"ERROR_PRI_MERGE_MULTIPLE_MAIN_PACKAGES_NOT_ALLOWED";
    break;
  case 0x00003B33:
    ans = L"ERROR_PRI_MERGE_BUNDLE_PACKAGES_NOT_ALLOWED";
    break;
  case 0x00003B34:
    ans = L"ERROR_PRI_MERGE_MAIN_PACKAGE_REQUIRED";
    break;
  case 0x00003B35:
    ans = L"ERROR_PRI_MERGE_RESOURCE_PACKAGE_REQUIRED";
    break;
  case 0x00003B36:
    ans = L"ERROR_PRI_MERGE_INVALID_FILE_NAME";
    break;
  case 0x00003B37:
    ans = L"ERROR_MRM_PACKAGE_NOT_FOUND";
    break;
  case 0x00003B60:
    ans = L"ERROR_MCA_INVALID_CAPABILITIES_STRING";
    break;
  case 0x00003B61:
    ans = L"ERROR_MCA_INVALID_VCP_VERSION";
    break;
  case 0x00003B62:
    ans = L"ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION";
    break;
  case 0x00003B63:
    ans = L"ERROR_MCA_MCCS_VERSION_MISMATCH";
    break;
  case 0x00003B64:
    ans = L"ERROR_MCA_UNSUPPORTED_MCCS_VERSION";
    break;
  case 0x00003B65:
    ans = L"ERROR_MCA_INTERNAL_ERROR";
    break;
  case 0x00003B66:
    ans = L"ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED";
    break;
  case 0x00003B67:
    ans = L"ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE";
    break;
  case 0x00003B92:
    ans = L"ERROR_AMBIGUOUS_SYSTEM_DEVICE";
    break;
  case 0x00003BC3:
    ans = L"ERROR_SYSTEM_DEVICE_NOT_FOUND";
    break;
  case 0x00003BC4:
    ans = L"ERROR_HASH_NOT_SUPPORTED";
    break;
  case 0x00003BC5:
    ans = L"ERROR_HASH_NOT_PRESENT";
    break;
  case 0x00003BD9:
    ans = L"ERROR_SECONDARY_IC_PROVIDER_NOT_REGISTERED";
    break;
  case 0x00003BDA:
    ans = L"ERROR_GPIO_CLIENT_INFORMATION_INVALID";
    break;
  case 0x00003BDB:
    ans = L"ERROR_GPIO_VERSION_NOT_SUPPORTED";
    break;
  case 0x00003BDC:
    ans = L"ERROR_GPIO_INVALID_REGISTRATION_PACKET";
    break;
  case 0x00003BDD:
    ans = L"ERROR_GPIO_OPERATION_DENIED";
    break;
  case 0x00003BDE:
    ans = L"ERROR_GPIO_INCOMPATIBLE_CONNECT_MODE";
    break;
  case 0x00003BDF:
    ans = L"ERROR_GPIO_INTERRUPT_ALREADY_UNMASKED";
    break;
  case 0x00003C28:
    ans = L"ERROR_CANNOT_SWITCH_RUNLEVEL";
    break;
  case 0x00003C29:
    ans = L"ERROR_INVALID_RUNLEVEL_SETTING";
    break;
  case 0x00003C2A:
    ans = L"ERROR_RUNLEVEL_SWITCH_TIMEOUT";
    break;
  case 0x00003C2B:
    ans = L"ERROR_RUNLEVEL_SWITCH_AGENT_TIMEOUT";
    break;
  case 0x00003C2C:
    ans = L"ERROR_RUNLEVEL_SWITCH_IN_PROGRESS";
    break;
  case 0x00003C2D:
    ans = L"ERROR_SERVICES_FAILED_AUTOSTART";
    break;
  case 0x00003C8D:
    ans = L"ERROR_COM_TASK_STOP_PENDING";
    break;
  case 0x00003CF0:
    ans = L"ERROR_INSTALL_OPEN_PACKAGE_FAILED";
    break;
  case 0x00003CF1:
    ans = L"ERROR_INSTALL_PACKAGE_NOT_FOUND";
    break;
  case 0x00003CF2:
    ans = L"ERROR_INSTALL_INVALID_PACKAGE";
    break;
  case 0x00003CF3:
    ans = L"ERROR_INSTALL_RESOLVE_DEPENDENCY_FAILED";
    break;
  case 0x00003CF4:
    ans = L"ERROR_INSTALL_OUT_OF_DISK_SPACE";
    break;
  case 0x00003CF5:
    ans = L"ERROR_INSTALL_NETWORK_FAILURE";
    break;
  case 0x00003CF6:
    ans = L"ERROR_INSTALL_REGISTRATION_FAILURE";
    break;
  case 0x00003CF7:
    ans = L"ERROR_INSTALL_DEREGISTRATION_FAILURE";
    break;
  case 0x00003CF8:
    ans = L"ERROR_INSTALL_CANCEL";
    break;
  case 0x00003CF9:
    ans = L"ERROR_INSTALL_FAILED";
    break;
  case 0x00003CFA:
    ans = L"ERROR_REMOVE_FAILED";
    break;
  case 0x00003CFB:
    ans = L"ERROR_PACKAGE_ALREADY_EXISTS";
    break;
  case 0x00003CFC:
    ans = L"ERROR_NEEDS_REMEDIATION";
    break;
  case 0x00003CFD:
    ans = L"ERROR_INSTALL_PREREQUISITE_FAILED";
    break;
  case 0x00003CFE:
    ans = L"ERROR_PACKAGE_REPOSITORY_CORRUPTED";
    break;
  case 0x00003CFF:
    ans = L"ERROR_INSTALL_POLICY_FAILURE";
    break;
  case 0x00003D00:
    ans = L"ERROR_PACKAGE_UPDATING";
    break;
  case 0x00003D01:
    ans = L"ERROR_DEPLOYMENT_BLOCKED_BY_POLICY";
    break;
  case 0x00003D02:
    ans = L"ERROR_PACKAGES_IN_USE";
    break;
  case 0x00003D03:
    ans = L"ERROR_RECOVERY_FILE_CORRUPT";
    break;
  case 0x00003D04:
    ans = L"ERROR_INVALID_STAGED_SIGNATURE";
    break;
  case 0x00003D05:
    ans = L"ERROR_DELETING_EXISTING_APPLICATIONDATA_STORE_FAILED";
    break;
  case 0x00003D06:
    ans = L"ERROR_INSTALL_PACKAGE_DOWNGRADE";
    break;
  case 0x00003D07:
    ans = L"ERROR_SYSTEM_NEEDS_REMEDIATION";
    break;
  case 0x00003D08:
    ans = L"ERROR_APPX_INTEGRITY_FAILURE_CLR_NGEN";
    break;
  case 0x00003D09:
    ans = L"ERROR_RESILIENCY_FILE_CORRUPT";
    break;
  case 0x00003D0A:
    ans = L"ERROR_INSTALL_FIREWALL_SERVICE_NOT_RUNNING";
    break;
  case 0x00003D0B:
    ans = L"ERROR_PACKAGE_MOVE_FAILED";
    break;
  case 0x00003D0C:
    ans = L"ERROR_INSTALL_VOLUME_NOT_EMPTY";
    break;
  case 0x00003D0D:
    ans = L"ERROR_INSTALL_VOLUME_OFFLINE";
    break;
  case 0x00003D0E:
    ans = L"ERROR_INSTALL_VOLUME_CORRUPT";
    break;
  case 0x00003D0F:
    ans = L"ERROR_NEEDS_REGISTRATION";
    break;
  case 0x00003D10:
    ans = L"ERROR_INSTALL_WRONG_PROCESSOR_ARCHITECTURE";
    break;
  case 0x00003D11:
    ans = L"ERROR_DEV_SIDELOAD_LIMIT_EXCEEDED";
    break;
  case 0x00003D12:
    ans = L"ERROR_INSTALL_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE";
    break;
  case 0x00003D13:
    ans = L"ERROR_PACKAGE_NOT_SUPPORTED_ON_FILESYSTEM";
    break;
  case 0x00003D14:
    ans = L"ERROR_PACKAGE_MOVE_BLOCKED_BY_STREAMING";
    break;
  case 0x00003D15:
    ans = L"ERROR_INSTALL_OPTIONAL_PACKAGE_APPLICATIONID_NOT_UNIQUE";
    break;
  case 0x00003D16:
    ans = L"ERROR_PACKAGE_STAGING_ONHOLD";
    break;
  case 0x00003D17:
    ans = L"ERROR_INSTALL_INVALID_RELATED_SET_UPDATE";
    break;
  case 0x00003D18:
    ans = L"ERROR_INSTALL_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE_FULLTRUST_CAPABILITY";
    break;
  case 0x00003D19:
    ans = L"ERROR_DEPLOYMENT_BLOCKED_BY_USER_LOG_OFF";
    break;
  case 0x00003D1A:
    ans = L"ERROR_PROVISION_OPTIONAL_PACKAGE_REQUIRES_MAIN_PACKAGE_PROVISIONED";
    break;
  case 0x00003D1B:
    ans = L"ERROR_PACKAGES_REPUTATION_CHECK_FAILED";
    break;
  case 0x00003D1C:
    ans = L"ERROR_PACKAGES_REPUTATION_CHECK_TIMEDOUT";
    break;
  case 0x00003D1D:
    ans = L"ERROR_DEPLOYMENT_OPTION_NOT_SUPPORTED";
    break;
  case 0x00003D1E:
    ans = L"ERROR_APPINSTALLER_ACTIVATION_BLOCKED";
    break;
  case 0x00003D1F:
    ans = L"ERROR_REGISTRATION_FROM_REMOTE_DRIVE_NOT_SUPPORTED";
    break;
  case 0x00003D54:
    ans = L"APPMODEL_ERROR_NO_PACKAGE";
    break;
  case 0x00003D55:
    ans = L"APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT";
    break;
  case 0x00003D56:
    ans = L"APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT";
    break;
  case 0x00003D57:
    ans = L"APPMODEL_ERROR_NO_APPLICATION";
    break;
  case 0x00003D58:
    ans = L"APPMODEL_ERROR_DYNAMIC_PROPERTY_READ_FAILED";
    break;
  case 0x00003D59:
    ans = L"APPMODEL_ERROR_DYNAMIC_PROPERTY_INVALID";
    break;
  case 0x00003D5A:
    ans = L"APPMODEL_ERROR_PACKAGE_NOT_AVAILABLE";
    break;
  case 0x00003DB8:
    ans = L"ERROR_STATE_LOAD_STORE_FAILED";
    break;
  case 0x00003DB9:
    ans = L"ERROR_STATE_GET_VERSION_FAILED";
    break;
  case 0x00003DBA:
    ans = L"ERROR_STATE_SET_VERSION_FAILED";
    break;
  case 0x00003DBB:
    ans = L"ERROR_STATE_STRUCTURED_RESET_FAILED";
    break;
  case 0x00003DBC:
    ans = L"ERROR_STATE_OPEN_CONTAINER_FAILED";
    break;
  case 0x00003DBD:
    ans = L"ERROR_STATE_CREATE_CONTAINER_FAILED";
    break;
  case 0x00003DBE:
    ans = L"ERROR_STATE_DELETE_CONTAINER_FAILED";
    break;
  case 0x00003DBF:
    ans = L"ERROR_STATE_READ_SETTING_FAILED";
    break;
  case 0x00003DC0:
    ans = L"ERROR_STATE_WRITE_SETTING_FAILED";
    break;
  case 0x00003DC1:
    ans = L"ERROR_STATE_DELETE_SETTING_FAILED";
    break;
  case 0x00003DC2:
    ans = L"ERROR_STATE_QUERY_SETTING_FAILED";
    break;
  case 0x00003DC3:
    ans = L"ERROR_STATE_READ_COMPOSITE_SETTING_FAILED";
    break;
  case 0x00003DC4:
    ans = L"ERROR_STATE_WRITE_COMPOSITE_SETTING_FAILED";
    break;
  case 0x00003DC5:
    ans = L"ERROR_STATE_ENUMERATE_CONTAINER_FAILED";
    break;
  case 0x00003DC6:
    ans = L"ERROR_STATE_ENUMERATE_SETTINGS_FAILED";
    break;
  case 0x00003DC7:
    ans = L"ERROR_STATE_COMPOSITE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED";
    break;
  case 0x00003DC8:
    ans = L"ERROR_STATE_SETTING_VALUE_SIZE_LIMIT_EXCEEDED";
    break;
  case 0x00003DC9:
    ans = L"ERROR_STATE_SETTING_NAME_SIZE_LIMIT_EXCEEDED";
    break;
  case 0x00003DCA:
    ans = L"ERROR_STATE_CONTAINER_NAME_SIZE_LIMIT_EXCEEDED";
    break;
  case 0x00003DE1:
    ans = L"ERROR_API_UNAVAILABLE";
    break;
  case 0x00003DF5:
    ans = L"STORE_ERROR_UNLICENSED";
    break;
  case 0x00003DF6:
    ans = L"STORE_ERROR_UNLICENSED_USER";
    break;
  case 0x00003DF7:
    ans = L"STORE_ERROR_PENDING_COM_TRANSACTION";
    break;
  case 0x00003DF8:
    ans = L"STORE_ERROR_LICENSE_REVOKED";
    break;
  case 0x8000FFFF:
    ans = L"E_UNEXPECTED";
    break;
  case 0x80004001:
    ans = L"E_NOTIMPL";
    break;
  case 0x8007000E:
    ans = L"E_OUTOFMEMORY";
    break;
  case 0x80070057:
    ans = L"E_INVALIDARG";
    break;
  case 0x80004002:
    ans = L"E_NOINTERFACE";
    break;
  case 0x80004003:
    ans = L"E_POINTER";
    break;
  case 0x80070006:
    ans = L"E_HANDLE";
    break;
  case 0x80004004:
    ans = L"E_ABORT";
    break;
  case 0x80004005:
    ans = L"E_FAIL";
    break;
  case 0x80070005:
    ans = L"E_ACCESSDENIED";
    break;
  case 0x80000001:
    ans = L"E_NOTIMPL";
    break;
  case 0x80000002:
    ans = L"E_OUTOFMEMORY";
    break;
  case 0x80000003:
    ans = L"E_INVALIDARG";
    break;
  case 0x80000004:
    ans = L"E_NOINTERFACE";
    break;
  case 0x80000005:
    ans = L"E_POINTER";
    break;
  case 0x80000006:
    ans = L"E_HANDLE";
    break;
  case 0x80000007:
    ans = L"E_ABORT";
    break;
  case 0x80000008:
    ans = L"E_FAIL";
    break;
  case 0x80000009:
    ans = L"E_ACCESSDENIED";
    break;
  case 0x8000000A:
    ans = L"E_PENDING";
    break;
  case 0x8000000B:
    ans = L"E_BOUNDS";
    break;
  case 0x8000000C:
    ans = L"E_CHANGED_STATE";
    break;
  case 0x8000000D:
    ans = L"E_ILLEGAL_STATE_CHANGE";
    break;
  case 0x8000000E:
    ans = L"E_ILLEGAL_METHOD_CALL";
    break;
  case 0x8000000F:
    ans = L"RO_E_METADATA_NAME_NOT_FOUND";
    break;
  case 0x80000010:
    ans = L"RO_E_METADATA_NAME_IS_NAMESPACE";
    break;
  case 0x80000011:
    ans = L"RO_E_METADATA_INVALID_TYPE_FORMAT";
    break;
  case 0x80000012:
    ans = L"RO_E_INVALID_METADATA_FILE";
    break;
  case 0x80000013:
    ans = L"RO_E_CLOSED";
    break;
  case 0x80000014:
    ans = L"RO_E_EXCLUSIVE_WRITE";
    break;
  case 0x80000015:
    ans = L"RO_E_CHANGE_NOTIFICATION_IN_PROGRESS";
    break;
  case 0x80000016:
    ans = L"RO_E_ERROR_STRING_NOT_FOUND";
    break;
  case 0x80000017:
    ans = L"E_STRING_NOT_NULL_TERMINATED";
    break;
  case 0x80000018:
    ans = L"E_ILLEGAL_DELEGATE_ASSIGNMENT";
    break;
  case 0x80000019:
    ans = L"E_ASYNC_OPERATION_NOT_STARTED";
    break;
  case 0x8000001A:
    ans = L"E_APPLICATION_EXITING";
    break;
  case 0x8000001B:
    ans = L"E_APPLICATION_VIEW_EXITING";
    break;
  case 0x8000001C:
    ans = L"RO_E_MUST_BE_AGILE";
    break;
  case 0x8000001D:
    ans = L"RO_E_UNSUPPORTED_FROM_MTA";
    break;
  case 0x8000001E:
    ans = L"RO_E_COMMITTED";
    break;
  case 0x8000001F:
    ans = L"RO_E_BLOCKED_CROSS_ASTA_CALL";
    break;
  case 0x80000020:
    ans = L"RO_E_CANNOT_ACTIVATE_FULL_TRUST_SERVER";
    break;
  case 0x80000021:
    ans = L"RO_E_CANNOT_ACTIVATE_UNIVERSAL_APPLICATION_SERVER";
    break;
  case 0x80004006:
    ans = L"CO_E_INIT_TLS";
    break;
  case 0x80004007:
    ans = L"CO_E_INIT_SHARED_ALLOCATOR";
    break;
  case 0x80004008:
    ans = L"CO_E_INIT_MEMORY_ALLOCATOR";
    break;
  case 0x80004009:
    ans = L"CO_E_INIT_CLASS_CACHE";
    break;
  case 0x8000400A:
    ans = L"CO_E_INIT_RPC_CHANNEL";
    break;
  case 0x8000400B:
    ans = L"CO_E_INIT_TLS_SET_CHANNEL_CONTROL";
    break;
  case 0x8000400C:
    ans = L"CO_E_INIT_TLS_CHANNEL_CONTROL";
    break;
  case 0x8000400D:
    ans = L"CO_E_INIT_UNACCEPTED_USER_ALLOCATOR";
    break;
  case 0x8000400E:
    ans = L"CO_E_INIT_SCM_MUTEX_EXISTS";
    break;
  case 0x8000400F:
    ans = L"CO_E_INIT_SCM_FILE_MAPPING_EXISTS";
    break;
  case 0x80004010:
    ans = L"CO_E_INIT_SCM_MAP_VIEW_OF_FILE";
    break;
  case 0x80004011:
    ans = L"CO_E_INIT_SCM_EXEC_FAILURE";
    break;
  case 0x80004012:
    ans = L"CO_E_INIT_ONLY_SINGLE_THREADED";
    break;
  case 0x80004013:
    ans = L"CO_E_CANT_REMOTE";
    break;
  case 0x80004014:
    ans = L"CO_E_BAD_SERVER_NAME";
    break;
  case 0x80004015:
    ans = L"CO_E_WRONG_SERVER_IDENTITY";
    break;
  case 0x80004016:
    ans = L"CO_E_OLE1DDE_DISABLED";
    break;
  case 0x80004017:
    ans = L"CO_E_RUNAS_SYNTAX";
    break;
  case 0x80004018:
    ans = L"CO_E_CREATEPROCESS_FAILURE";
    break;
  case 0x80004019:
    ans = L"CO_E_RUNAS_CREATEPROCESS_FAILURE";
    break;
  case 0x8000401A:
    ans = L"CO_E_RUNAS_LOGON_FAILURE";
    break;
  case 0x8000401B:
    ans = L"CO_E_LAUNCH_PERMSSION_DENIED";
    break;
  case 0x8000401C:
    ans = L"CO_E_START_SERVICE_FAILURE";
    break;
  case 0x8000401D:
    ans = L"CO_E_REMOTE_COMMUNICATION_FAILURE";
    break;
  case 0x8000401E:
    ans = L"CO_E_SERVER_START_TIMEOUT";
    break;
  case 0x8000401F:
    ans = L"CO_E_CLSREG_INCONSISTENT";
    break;
  case 0x80004020:
    ans = L"CO_E_IIDREG_INCONSISTENT";
    break;
  case 0x80004021:
    ans = L"CO_E_NOT_SUPPORTED";
    break;
  case 0x80004022:
    ans = L"CO_E_RELOAD_DLL";
    break;
  case 0x80004023:
    ans = L"CO_E_MSI_ERROR";
    break;
  case 0x80004024:
    ans = L"CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT";
    break;
  case 0x80004025:
    ans = L"CO_E_SERVER_PAUSED";
    break;
  case 0x80004026:
    ans = L"CO_E_SERVER_NOT_PAUSED";
    break;
  case 0x80004027:
    ans = L"CO_E_CLASS_DISABLED";
    break;
  case 0x80004028:
    ans = L"CO_E_CLRNOTAVAILABLE";
    break;
  case 0x80004029:
    ans = L"CO_E_ASYNC_WORK_REJECTED";
    break;
  case 0x8000402A:
    ans = L"CO_E_SERVER_INIT_TIMEOUT";
    break;
  case 0x8000402B:
    ans = L"CO_E_NO_SECCTX_IN_ACTIVATE";
    break;
  case 0x80004030:
    ans = L"CO_E_TRACKER_CONFIG";
    break;
  case 0x80004031:
    ans = L"CO_E_THREADPOOL_CONFIG";
    break;
  case 0x80004032:
    ans = L"CO_E_SXS_CONFIG";
    break;
  case 0x80004033:
    ans = L"CO_E_MALFORMED_SPN";
    break;
  case 0x80004034:
    ans = L"CO_E_UNREVOKED_REGISTRATION_ON_APARTMENT_SHUTDOWN";
    break;
  case 0x80004035:
    ans = L"CO_E_PREMATURE_STUB_RUNDOWN";
    break;
  case 0x80040000:
    ans = L"OLE_E_OLEVERB";
    break;
  case 0x80040001:
    ans = L"OLE_E_ADVF";
    break;
  case 0x80040002:
    ans = L"OLE_E_ENUM_NOMORE";
    break;
  case 0x80040003:
    ans = L"OLE_E_ADVISENOTSUPPORTED";
    break;
  case 0x80040004:
    ans = L"OLE_E_NOCONNECTION";
    break;
  case 0x80040005:
    ans = L"OLE_E_NOTRUNNING";
    break;
  case 0x80040006:
    ans = L"OLE_E_NOCACHE";
    break;
  case 0x80040007:
    ans = L"OLE_E_BLANK";
    break;
  case 0x80040008:
    ans = L"OLE_E_CLASSDIFF";
    break;
  case 0x80040009:
    ans = L"OLE_E_CANT_GETMONIKER";
    break;
  case 0x8004000A:
    ans = L"OLE_E_CANT_BINDTOSOURCE";
    break;
  case 0x8004000B:
    ans = L"OLE_E_STATIC";
    break;
  case 0x8004000C:
    ans = L"OLE_E_PROMPTSAVECANCELLED";
    break;
  case 0x8004000D:
    ans = L"OLE_E_INVALIDRECT";
    break;
  case 0x8004000E:
    ans = L"OLE_E_WRONGCOMPOBJ";
    break;
  case 0x8004000F:
    ans = L"OLE_E_INVALIDHWND";
    break;
  case 0x80040010:
    ans = L"OLE_E_NOT_INPLACEACTIVE";
    break;
  case 0x80040011:
    ans = L"OLE_E_CANTCONVERT";
    break;
  case 0x80040012:
    ans = L"OLE_E_NOSTORAGE";
    break;
  case 0x80040064:
    ans = L"DV_E_FORMATETC";
    break;
  case 0x80040065:
    ans = L"DV_E_DVTARGETDEVICE";
    break;
  case 0x80040066:
    ans = L"DV_E_STGMEDIUM";
    break;
  case 0x80040067:
    ans = L"DV_E_STATDATA";
    break;
  case 0x80040068:
    ans = L"DV_E_LINDEX";
    break;
  case 0x80040069:
    ans = L"DV_E_TYMED";
    break;
  case 0x8004006A:
    ans = L"DV_E_CLIPFORMAT";
    break;
  case 0x8004006B:
    ans = L"DV_E_DVASPECT";
    break;
  case 0x8004006C:
    ans = L"DV_E_DVTARGETDEVICE_SIZE";
    break;
  case 0x8004006D:
    ans = L"DV_E_NOIVIEWOBJECT";
    break;
  case 0x80040100:
    ans = L"DRAGDROP_E_NOTREGISTERED";
    break;
  case 0x80040101:
    ans = L"DRAGDROP_E_ALREADYREGISTERED";
    break;
  case 0x80040102:
    ans = L"DRAGDROP_E_INVALIDHWND";
    break;
  case 0x80040103:
    ans = L"DRAGDROP_E_CONCURRENT_DRAG_ATTEMPTED";
    break;
  case 0x80040110:
    ans = L"CLASS_E_NOAGGREGATION";
    break;
  case 0x80040111:
    ans = L"CLASS_E_CLASSNOTAVAILABLE";
    break;
  case 0x80040112:
    ans = L"CLASS_E_NOTLICENSED";
    break;
  case 0x80040140:
    ans = L"VIEW_E_DRAW";
    break;
  case 0x80040150:
    ans = L"REGDB_E_READREGDB";
    break;
  case 0x80040151:
    ans = L"REGDB_E_WRITEREGDB";
    break;
  case 0x80040152:
    ans = L"REGDB_E_KEYMISSING";
    break;
  case 0x80040153:
    ans = L"REGDB_E_INVALIDVALUE";
    break;
  case 0x80040154:
    ans = L"REGDB_E_CLASSNOTREG";
    break;
  case 0x80040155:
    ans = L"REGDB_E_IIDNOTREG";
    break;
  case 0x80040156:
    ans = L"REGDB_E_BADTHREADINGMODEL";
    break;
  case 0x80040157:
    ans = L"REGDB_E_PACKAGEPOLICYVIOLATION";
    break;
  case 0x80040160:
    ans = L"CAT_E_CATIDNOEXIST";
    break;
  case 0x80040161:
    ans = L"CAT_E_NODESCRIPTION";
    break;
  case 0x80040164:
    ans = L"CS_E_PACKAGE_NOTFOUND";
    break;
  case 0x80040165:
    ans = L"CS_E_NOT_DELETABLE";
    break;
  case 0x80040166:
    ans = L"CS_E_CLASS_NOTFOUND";
    break;
  case 0x80040167:
    ans = L"CS_E_INVALID_VERSION";
    break;
  case 0x80040168:
    ans = L"CS_E_NO_CLASSSTORE";
    break;
  case 0x80040169:
    ans = L"CS_E_OBJECT_NOTFOUND";
    break;
  case 0x8004016A:
    ans = L"CS_E_OBJECT_ALREADY_EXISTS";
    break;
  case 0x8004016B:
    ans = L"CS_E_INVALID_PATH";
    break;
  case 0x8004016C:
    ans = L"CS_E_NETWORK_ERROR";
    break;
  case 0x8004016D:
    ans = L"CS_E_ADMIN_LIMIT_EXCEEDED";
    break;
  case 0x8004016E:
    ans = L"CS_E_SCHEMA_MISMATCH";
    break;
  case 0x8004016F:
    ans = L"CS_E_INTERNAL_ERROR";
    break;
  case 0x80040170:
    ans = L"CACHE_E_NOCACHE_UPDATED";
    break;
  case 0x80040180:
    ans = L"OLEOBJ_E_NOVERBS";
    break;
  case 0x80040181:
    ans = L"OLEOBJ_E_INVALIDVERB";
    break;
  case 0x800401A0:
    ans = L"INPLACE_E_NOTUNDOABLE";
    break;
  case 0x800401A1:
    ans = L"INPLACE_E_NOTOOLSPACE";
    break;
  case 0x800401C0:
    ans = L"CONVERT10_E_OLESTREAM_GET";
    break;
  case 0x800401C1:
    ans = L"CONVERT10_E_OLESTREAM_PUT";
    break;
  case 0x800401C2:
    ans = L"CONVERT10_E_OLESTREAM_FMT";
    break;
  case 0x800401C3:
    ans = L"CONVERT10_E_OLESTREAM_BITMAP_TO_DIB";
    break;
  case 0x800401C4:
    ans = L"CONVERT10_E_STG_FMT";
    break;
  case 0x800401C5:
    ans = L"CONVERT10_E_STG_NO_STD_STREAM";
    break;
  case 0x800401C6:
    ans = L"CONVERT10_E_STG_DIB_TO_BITMAP";
    break;
  case 0x800401D0:
    ans = L"CLIPBRD_E_CANT_OPEN";
    break;
  case 0x800401D1:
    ans = L"CLIPBRD_E_CANT_EMPTY";
    break;
  case 0x800401D2:
    ans = L"CLIPBRD_E_CANT_SET";
    break;
  case 0x800401D3:
    ans = L"CLIPBRD_E_BAD_DATA";
    break;
  case 0x800401D4:
    ans = L"CLIPBRD_E_CANT_CLOSE";
    break;
  case 0x800401E0:
    ans = L"MK_E_CONNECTMANUALLY";
    break;
  case 0x800401E1:
    ans = L"MK_E_EXCEEDEDDEADLINE";
    break;
  case 0x800401E2:
    ans = L"MK_E_NEEDGENERIC";
    break;
  case 0x800401E3:
    ans = L"MK_E_UNAVAILABLE";
    break;
  case 0x800401E4:
    ans = L"MK_E_SYNTAX";
    break;
  case 0x800401E5:
    ans = L"MK_E_NOOBJECT";
    break;
  case 0x800401E6:
    ans = L"MK_E_INVALIDEXTENSION";
    break;
  case 0x800401E7:
    ans = L"MK_E_INTERMEDIATEINTERFACENOTSUPPORTED";
    break;
  case 0x800401E8:
    ans = L"MK_E_NOTBINDABLE";
    break;
  case 0x800401E9:
    ans = L"MK_E_NOTBOUND";
    break;
  case 0x800401EA:
    ans = L"MK_E_CANTOPENFILE";
    break;
  case 0x800401EB:
    ans = L"MK_E_MUSTBOTHERUSER";
    break;
  case 0x800401EC:
    ans = L"MK_E_NOINVERSE";
    break;
  case 0x800401ED:
    ans = L"MK_E_NOSTORAGE";
    break;
  case 0x800401EE:
    ans = L"MK_E_NOPREFIX";
    break;
  case 0x800401EF:
    ans = L"MK_E_ENUMERATION_FAILED";
    break;
  case 0x800401F0:
    ans = L"CO_E_NOTINITIALIZED";
    break;
  case 0x800401F1:
    ans = L"CO_E_ALREADYINITIALIZED";
    break;
  case 0x800401F2:
    ans = L"CO_E_CANTDETERMINECLASS";
    break;
  case 0x800401F3:
    ans = L"CO_E_CLASSSTRING";
    break;
  case 0x800401F4:
    ans = L"CO_E_IIDSTRING";
    break;
  case 0x800401F5:
    ans = L"CO_E_APPNOTFOUND";
    break;
  case 0x800401F6:
    ans = L"CO_E_APPSINGLEUSE";
    break;
  case 0x800401F7:
    ans = L"CO_E_ERRORINAPP";
    break;
  case 0x800401F8:
    ans = L"CO_E_DLLNOTFOUND";
    break;
  case 0x800401F9:
    ans = L"CO_E_ERRORINDLL";
    break;
  case 0x800401FA:
    ans = L"CO_E_WRONGOSFORAPP";
    break;
  case 0x800401FB:
    ans = L"CO_E_OBJNOTREG";
    break;
  case 0x800401FC:
    ans = L"CO_E_OBJISREG";
    break;
  case 0x800401FD:
    ans = L"CO_E_OBJNOTCONNECTED";
    break;
  case 0x800401FE:
    ans = L"CO_E_APPDIDNTREG";
    break;
  case 0x800401FF:
    ans = L"CO_E_RELEASED";
    break;
  case 0x00040200:
    ans = L"EVENT_S_SOME_SUBSCRIBERS_FAILED";
    break;
  case 0x80040201:
    ans = L"EVENT_E_ALL_SUBSCRIBERS_FAILED";
    break;
  case 0x00040202:
    ans = L"EVENT_S_NOSUBSCRIBERS";
    break;
  case 0x80040203:
    ans = L"EVENT_E_QUERYSYNTAX";
    break;
  case 0x80040204:
    ans = L"EVENT_E_QUERYFIELD";
    break;
  case 0x80040205:
    ans = L"EVENT_E_INTERNALEXCEPTION";
    break;
  case 0x80040206:
    ans = L"EVENT_E_INTERNALERROR";
    break;
  case 0x80040207:
    ans = L"EVENT_E_INVALID_PER_USER_SID";
    break;
  case 0x80040208:
    ans = L"EVENT_E_USER_EXCEPTION";
    break;
  case 0x80040209:
    ans = L"EVENT_E_TOO_MANY_METHODS";
    break;
  case 0x8004020A:
    ans = L"EVENT_E_MISSING_EVENTCLASS";
    break;
  case 0x8004020B:
    ans = L"EVENT_E_NOT_ALL_REMOVED";
    break;
  case 0x8004020C:
    ans = L"EVENT_E_COMPLUS_NOT_INSTALLED";
    break;
  case 0x8004020D:
    ans = L"EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT";
    break;
  case 0x8004020E:
    ans = L"EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT";
    break;
  case 0x8004020F:
    ans = L"EVENT_E_INVALID_EVENT_CLASS_PARTITION";
    break;
  case 0x80040210:
    ans = L"EVENT_E_PER_USER_SID_NOT_LOGGED_ON";
    break;
  case 0x80040241:
    ans = L"TPC_E_INVALID_PROPERTY";
    break;
  case 0x80040212:
    ans = L"TPC_E_NO_DEFAULT_TABLET";
    break;
  case 0x8004021B:
    ans = L"TPC_E_UNKNOWN_PROPERTY";
    break;
  case 0x80040219:
    ans = L"TPC_E_INVALID_INPUT_RECT";
    break;
  case 0x80040222:
    ans = L"TPC_E_INVALID_STROKE";
    break;
  case 0x80040223:
    ans = L"TPC_E_INITIALIZE_FAIL";
    break;
  case 0x80040232:
    ans = L"TPC_E_NOT_RELEVANT";
    break;
  case 0x80040233:
    ans = L"TPC_E_INVALID_PACKET_DESCRIPTION";
    break;
  case 0x80040235:
    ans = L"TPC_E_RECOGNIZER_NOT_REGISTERED";
    break;
  case 0x80040236:
    ans = L"TPC_E_INVALID_RIGHTS";
    break;
  case 0x80040237:
    ans = L"TPC_E_OUT_OF_ORDER_CALL";
    break;
  case 0x80040238:
    ans = L"TPC_E_QUEUE_FULL";
    break;
  case 0x80040239:
    ans = L"TPC_E_INVALID_CONFIGURATION";
    break;
  case 0x8004023A:
    ans = L"TPC_E_INVALID_DATA_FROM_RECOGNIZER";
    break;
  case 0x00040252:
    ans = L"TPC_S_TRUNCATED";
    break;
  case 0x00040253:
    ans = L"TPC_S_INTERRUPTED";
    break;
  case 0x00040254:
    ans = L"TPC_S_NO_DATA_TO_PROCESS";
    break;
  case 0x8004D000:
    ans = L"XACT_E_ALREADYOTHERSINGLEPHASE";
    break;
  case 0x8004D001:
    ans = L"XACT_E_CANTRETAIN";
    break;
  case 0x8004D002:
    ans = L"XACT_E_COMMITFAILED";
    break;
  case 0x8004D003:
    ans = L"XACT_E_COMMITPREVENTED";
    break;
  case 0x8004D004:
    ans = L"XACT_E_HEURISTICABORT";
    break;
  case 0x8004D005:
    ans = L"XACT_E_HEURISTICCOMMIT";
    break;
  case 0x8004D006:
    ans = L"XACT_E_HEURISTICDAMAGE";
    break;
  case 0x8004D007:
    ans = L"XACT_E_HEURISTICDANGER";
    break;
  case 0x8004D008:
    ans = L"XACT_E_ISOLATIONLEVEL";
    break;
  case 0x8004D009:
    ans = L"XACT_E_NOASYNC";
    break;
  case 0x8004D00A:
    ans = L"XACT_E_NOENLIST";
    break;
  case 0x8004D00B:
    ans = L"XACT_E_NOISORETAIN";
    break;
  case 0x8004D00C:
    ans = L"XACT_E_NORESOURCE";
    break;
  case 0x8004D00D:
    ans = L"XACT_E_NOTCURRENT";
    break;
  case 0x8004D00E:
    ans = L"XACT_E_NOTRANSACTION";
    break;
  case 0x8004D00F:
    ans = L"XACT_E_NOTSUPPORTED";
    break;
  case 0x8004D010:
    ans = L"XACT_E_UNKNOWNRMGRID";
    break;
  case 0x8004D011:
    ans = L"XACT_E_WRONGSTATE";
    break;
  case 0x8004D012:
    ans = L"XACT_E_WRONGUOW";
    break;
  case 0x8004D013:
    ans = L"XACT_E_XTIONEXISTS";
    break;
  case 0x8004D014:
    ans = L"XACT_E_NOIMPORTOBJECT";
    break;
  case 0x8004D015:
    ans = L"XACT_E_INVALIDCOOKIE";
    break;
  case 0x8004D016:
    ans = L"XACT_E_INDOUBT";
    break;
  case 0x8004D017:
    ans = L"XACT_E_NOTIMEOUT";
    break;
  case 0x8004D018:
    ans = L"XACT_E_ALREADYINPROGRESS";
    break;
  case 0x8004D019:
    ans = L"XACT_E_ABORTED";
    break;
  case 0x8004D01A:
    ans = L"XACT_E_LOGFULL";
    break;
  case 0x8004D01B:
    ans = L"XACT_E_TMNOTAVAILABLE";
    break;
  case 0x8004D01C:
    ans = L"XACT_E_CONNECTION_DOWN";
    break;
  case 0x8004D01D:
    ans = L"XACT_E_CONNECTION_DENIED";
    break;
  case 0x8004D01E:
    ans = L"XACT_E_REENLISTTIMEOUT";
    break;
  case 0x8004D01F:
    ans = L"XACT_E_TIP_CONNECT_FAILED";
    break;
  case 0x8004D020:
    ans = L"XACT_E_TIP_PROTOCOL_ERROR";
    break;
  case 0x8004D021:
    ans = L"XACT_E_TIP_PULL_FAILED";
    break;
  case 0x8004D022:
    ans = L"XACT_E_DEST_TMNOTAVAILABLE";
    break;
  case 0x8004D023:
    ans = L"XACT_E_TIP_DISABLED";
    break;
  case 0x8004D024:
    ans = L"XACT_E_NETWORK_TX_DISABLED";
    break;
  case 0x8004D025:
    ans = L"XACT_E_PARTNER_NETWORK_TX_DISABLED";
    break;
  case 0x8004D026:
    ans = L"XACT_E_XA_TX_DISABLED";
    break;
  case 0x8004D027:
    ans = L"XACT_E_UNABLE_TO_READ_DTC_CONFIG";
    break;
  case 0x8004D028:
    ans = L"XACT_E_UNABLE_TO_LOAD_DTC_PROXY";
    break;
  case 0x8004D029:
    ans = L"XACT_E_ABORTING";
    break;
  case 0x8004D02A:
    ans = L"XACT_E_PUSH_COMM_FAILURE";
    break;
  case 0x8004D02B:
    ans = L"XACT_E_PULL_COMM_FAILURE";
    break;
  case 0x8004D02C:
    ans = L"XACT_E_LU_TX_DISABLED";
    break;
  case 0x8004D080:
    ans = L"XACT_E_CLERKNOTFOUND";
    break;
  case 0x8004D081:
    ans = L"XACT_E_CLERKEXISTS";
    break;
  case 0x8004D082:
    ans = L"XACT_E_RECOVERYINPROGRESS";
    break;
  case 0x8004D083:
    ans = L"XACT_E_TRANSACTIONCLOSED";
    break;
  case 0x8004D084:
    ans = L"XACT_E_INVALIDLSN";
    break;
  case 0x8004D085:
    ans = L"XACT_E_REPLAYREQUEST";
    break;
  case 0x0004D000:
    ans = L"XACT_S_ASYNC";
    break;
  case 0x0004D001:
    ans = L"XACT_S_DEFECT";
    break;
  case 0x0004D002:
    ans = L"XACT_S_READONLY";
    break;
  case 0x0004D003:
    ans = L"XACT_S_SOMENORETAIN";
    break;
  case 0x0004D004:
    ans = L"XACT_S_OKINFORM";
    break;
  case 0x0004D005:
    ans = L"XACT_S_MADECHANGESCONTENT";
    break;
  case 0x0004D006:
    ans = L"XACT_S_MADECHANGESINFORM";
    break;
  case 0x0004D007:
    ans = L"XACT_S_ALLNORETAIN";
    break;
  case 0x0004D008:
    ans = L"XACT_S_ABORTING";
    break;
  case 0x0004D009:
    ans = L"XACT_S_SINGLEPHASE";
    break;
  case 0x0004D00A:
    ans = L"XACT_S_LOCALLY_OK";
    break;
  case 0x0004D010:
    ans = L"XACT_S_LASTRESOURCEMANAGER";
    break;
  case 0x8004E002:
    ans = L"CONTEXT_E_ABORTED";
    break;
  case 0x8004E003:
    ans = L"CONTEXT_E_ABORTING";
    break;
  case 0x8004E004:
    ans = L"CONTEXT_E_NOCONTEXT";
    break;
  case 0x8004E005:
    ans = L"CONTEXT_E_WOULD_DEADLOCK";
    break;
  case 0x8004E006:
    ans = L"CONTEXT_E_SYNCH_TIMEOUT";
    break;
  case 0x8004E007:
    ans = L"CONTEXT_E_OLDREF";
    break;
  case 0x8004E00C:
    ans = L"CONTEXT_E_ROLENOTFOUND";
    break;
  case 0x8004E00F:
    ans = L"CONTEXT_E_TMNOTAVAILABLE";
    break;
  case 0x8004E021:
    ans = L"CO_E_ACTIVATIONFAILED";
    break;
  case 0x8004E022:
    ans = L"CO_E_ACTIVATIONFAILED_EVENTLOGGED";
    break;
  case 0x8004E023:
    ans = L"CO_E_ACTIVATIONFAILED_CATALOGERROR";
    break;
  case 0x8004E024:
    ans = L"CO_E_ACTIVATIONFAILED_TIMEOUT";
    break;
  case 0x8004E025:
    ans = L"CO_E_INITIALIZATIONFAILED";
    break;
  case 0x8004E026:
    ans = L"CONTEXT_E_NOJIT";
    break;
  case 0x8004E027:
    ans = L"CONTEXT_E_NOTRANSACTION";
    break;
  case 0x8004E028:
    ans = L"CO_E_THREADINGMODEL_CHANGED";
    break;
  case 0x8004E029:
    ans = L"CO_E_NOIISINTRINSICS";
    break;
  case 0x8004E02A:
    ans = L"CO_E_NOCOOKIES";
    break;
  case 0x8004E02B:
    ans = L"CO_E_DBERROR";
    break;
  case 0x8004E02C:
    ans = L"CO_E_NOTPOOLED";
    break;
  case 0x8004E02D:
    ans = L"CO_E_NOTCONSTRUCTED";
    break;
  case 0x8004E02E:
    ans = L"CO_E_NOSYNCHRONIZATION";
    break;
  case 0x8004E02F:
    ans = L"CO_E_ISOLEVELMISMATCH";
    break;
  case 0x8004E030:
    ans = L"CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED";
    break;
  case 0x8004E031:
    ans = L"CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED";
    break;
  case 0x00040000:
    ans = L"OLE_S_USEREG";
    break;
  case 0x00040001:
    ans = L"OLE_S_STATIC";
    break;
  case 0x00040002:
    ans = L"OLE_S_MAC_CLIPFORMAT";
    break;
  case 0x00040100:
    ans = L"DRAGDROP_S_DROP";
    break;
  case 0x00040101:
    ans = L"DRAGDROP_S_CANCEL";
    break;
  case 0x00040102:
    ans = L"DRAGDROP_S_USEDEFAULTCURSORS";
    break;
  case 0x00040130:
    ans = L"DATA_S_SAMEFORMATETC";
    break;
  case 0x00040140:
    ans = L"VIEW_S_ALREADY_FROZEN";
    break;
  case 0x00040170:
    ans = L"CACHE_S_FORMATETC_NOTSUPPORTED";
    break;
  case 0x00040171:
    ans = L"CACHE_S_SAMECACHE";
    break;
  case 0x00040172:
    ans = L"CACHE_S_SOMECACHES_NOTUPDATED";
    break;
  case 0x00040180:
    ans = L"OLEOBJ_S_INVALIDVERB";
    break;
  case 0x00040181:
    ans = L"OLEOBJ_S_CANNOT_DOVERB_NOW";
    break;
  case 0x00040182:
    ans = L"OLEOBJ_S_INVALIDHWND";
    break;
  case 0x000401A0:
    ans = L"INPLACE_S_TRUNCATED";
    break;
  case 0x000401C0:
    ans = L"CONVERT10_S_NO_PRESENTATION";
    break;
  case 0x000401E2:
    ans = L"MK_S_REDUCED_TO_SELF";
    break;
  case 0x000401E4:
    ans = L"MK_S_ME";
    break;
  case 0x000401E5:
    ans = L"MK_S_HIM";
    break;
  case 0x000401E6:
    ans = L"MK_S_US";
    break;
  case 0x000401E7:
    ans = L"MK_S_MONIKERALREADYREGISTERED";
    break;
  case 0x00041300:
    ans = L"SCHED_S_TASK_READY";
    break;
  case 0x00041301:
    ans = L"SCHED_S_TASK_RUNNING";
    break;
  case 0x00041302:
    ans = L"SCHED_S_TASK_DISABLED";
    break;
  case 0x00041303:
    ans = L"SCHED_S_TASK_HAS_NOT_RUN";
    break;
  case 0x00041304:
    ans = L"SCHED_S_TASK_NO_MORE_RUNS";
    break;
  case 0x00041305:
    ans = L"SCHED_S_TASK_NOT_SCHEDULED";
    break;
  case 0x00041306:
    ans = L"SCHED_S_TASK_TERMINATED";
    break;
  case 0x00041307:
    ans = L"SCHED_S_TASK_NO_VALID_TRIGGERS";
    break;
  case 0x00041308:
    ans = L"SCHED_S_EVENT_TRIGGER";
    break;
  case 0x80041309:
    ans = L"SCHED_E_TRIGGER_NOT_FOUND";
    break;
  case 0x8004130A:
    ans = L"SCHED_E_TASK_NOT_READY";
    break;
  case 0x8004130B:
    ans = L"SCHED_E_TASK_NOT_RUNNING";
    break;
  case 0x8004130C:
    ans = L"SCHED_E_SERVICE_NOT_INSTALLED";
    break;
  case 0x8004130D:
    ans = L"SCHED_E_CANNOT_OPEN_TASK";
    break;
  case 0x8004130E:
    ans = L"SCHED_E_INVALID_TASK";
    break;
  case 0x8004130F:
    ans = L"SCHED_E_ACCOUNT_INFORMATION_NOT_SET";
    break;
  case 0x80041310:
    ans = L"SCHED_E_ACCOUNT_NAME_NOT_FOUND";
    break;
  case 0x80041311:
    ans = L"SCHED_E_ACCOUNT_DBASE_CORRUPT";
    break;
  case 0x80041312:
    ans = L"SCHED_E_NO_SECURITY_SERVICES";
    break;
  case 0x80041313:
    ans = L"SCHED_E_UNKNOWN_OBJECT_VERSION";
    break;
  case 0x80041314:
    ans = L"SCHED_E_UNSUPPORTED_ACCOUNT_OPTION";
    break;
  case 0x80041315:
    ans = L"SCHED_E_SERVICE_NOT_RUNNING";
    break;
  case 0x80041316:
    ans = L"SCHED_E_UNEXPECTEDNODE";
    break;
  case 0x80041317:
    ans = L"SCHED_E_NAMESPACE";
    break;
  case 0x80041318:
    ans = L"SCHED_E_INVALIDVALUE";
    break;
  case 0x80041319:
    ans = L"SCHED_E_MISSINGNODE";
    break;
  case 0x8004131A:
    ans = L"SCHED_E_MALFORMEDXML";
    break;
  case 0x0004131B:
    ans = L"SCHED_S_SOME_TRIGGERS_FAILED";
    break;
  case 0x0004131C:
    ans = L"SCHED_S_BATCH_LOGON_PROBLEM";
    break;
  case 0x8004131D:
    ans = L"SCHED_E_TOO_MANY_NODES";
    break;
  case 0x8004131E:
    ans = L"SCHED_E_PAST_END_BOUNDARY";
    break;
  case 0x8004131F:
    ans = L"SCHED_E_ALREADY_RUNNING";
    break;
  case 0x80041320:
    ans = L"SCHED_E_USER_NOT_LOGGED_ON";
    break;
  case 0x80041321:
    ans = L"SCHED_E_INVALID_TASK_HASH";
    break;
  case 0x80041322:
    ans = L"SCHED_E_SERVICE_NOT_AVAILABLE";
    break;
  case 0x80041323:
    ans = L"SCHED_E_SERVICE_TOO_BUSY";
    break;
  case 0x80041324:
    ans = L"SCHED_E_TASK_ATTEMPTED";
    break;
  case 0x00041325:
    ans = L"SCHED_S_TASK_QUEUED";
    break;
  case 0x80041326:
    ans = L"SCHED_E_TASK_DISABLED";
    break;
  case 0x80041327:
    ans = L"SCHED_E_TASK_NOT_V1_COMPAT";
    break;
  case 0x80041328:
    ans = L"SCHED_E_START_ON_DEMAND";
    break;
  case 0x80041329:
    ans = L"SCHED_E_TASK_NOT_UBPM_COMPAT";
    break;
  case 0x80041330:
    ans = L"SCHED_E_DEPRECATED_FEATURE_USED";
    break;
  case 0x80080001:
    ans = L"CO_E_CLASS_CREATE_FAILED";
    break;
  case 0x80080002:
    ans = L"CO_E_SCM_ERROR";
    break;
  case 0x80080003:
    ans = L"CO_E_SCM_RPC_FAILURE";
    break;
  case 0x80080004:
    ans = L"CO_E_BAD_PATH";
    break;
  case 0x80080005:
    ans = L"CO_E_SERVER_EXEC_FAILURE";
    break;
  case 0x80080006:
    ans = L"CO_E_OBJSRV_RPC_FAILURE";
    break;
  case 0x80080007:
    ans = L"MK_E_NO_NORMALIZED";
    break;
  case 0x80080008:
    ans = L"CO_E_SERVER_STOPPING";
    break;
  case 0x80080009:
    ans = L"MEM_E_INVALID_ROOT";
    break;
  case 0x80080010:
    ans = L"MEM_E_INVALID_LINK";
    break;
  case 0x80080011:
    ans = L"MEM_E_INVALID_SIZE";
    break;
  case 0x00080012:
    ans = L"CO_S_NOTALLINTERFACES";
    break;
  case 0x00080013:
    ans = L"CO_S_MACHINENAMENOTFOUND";
    break;
  case 0x80080015:
    ans = L"CO_E_MISSING_DISPLAYNAME";
    break;
  case 0x80080016:
    ans = L"CO_E_RUNAS_VALUE_MUST_BE_AAA";
    break;
  case 0x80080017:
    ans = L"CO_E_ELEVATION_DISABLED";
    break;
  case 0x80080200:
    ans = L"APPX_E_PACKAGING_INTERNAL";
    break;
  case 0x80080201:
    ans = L"APPX_E_INTERLEAVING_NOT_ALLOWED";
    break;
  case 0x80080202:
    ans = L"APPX_E_RELATIONSHIPS_NOT_ALLOWED";
    break;
  case 0x80080203:
    ans = L"APPX_E_MISSING_REQUIRED_FILE";
    break;
  case 0x80080204:
    ans = L"APPX_E_INVALID_MANIFEST";
    break;
  case 0x80080205:
    ans = L"APPX_E_INVALID_BLOCKMAP";
    break;
  case 0x80080206:
    ans = L"APPX_E_CORRUPT_CONTENT";
    break;
  case 0x80080207:
    ans = L"APPX_E_BLOCK_HASH_INVALID";
    break;
  case 0x80080208:
    ans = L"APPX_E_REQUESTED_RANGE_TOO_LARGE";
    break;
  case 0x80080209:
    ans = L"APPX_E_INVALID_SIP_CLIENT_DATA";
    break;
  case 0x8008020A:
    ans = L"APPX_E_INVALID_KEY_INFO";
    break;
  case 0x8008020B:
    ans = L"APPX_E_INVALID_CONTENTGROUPMAP";
    break;
  case 0x8008020C:
    ans = L"APPX_E_INVALID_APPINSTALLER";
    break;
  case 0x8008020D:
    ans = L"APPX_E_DELTA_BASELINE_VERSION_MISMATCH";
    break;
  case 0x8008020E:
    ans = L"APPX_E_DELTA_PACKAGE_MISSING_FILE";
    break;
  case 0x8008020F:
    ans = L"APPX_E_INVALID_DELTA_PACKAGE";
    break;
  case 0x80080210:
    ans = L"APPX_E_DELTA_APPENDED_PACKAGE_NOT_ALLOWED";
    break;
  case 0x80080211:
    ans = L"APPX_E_INVALID_PACKAGING_LAYOUT";
    break;
  case 0x80080212:
    ans = L"APPX_E_INVALID_PACKAGESIGNCONFIG";
    break;
  case 0x80080213:
    ans = L"APPX_E_RESOURCESPRI_NOT_ALLOWED";
    break;
  case 0x80080214:
    ans = L"APPX_E_FILE_COMPRESSION_MISMATCH";
    break;
  case 0x80080215:
    ans = L"APPX_E_INVALID_PAYLOAD_PACKAGE_EXTENSION";
    break;
  case 0x80080216:
    ans = L"APPX_E_INVALID_ENCRYPTION_EXCLUSION_FILE_LIST";
    break;
  case 0x80080300:
    ans = L"BT_E_SPURIOUS_ACTIVATION";
    break;
  case 0x80020001:
    ans = L"DISP_E_UNKNOWNINTERFACE";
    break;
  case 0x80020003:
    ans = L"DISP_E_MEMBERNOTFOUND";
    break;
  case 0x80020004:
    ans = L"DISP_E_PARAMNOTFOUND";
    break;
  case 0x80020005:
    ans = L"DISP_E_TYPEMISMATCH";
    break;
  case 0x80020006:
    ans = L"DISP_E_UNKNOWNNAME";
    break;
  case 0x80020007:
    ans = L"DISP_E_NONAMEDARGS";
    break;
  case 0x80020008:
    ans = L"DISP_E_BADVARTYPE";
    break;
  case 0x80020009:
    ans = L"DISP_E_EXCEPTION";
    break;
  case 0x8002000A:
    ans = L"DISP_E_OVERFLOW";
    break;
  case 0x8002000B:
    ans = L"DISP_E_BADINDEX";
    break;
  case 0x8002000C:
    ans = L"DISP_E_UNKNOWNLCID";
    break;
  case 0x8002000D:
    ans = L"DISP_E_ARRAYISLOCKED";
    break;
  case 0x8002000E:
    ans = L"DISP_E_BADPARAMCOUNT";
    break;
  case 0x8002000F:
    ans = L"DISP_E_PARAMNOTOPTIONAL";
    break;
  case 0x80020010:
    ans = L"DISP_E_BADCALLEE";
    break;
  case 0x80020011:
    ans = L"DISP_E_NOTACOLLECTION";
    break;
  case 0x80020012:
    ans = L"DISP_E_DIVBYZERO";
    break;
  case 0x80020013:
    ans = L"DISP_E_BUFFERTOOSMALL";
    break;
  case 0x80028016:
    ans = L"TYPE_E_BUFFERTOOSMALL";
    break;
  case 0x80028017:
    ans = L"TYPE_E_FIELDNOTFOUND";
    break;
  case 0x80028018:
    ans = L"TYPE_E_INVDATAREAD";
    break;
  case 0x80028019:
    ans = L"TYPE_E_UNSUPFORMAT";
    break;
  case 0x8002801C:
    ans = L"TYPE_E_REGISTRYACCESS";
    break;
  case 0x8002801D:
    ans = L"TYPE_E_LIBNOTREGISTERED";
    break;
  case 0x80028027:
    ans = L"TYPE_E_UNDEFINEDTYPE";
    break;
  case 0x80028028:
    ans = L"TYPE_E_QUALIFIEDNAMEDISALLOWED";
    break;
  case 0x80028029:
    ans = L"TYPE_E_INVALIDSTATE";
    break;
  case 0x8002802A:
    ans = L"TYPE_E_WRONGTYPEKIND";
    break;
  case 0x8002802B:
    ans = L"TYPE_E_ELEMENTNOTFOUND";
    break;
  case 0x8002802C:
    ans = L"TYPE_E_AMBIGUOUSNAME";
    break;
  case 0x8002802D:
    ans = L"TYPE_E_NAMECONFLICT";
    break;
  case 0x8002802E:
    ans = L"TYPE_E_UNKNOWNLCID";
    break;
  case 0x8002802F:
    ans = L"TYPE_E_DLLFUNCTIONNOTFOUND";
    break;
  case 0x800288BD:
    ans = L"TYPE_E_BADMODULEKIND";
    break;
  case 0x800288C5:
    ans = L"TYPE_E_SIZETOOBIG";
    break;
  case 0x800288C6:
    ans = L"TYPE_E_DUPLICATEID";
    break;
  case 0x800288CF:
    ans = L"TYPE_E_INVALIDID";
    break;
  case 0x80028CA0:
    ans = L"TYPE_E_TYPEMISMATCH";
    break;
  case 0x80028CA1:
    ans = L"TYPE_E_OUTOFBOUNDS";
    break;
  case 0x80028CA2:
    ans = L"TYPE_E_IOERROR";
    break;
  case 0x80028CA3:
    ans = L"TYPE_E_CANTCREATETMPFILE";
    break;
  case 0x80029C4A:
    ans = L"TYPE_E_CANTLOADLIBRARY";
    break;
  case 0x80029C83:
    ans = L"TYPE_E_INCONSISTENTPROPFUNCS";
    break;
  case 0x80029C84:
    ans = L"TYPE_E_CIRCULARTYPE";
    break;
  case 0x80030001:
    ans = L"STG_E_INVALIDFUNCTION";
    break;
  case 0x80030002:
    ans = L"STG_E_FILENOTFOUND";
    break;
  case 0x80030003:
    ans = L"STG_E_PATHNOTFOUND";
    break;
  case 0x80030004:
    ans = L"STG_E_TOOMANYOPENFILES";
    break;
  case 0x80030005:
    ans = L"STG_E_ACCESSDENIED";
    break;
  case 0x80030006:
    ans = L"STG_E_INVALIDHANDLE";
    break;
  case 0x80030008:
    ans = L"STG_E_INSUFFICIENTMEMORY";
    break;
  case 0x80030009:
    ans = L"STG_E_INVALIDPOINTER";
    break;
  case 0x80030012:
    ans = L"STG_E_NOMOREFILES";
    break;
  case 0x80030013:
    ans = L"STG_E_DISKISWRITEPROTECTED";
    break;
  case 0x80030019:
    ans = L"STG_E_SEEKERROR";
    break;
  case 0x8003001D:
    ans = L"STG_E_WRITEFAULT";
    break;
  case 0x8003001E:
    ans = L"STG_E_READFAULT";
    break;
  case 0x80030020:
    ans = L"STG_E_SHAREVIOLATION";
    break;
  case 0x80030021:
    ans = L"STG_E_LOCKVIOLATION";
    break;
  case 0x80030050:
    ans = L"STG_E_FILEALREADYEXISTS";
    break;
  case 0x80030057:
    ans = L"STG_E_INVALIDPARAMETER";
    break;
  case 0x80030070:
    ans = L"STG_E_MEDIUMFULL";
    break;
  case 0x800300F0:
    ans = L"STG_E_PROPSETMISMATCHED";
    break;
  case 0x800300FA:
    ans = L"STG_E_ABNORMALAPIEXIT";
    break;
  case 0x800300FB:
    ans = L"STG_E_INVALIDHEADER";
    break;
  case 0x800300FC:
    ans = L"STG_E_INVALIDNAME";
    break;
  case 0x800300FD:
    ans = L"STG_E_UNKNOWN";
    break;
  case 0x800300FE:
    ans = L"STG_E_UNIMPLEMENTEDFUNCTION";
    break;
  case 0x800300FF:
    ans = L"STG_E_INVALIDFLAG";
    break;
  case 0x80030100:
    ans = L"STG_E_INUSE";
    break;
  case 0x80030101:
    ans = L"STG_E_NOTCURRENT";
    break;
  case 0x80030102:
    ans = L"STG_E_REVERTED";
    break;
  case 0x80030103:
    ans = L"STG_E_CANTSAVE";
    break;
  case 0x80030104:
    ans = L"STG_E_OLDFORMAT";
    break;
  case 0x80030105:
    ans = L"STG_E_OLDDLL";
    break;
  case 0x80030106:
    ans = L"STG_E_SHAREREQUIRED";
    break;
  case 0x80030107:
    ans = L"STG_E_NOTFILEBASEDSTORAGE";
    break;
  case 0x80030108:
    ans = L"STG_E_EXTANTMARSHALLINGS";
    break;
  case 0x80030109:
    ans = L"STG_E_DOCFILECORRUPT";
    break;
  case 0x80030110:
    ans = L"STG_E_BADBASEADDRESS";
    break;
  case 0x80030111:
    ans = L"STG_E_DOCFILETOOLARGE";
    break;
  case 0x80030112:
    ans = L"STG_E_NOTSIMPLEFORMAT";
    break;
  case 0x80030201:
    ans = L"STG_E_INCOMPLETE";
    break;
  case 0x80030202:
    ans = L"STG_E_TERMINATED";
    break;
  case 0x00030200:
    ans = L"STG_S_CONVERTED";
    break;
  case 0x00030201:
    ans = L"STG_S_BLOCK";
    break;
  case 0x00030202:
    ans = L"STG_S_RETRYNOW";
    break;
  case 0x00030203:
    ans = L"STG_S_MONITORING";
    break;
  case 0x00030204:
    ans = L"STG_S_MULTIPLEOPENS";
    break;
  case 0x00030205:
    ans = L"STG_S_CONSOLIDATIONFAILED";
    break;
  case 0x00030206:
    ans = L"STG_S_CANNOTCONSOLIDATE";
    break;
  case 0x00030207:
    ans = L"STG_S_POWER_CYCLE_REQUIRED";
    break;
  case 0x80030208:
    ans = L"STG_E_FIRMWARE_SLOT_INVALID";
    break;
  case 0x80030209:
    ans = L"STG_E_FIRMWARE_IMAGE_INVALID";
    break;
  case 0x8003020A:
    ans = L"STG_E_DEVICE_UNRESPONSIVE";
    break;
  case 0x80030305:
    ans = L"STG_E_STATUS_COPY_PROTECTION_FAILURE";
    break;
  case 0x80030306:
    ans = L"STG_E_CSS_AUTHENTICATION_FAILURE";
    break;
  case 0x80030307:
    ans = L"STG_E_CSS_KEY_NOT_PRESENT";
    break;
  case 0x80030308:
    ans = L"STG_E_CSS_KEY_NOT_ESTABLISHED";
    break;
  case 0x80030309:
    ans = L"STG_E_CSS_SCRAMBLED_SECTOR";
    break;
  case 0x8003030A:
    ans = L"STG_E_CSS_REGION_MISMATCH";
    break;
  case 0x8003030B:
    ans = L"STG_E_RESETS_EXHAUSTED";
    break;
  case 0x80010001:
    ans = L"RPC_E_CALL_REJECTED";
    break;
  case 0x80010002:
    ans = L"RPC_E_CALL_CANCELED";
    break;
  case 0x80010003:
    ans = L"RPC_E_CANTPOST_INSENDCALL";
    break;
  case 0x80010004:
    ans = L"RPC_E_CANTCALLOUT_INASYNCCALL";
    break;
  case 0x80010005:
    ans = L"RPC_E_CANTCALLOUT_INEXTERNALCALL";
    break;
  case 0x80010006:
    ans = L"RPC_E_CONNECTION_TERMINATED";
    break;
  case 0x80010007:
    ans = L"RPC_E_SERVER_DIED";
    break;
  case 0x80010008:
    ans = L"RPC_E_CLIENT_DIED";
    break;
  case 0x80010009:
    ans = L"RPC_E_INVALID_DATAPACKET";
    break;
  case 0x8001000A:
    ans = L"RPC_E_CANTTRANSMIT_CALL";
    break;
  case 0x8001000B:
    ans = L"RPC_E_CLIENT_CANTMARSHAL_DATA";
    break;
  case 0x8001000C:
    ans = L"RPC_E_CLIENT_CANTUNMARSHAL_DATA";
    break;
  case 0x8001000D:
    ans = L"RPC_E_SERVER_CANTMARSHAL_DATA";
    break;
  case 0x8001000E:
    ans = L"RPC_E_SERVER_CANTUNMARSHAL_DATA";
    break;
  case 0x8001000F:
    ans = L"RPC_E_INVALID_DATA";
    break;
  case 0x80010010:
    ans = L"RPC_E_INVALID_PARAMETER";
    break;
  case 0x80010011:
    ans = L"RPC_E_CANTCALLOUT_AGAIN";
    break;
  case 0x80010012:
    ans = L"RPC_E_SERVER_DIED_DNE";
    break;
  case 0x80010100:
    ans = L"RPC_E_SYS_CALL_FAILED";
    break;
  case 0x80010101:
    ans = L"RPC_E_OUT_OF_RESOURCES";
    break;
  case 0x80010102:
    ans = L"RPC_E_ATTEMPTED_MULTITHREAD";
    break;
  case 0x80010103:
    ans = L"RPC_E_NOT_REGISTERED";
    break;
  case 0x80010104:
    ans = L"RPC_E_FAULT";
    break;
  case 0x80010105:
    ans = L"RPC_E_SERVERFAULT";
    break;
  case 0x80010106:
    ans = L"RPC_E_CHANGED_MODE";
    break;
  case 0x80010107:
    ans = L"RPC_E_INVALIDMETHOD";
    break;
  case 0x80010108:
    ans = L"RPC_E_DISCONNECTED";
    break;
  case 0x80010109:
    ans = L"RPC_E_RETRY";
    break;
  case 0x8001010A:
    ans = L"RPC_E_SERVERCALL_RETRYLATER";
    break;
  case 0x8001010B:
    ans = L"RPC_E_SERVERCALL_REJECTED";
    break;
  case 0x8001010C:
    ans = L"RPC_E_INVALID_CALLDATA";
    break;
  case 0x8001010D:
    ans = L"RPC_E_CANTCALLOUT_ININPUTSYNCCALL";
    break;
  case 0x8001010E:
    ans = L"RPC_E_WRONG_THREAD";
    break;
  case 0x8001010F:
    ans = L"RPC_E_THREAD_NOT_INIT";
    break;
  case 0x80010110:
    ans = L"RPC_E_VERSION_MISMATCH";
    break;
  case 0x80010111:
    ans = L"RPC_E_INVALID_HEADER";
    break;
  case 0x80010112:
    ans = L"RPC_E_INVALID_EXTENSION";
    break;
  case 0x80010113:
    ans = L"RPC_E_INVALID_IPID";
    break;
  case 0x80010114:
    ans = L"RPC_E_INVALID_OBJECT";
    break;
  case 0x80010115:
    ans = L"RPC_S_CALLPENDING";
    break;
  case 0x80010116:
    ans = L"RPC_S_WAITONTIMER";
    break;
  case 0x80010117:
    ans = L"RPC_E_CALL_COMPLETE";
    break;
  case 0x80010118:
    ans = L"RPC_E_UNSECURE_CALL";
    break;
  case 0x80010119:
    ans = L"RPC_E_TOO_LATE";
    break;
  case 0x8001011A:
    ans = L"RPC_E_NO_GOOD_SECURITY_PACKAGES";
    break;
  case 0x8001011B:
    ans = L"RPC_E_ACCESS_DENIED";
    break;
  case 0x8001011C:
    ans = L"RPC_E_REMOTE_DISABLED";
    break;
  case 0x8001011D:
    ans = L"RPC_E_INVALID_OBJREF";
    break;
  case 0x8001011E:
    ans = L"RPC_E_NO_CONTEXT";
    break;
  case 0x8001011F:
    ans = L"RPC_E_TIMEOUT";
    break;
  case 0x80010120:
    ans = L"RPC_E_NO_SYNC";
    break;
  case 0x80010121:
    ans = L"RPC_E_FULLSIC_REQUIRED";
    break;
  case 0x80010122:
    ans = L"RPC_E_INVALID_STD_NAME";
    break;
  case 0x80010123:
    ans = L"CO_E_FAILEDTOIMPERSONATE";
    break;
  case 0x80010124:
    ans = L"CO_E_FAILEDTOGETSECCTX";
    break;
  case 0x80010125:
    ans = L"CO_E_FAILEDTOOPENTHREADTOKEN";
    break;
  case 0x80010126:
    ans = L"CO_E_FAILEDTOGETTOKENINFO";
    break;
  case 0x80010127:
    ans = L"CO_E_TRUSTEEDOESNTMATCHCLIENT";
    break;
  case 0x80010128:
    ans = L"CO_E_FAILEDTOQUERYCLIENTBLANKET";
    break;
  case 0x80010129:
    ans = L"CO_E_FAILEDTOSETDACL";
    break;
  case 0x8001012A:
    ans = L"CO_E_ACCESSCHECKFAILED";
    break;
  case 0x8001012B:
    ans = L"CO_E_NETACCESSAPIFAILED";
    break;
  case 0x8001012C:
    ans = L"CO_E_WRONGTRUSTEENAMESYNTAX";
    break;
  case 0x8001012D:
    ans = L"CO_E_INVALIDSID";
    break;
  case 0x8001012E:
    ans = L"CO_E_CONVERSIONFAILED";
    break;
  case 0x8001012F:
    ans = L"CO_E_NOMATCHINGSIDFOUND";
    break;
  case 0x80010130:
    ans = L"CO_E_LOOKUPACCSIDFAILED";
    break;
  case 0x80010131:
    ans = L"CO_E_NOMATCHINGNAMEFOUND";
    break;
  case 0x80010132:
    ans = L"CO_E_LOOKUPACCNAMEFAILED";
    break;
  case 0x80010133:
    ans = L"CO_E_SETSERLHNDLFAILED";
    break;
  case 0x80010134:
    ans = L"CO_E_FAILEDTOGETWINDIR";
    break;
  case 0x80010135:
    ans = L"CO_E_PATHTOOLONG";
    break;
  case 0x80010136:
    ans = L"CO_E_FAILEDTOGENUUID";
    break;
  case 0x80010137:
    ans = L"CO_E_FAILEDTOCREATEFILE";
    break;
  case 0x80010138:
    ans = L"CO_E_FAILEDTOCLOSEHANDLE";
    break;
  case 0x80010139:
    ans = L"CO_E_EXCEEDSYSACLLIMIT";
    break;
  case 0x8001013A:
    ans = L"CO_E_ACESINWRONGORDER";
    break;
  case 0x8001013B:
    ans = L"CO_E_INCOMPATIBLESTREAMVERSION";
    break;
  case 0x8001013C:
    ans = L"CO_E_FAILEDTOOPENPROCESSTOKEN";
    break;
  case 0x8001013D:
    ans = L"CO_E_DECODEFAILED";
    break;
  case 0x8001013F:
    ans = L"CO_E_ACNOTINITIALIZED";
    break;
  case 0x80010140:
    ans = L"CO_E_CANCEL_DISABLED";
    break;
  case 0x8001FFFF:
    ans = L"RPC_E_UNEXPECTED";
    break;
  case 0xC0090001:
    ans = L"ERROR_AUDITING_DISABLED";
    break;
  case 0xC0090002:
    ans = L"ERROR_ALL_SIDS_FILTERED";
    break;
  case 0xC0090003:
    ans = L"ERROR_BIZRULES_NOT_ENABLED";
    break;
  case 0x80090001:
    ans = L"NTE_BAD_UID";
    break;
  case 0x80090002:
    ans = L"NTE_BAD_HASH";
    break;
  case 0x80090003:
    ans = L"NTE_BAD_KEY";
    break;
  case 0x80090004:
    ans = L"NTE_BAD_LEN";
    break;
  case 0x80090005:
    ans = L"NTE_BAD_DATA";
    break;
  case 0x80090006:
    ans = L"NTE_BAD_SIGNATURE";
    break;
  case 0x80090007:
    ans = L"NTE_BAD_VER";
    break;
  case 0x80090008:
    ans = L"NTE_BAD_ALGID";
    break;
  case 0x80090009:
    ans = L"NTE_BAD_FLAGS";
    break;
  case 0x8009000A:
    ans = L"NTE_BAD_TYPE";
    break;
  case 0x8009000B:
    ans = L"NTE_BAD_KEY_STATE";
    break;
  case 0x8009000C:
    ans = L"NTE_BAD_HASH_STATE";
    break;
  case 0x8009000D:
    ans = L"NTE_NO_KEY";
    break;
  case 0x8009000E:
    ans = L"NTE_NO_MEMORY";
    break;
  case 0x8009000F:
    ans = L"NTE_EXISTS";
    break;
  case 0x80090010:
    ans = L"NTE_PERM";
    break;
  case 0x80090011:
    ans = L"NTE_NOT_FOUND";
    break;
  case 0x80090012:
    ans = L"NTE_DOUBLE_ENCRYPT";
    break;
  case 0x80090013:
    ans = L"NTE_BAD_PROVIDER";
    break;
  case 0x80090014:
    ans = L"NTE_BAD_PROV_TYPE";
    break;
  case 0x80090015:
    ans = L"NTE_BAD_PUBLIC_KEY";
    break;
  case 0x80090016:
    ans = L"NTE_BAD_KEYSET";
    break;
  case 0x80090017:
    ans = L"NTE_PROV_TYPE_NOT_DEF";
    break;
  case 0x80090018:
    ans = L"NTE_PROV_TYPE_ENTRY_BAD";
    break;
  case 0x80090019:
    ans = L"NTE_KEYSET_NOT_DEF";
    break;
  case 0x8009001A:
    ans = L"NTE_KEYSET_ENTRY_BAD";
    break;
  case 0x8009001B:
    ans = L"NTE_PROV_TYPE_NO_MATCH";
    break;
  case 0x8009001C:
    ans = L"NTE_SIGNATURE_FILE_BAD";
    break;
  case 0x8009001D:
    ans = L"NTE_PROVIDER_DLL_FAIL";
    break;
  case 0x8009001E:
    ans = L"NTE_PROV_DLL_NOT_FOUND";
    break;
  case 0x8009001F:
    ans = L"NTE_BAD_KEYSET_PARAM";
    break;
  case 0x80090020:
    ans = L"NTE_FAIL";
    break;
  case 0x80090021:
    ans = L"NTE_SYS_ERR";
    break;
  case 0x80090022:
    ans = L"NTE_SILENT_CONTEXT";
    break;
  case 0x80090023:
    ans = L"NTE_TOKEN_KEYSET_STORAGE_FULL";
    break;
  case 0x80090024:
    ans = L"NTE_TEMPORARY_PROFILE";
    break;
  case 0x80090025:
    ans = L"NTE_FIXEDPARAMETER";
    break;
  case 0x80090026:
    ans = L"NTE_INVALID_HANDLE";
    break;
  case 0x80090027:
    ans = L"NTE_INVALID_PARAMETER";
    break;
  case 0x80090028:
    ans = L"NTE_BUFFER_TOO_SMALL";
    break;
  case 0x80090029:
    ans = L"NTE_NOT_SUPPORTED";
    break;
  case 0x8009002A:
    ans = L"NTE_NO_MORE_ITEMS";
    break;
  case 0x8009002B:
    ans = L"NTE_BUFFERS_OVERLAP";
    break;
  case 0x8009002C:
    ans = L"NTE_DECRYPTION_FAILURE";
    break;
  case 0x8009002D:
    ans = L"NTE_INTERNAL_ERROR";
    break;
  case 0x8009002E:
    ans = L"NTE_UI_REQUIRED";
    break;
  case 0x8009002F:
    ans = L"NTE_HMAC_NOT_SUPPORTED";
    break;
  case 0x80090030:
    ans = L"NTE_DEVICE_NOT_READY";
    break;
  case 0x80090031:
    ans = L"NTE_AUTHENTICATION_IGNORED";
    break;
  case 0x80090032:
    ans = L"NTE_VALIDATION_FAILED";
    break;
  case 0x80090033:
    ans = L"NTE_INCORRECT_PASSWORD";
    break;
  case 0x80090034:
    ans = L"NTE_ENCRYPTION_FAILURE";
    break;
  case 0x80090035:
    ans = L"NTE_DEVICE_NOT_FOUND";
    break;
  case 0x80090036:
    ans = L"NTE_USER_CANCELLED";
    break;
  case 0x80090037:
    ans = L"NTE_PASSWORD_CHANGE_REQUIRED";
    break;
  case 0x80090038:
    ans = L"NTE_NOT_ACTIVE_CONSOLE";
    break;
  case 0x80090300:
    ans = L"SEC_E_INSUFFICIENT_MEMORY";
    break;
  case 0x80090301:
    ans = L"SEC_E_INVALID_HANDLE";
    break;
  case 0x80090302:
    ans = L"SEC_E_UNSUPPORTED_FUNCTION";
    break;
  case 0x80090303:
    ans = L"SEC_E_TARGET_UNKNOWN";
    break;
  case 0x80090304:
    ans = L"SEC_E_INTERNAL_ERROR";
    break;
  case 0x80090305:
    ans = L"SEC_E_SECPKG_NOT_FOUND";
    break;
  case 0x80090306:
    ans = L"SEC_E_NOT_OWNER";
    break;
  case 0x80090307:
    ans = L"SEC_E_CANNOT_INSTALL";
    break;
  case 0x80090308:
    ans = L"SEC_E_INVALID_TOKEN";
    break;
  case 0x80090309:
    ans = L"SEC_E_CANNOT_PACK";
    break;
  case 0x8009030A:
    ans = L"SEC_E_QOP_NOT_SUPPORTED";
    break;
  case 0x8009030B:
    ans = L"SEC_E_NO_IMPERSONATION";
    break;
  case 0x8009030C:
    ans = L"SEC_E_LOGON_DENIED";
    break;
  case 0x8009030D:
    ans = L"SEC_E_UNKNOWN_CREDENTIALS";
    break;
  case 0x8009030E:
    ans = L"SEC_E_NO_CREDENTIALS";
    break;
  case 0x8009030F:
    ans = L"SEC_E_MESSAGE_ALTERED";
    break;
  case 0x80090310:
    ans = L"SEC_E_OUT_OF_SEQUENCE";
    break;
  case 0x80090311:
    ans = L"SEC_E_NO_AUTHENTICATING_AUTHORITY";
    break;
  case 0x00090312:
    ans = L"SEC_I_CONTINUE_NEEDED";
    break;
  case 0x00090313:
    ans = L"SEC_I_COMPLETE_NEEDED";
    break;
  case 0x00090314:
    ans = L"SEC_I_COMPLETE_AND_CONTINUE";
    break;
  case 0x00090315:
    ans = L"SEC_I_LOCAL_LOGON";
    break;
  case 0x80090316:
    ans = L"SEC_E_BAD_PKGID";
    break;
  case 0x80090317:
    ans = L"SEC_E_CONTEXT_EXPIRED";
    break;
  case 0x00090317:
    ans = L"SEC_I_CONTEXT_EXPIRED";
    break;
  case 0x80090318:
    ans = L"SEC_E_INCOMPLETE_MESSAGE";
    break;
  case 0x80090320:
    ans = L"SEC_E_INCOMPLETE_CREDENTIALS";
    break;
  case 0x80090321:
    ans = L"SEC_E_BUFFER_TOO_SMALL";
    break;
  case 0x00090320:
    ans = L"SEC_I_INCOMPLETE_CREDENTIALS";
    break;
  case 0x00090321:
    ans = L"SEC_I_RENEGOTIATE";
    break;
  case 0x80090322:
    ans = L"SEC_E_WRONG_PRINCIPAL";
    break;
  case 0x00090323:
    ans = L"SEC_I_NO_LSA_CONTEXT";
    break;
  case 0x80090324:
    ans = L"SEC_E_TIME_SKEW";
    break;
  case 0x80090325:
    ans = L"SEC_E_UNTRUSTED_ROOT";
    break;
  case 0x80090326:
    ans = L"SEC_E_ILLEGAL_MESSAGE";
    break;
  case 0x80090327:
    ans = L"SEC_E_CERT_UNKNOWN";
    break;
  case 0x80090328:
    ans = L"SEC_E_CERT_EXPIRED";
    break;
  case 0x80090329:
    ans = L"SEC_E_ENCRYPT_FAILURE";
    break;
  case 0x80090330:
    ans = L"SEC_E_DECRYPT_FAILURE";
    break;
  case 0x80090331:
    ans = L"SEC_E_ALGORITHM_MISMATCH";
    break;
  case 0x80090332:
    ans = L"SEC_E_SECURITY_QOS_FAILED";
    break;
  case 0x80090333:
    ans = L"SEC_E_UNFINISHED_CONTEXT_DELETED";
    break;
  case 0x80090334:
    ans = L"SEC_E_NO_TGT_REPLY";
    break;
  case 0x80090335:
    ans = L"SEC_E_NO_IP_ADDRESSES";
    break;
  case 0x80090336:
    ans = L"SEC_E_WRONG_CREDENTIAL_HANDLE";
    break;
  case 0x80090337:
    ans = L"SEC_E_CRYPTO_SYSTEM_INVALID";
    break;
  case 0x80090338:
    ans = L"SEC_E_MAX_REFERRALS_EXCEEDED";
    break;
  case 0x80090339:
    ans = L"SEC_E_MUST_BE_KDC";
    break;
  case 0x8009033A:
    ans = L"SEC_E_STRONG_CRYPTO_NOT_SUPPORTED";
    break;
  case 0x8009033B:
    ans = L"SEC_E_TOO_MANY_PRINCIPALS";
    break;
  case 0x8009033C:
    ans = L"SEC_E_NO_PA_DATA";
    break;
  case 0x8009033D:
    ans = L"SEC_E_PKINIT_NAME_MISMATCH";
    break;
  case 0x8009033E:
    ans = L"SEC_E_SMARTCARD_LOGON_REQUIRED";
    break;
  case 0x8009033F:
    ans = L"SEC_E_SHUTDOWN_IN_PROGRESS";
    break;
  case 0x80090340:
    ans = L"SEC_E_KDC_INVALID_REQUEST";
    break;
  case 0x80090341:
    ans = L"SEC_E_KDC_UNABLE_TO_REFER";
    break;
  case 0x80090342:
    ans = L"SEC_E_KDC_UNKNOWN_ETYPE";
    break;
  case 0x80090343:
    ans = L"SEC_E_UNSUPPORTED_PREAUTH";
    break;
  case 0x80090345:
    ans = L"SEC_E_DELEGATION_REQUIRED";
    break;
  case 0x80090346:
    ans = L"SEC_E_BAD_BINDINGS";
    break;
  case 0x80090347:
    ans = L"SEC_E_MULTIPLE_ACCOUNTS";
    break;
  case 0x80090348:
    ans = L"SEC_E_NO_KERB_KEY";
    break;
  case 0x80090349:
    ans = L"SEC_E_CERT_WRONG_USAGE";
    break;
  case 0x80090350:
    ans = L"SEC_E_DOWNGRADE_DETECTED";
    break;
  case 0x80090351:
    ans = L"SEC_E_SMARTCARD_CERT_REVOKED";
    break;
  case 0x80090352:
    ans = L"SEC_E_ISSUING_CA_UNTRUSTED";
    break;
  case 0x80090353:
    ans = L"SEC_E_REVOCATION_OFFLINE_C";
    break;
  case 0x80090354:
    ans = L"SEC_E_PKINIT_CLIENT_FAILURE";
    break;
  case 0x80090355:
    ans = L"SEC_E_SMARTCARD_CERT_EXPIRED";
    break;
  case 0x80090356:
    ans = L"SEC_E_NO_S4U_PROT_SUPPORT";
    break;
  case 0x80090357:
    ans = L"SEC_E_CROSSREALM_DELEGATION_FAILURE";
    break;
  case 0x80090358:
    ans = L"SEC_E_REVOCATION_OFFLINE_KDC";
    break;
  case 0x80090359:
    ans = L"SEC_E_ISSUING_CA_UNTRUSTED_KDC";
    break;
  case 0x8009035A:
    ans = L"SEC_E_KDC_CERT_EXPIRED";
    break;
  case 0x8009035B:
    ans = L"SEC_E_KDC_CERT_REVOKED";
    break;
  case 0x0009035C:
    ans = L"SEC_I_SIGNATURE_NEEDED";
    break;
  case 0x8009035D:
    ans = L"SEC_E_INVALID_PARAMETER";
    break;
  case 0x8009035E:
    ans = L"SEC_E_DELEGATION_POLICY";
    break;
  case 0x8009035F:
    ans = L"SEC_E_POLICY_NLTM_ONLY";
    break;
  case 0x00090360:
    ans = L"SEC_I_NO_RENEGOTIATION";
    break;
  case 0x80090361:
    ans = L"SEC_E_NO_CONTEXT";
    break;
  case 0x80090362:
    ans = L"SEC_E_PKU2U_CERT_FAILURE";
    break;
  case 0x80090363:
    ans = L"SEC_E_MUTUAL_AUTH_FAILED";
    break;
  case 0x00090364:
    ans = L"SEC_I_MESSAGE_FRAGMENT";
    break;
  case 0x80090365:
    ans = L"SEC_E_ONLY_HTTPS_ALLOWED";
    break;
  case 0x00090366:
    ans = L"SEC_I_CONTINUE_NEEDED_MESSAGE_OK";
    break;
  case 0x80090367:
    ans = L"SEC_E_APPLICATION_PROTOCOL_MISMATCH";
    break;
  case 0x00090368:
    ans = L"SEC_I_ASYNC_CALL_PENDING";
    break;
  case 0x80090369:
    ans = L"SEC_E_INVALID_UPN_NAME";
    break;
  case 0x80091001:
    ans = L"CRYPT_E_MSG_ERROR";
    break;
  case 0x80091002:
    ans = L"CRYPT_E_UNKNOWN_ALGO";
    break;
  case 0x80091003:
    ans = L"CRYPT_E_OID_FORMAT";
    break;
  case 0x80091004:
    ans = L"CRYPT_E_INVALID_MSG_TYPE";
    break;
  case 0x80091005:
    ans = L"CRYPT_E_UNEXPECTED_ENCODING";
    break;
  case 0x80091006:
    ans = L"CRYPT_E_AUTH_ATTR_MISSING";
    break;
  case 0x80091007:
    ans = L"CRYPT_E_HASH_VALUE";
    break;
  case 0x80091008:
    ans = L"CRYPT_E_INVALID_INDEX";
    break;
  case 0x80091009:
    ans = L"CRYPT_E_ALREADY_DECRYPTED";
    break;
  case 0x8009100A:
    ans = L"CRYPT_E_NOT_DECRYPTED";
    break;
  case 0x8009100B:
    ans = L"CRYPT_E_RECIPIENT_NOT_FOUND";
    break;
  case 0x8009100C:
    ans = L"CRYPT_E_CONTROL_TYPE";
    break;
  case 0x8009100D:
    ans = L"CRYPT_E_ISSUER_SERIALNUMBER";
    break;
  case 0x8009100E:
    ans = L"CRYPT_E_SIGNER_NOT_FOUND";
    break;
  case 0x8009100F:
    ans = L"CRYPT_E_ATTRIBUTES_MISSING";
    break;
  case 0x80091010:
    ans = L"CRYPT_E_STREAM_MSG_NOT_READY";
    break;
  case 0x80091011:
    ans = L"CRYPT_E_STREAM_INSUFFICIENT_DATA";
    break;
  case 0x00091012:
    ans = L"CRYPT_I_NEW_PROTECTION_REQUIRED";
    break;
  case 0x80092001:
    ans = L"CRYPT_E_BAD_LEN";
    break;
  case 0x80092002:
    ans = L"CRYPT_E_BAD_ENCODE";
    break;
  case 0x80092003:
    ans = L"CRYPT_E_FILE_ERROR";
    break;
  case 0x80092004:
    ans = L"CRYPT_E_NOT_FOUND";
    break;
  case 0x80092005:
    ans = L"CRYPT_E_EXISTS";
    break;
  case 0x80092006:
    ans = L"CRYPT_E_NO_PROVIDER";
    break;
  case 0x80092007:
    ans = L"CRYPT_E_SELF_SIGNED";
    break;
  case 0x80092008:
    ans = L"CRYPT_E_DELETED_PREV";
    break;
  case 0x80092009:
    ans = L"CRYPT_E_NO_MATCH";
    break;
  case 0x8009200A:
    ans = L"CRYPT_E_UNEXPECTED_MSG_TYPE";
    break;
  case 0x8009200B:
    ans = L"CRYPT_E_NO_KEY_PROPERTY";
    break;
  case 0x8009200C:
    ans = L"CRYPT_E_NO_DECRYPT_CERT";
    break;
  case 0x8009200D:
    ans = L"CRYPT_E_BAD_MSG";
    break;
  case 0x8009200E:
    ans = L"CRYPT_E_NO_SIGNER";
    break;
  case 0x8009200F:
    ans = L"CRYPT_E_PENDING_CLOSE";
    break;
  case 0x80092010:
    ans = L"CRYPT_E_REVOKED";
    break;
  case 0x80092011:
    ans = L"CRYPT_E_NO_REVOCATION_DLL";
    break;
  case 0x80092012:
    ans = L"CRYPT_E_NO_REVOCATION_CHECK";
    break;
  case 0x80092013:
    ans = L"CRYPT_E_REVOCATION_OFFLINE";
    break;
  case 0x80092014:
    ans = L"CRYPT_E_NOT_IN_REVOCATION_DATABASE";
    break;
  case 0x80092020:
    ans = L"CRYPT_E_INVALID_NUMERIC_STRING";
    break;
  case 0x80092021:
    ans = L"CRYPT_E_INVALID_PRINTABLE_STRING";
    break;
  case 0x80092022:
    ans = L"CRYPT_E_INVALID_IA5_STRING";
    break;
  case 0x80092023:
    ans = L"CRYPT_E_INVALID_X500_STRING";
    break;
  case 0x80092024:
    ans = L"CRYPT_E_NOT_CHAR_STRING";
    break;
  case 0x80092025:
    ans = L"CRYPT_E_FILERESIZED";
    break;
  case 0x80092026:
    ans = L"CRYPT_E_SECURITY_SETTINGS";
    break;
  case 0x80092027:
    ans = L"CRYPT_E_NO_VERIFY_USAGE_DLL";
    break;
  case 0x80092028:
    ans = L"CRYPT_E_NO_VERIFY_USAGE_CHECK";
    break;
  case 0x80092029:
    ans = L"CRYPT_E_VERIFY_USAGE_OFFLINE";
    break;
  case 0x8009202A:
    ans = L"CRYPT_E_NOT_IN_CTL";
    break;
  case 0x8009202B:
    ans = L"CRYPT_E_NO_TRUSTED_SIGNER";
    break;
  case 0x8009202C:
    ans = L"CRYPT_E_MISSING_PUBKEY_PARA";
    break;
  case 0x8009202D:
    ans = L"CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND";
    break;
  case 0x80093000:
    ans = L"CRYPT_E_OSS_ERROR";
    break;
  case 0x80093001:
    ans = L"OSS_MORE_BUF";
    break;
  case 0x80093002:
    ans = L"OSS_NEGATIVE_UINTEGER";
    break;
  case 0x80093003:
    ans = L"OSS_PDU_RANGE";
    break;
  case 0x80093004:
    ans = L"OSS_MORE_INPUT";
    break;
  case 0x80093005:
    ans = L"OSS_DATA_ERROR";
    break;
  case 0x80093006:
    ans = L"OSS_BAD_ARG";
    break;
  case 0x80093007:
    ans = L"OSS_BAD_VERSION";
    break;
  case 0x80093008:
    ans = L"OSS_OUT_MEMORY";
    break;
  case 0x80093009:
    ans = L"OSS_PDU_MISMATCH";
    break;
  case 0x8009300A:
    ans = L"OSS_LIMITED";
    break;
  case 0x8009300B:
    ans = L"OSS_BAD_PTR";
    break;
  case 0x8009300C:
    ans = L"OSS_BAD_TIME";
    break;
  case 0x8009300D:
    ans = L"OSS_INDEFINITE_NOT_SUPPORTED";
    break;
  case 0x8009300E:
    ans = L"OSS_MEM_ERROR";
    break;
  case 0x8009300F:
    ans = L"OSS_BAD_TABLE";
    break;
  case 0x80093010:
    ans = L"OSS_TOO_LONG";
    break;
  case 0x80093011:
    ans = L"OSS_CONSTRAINT_VIOLATED";
    break;
  case 0x80093012:
    ans = L"OSS_FATAL_ERROR";
    break;
  case 0x80093013:
    ans = L"OSS_ACCESS_SERIALIZATION_ERROR";
    break;
  case 0x80093014:
    ans = L"OSS_NULL_TBL";
    break;
  case 0x80093015:
    ans = L"OSS_NULL_FCN";
    break;
  case 0x80093016:
    ans = L"OSS_BAD_ENCRULES";
    break;
  case 0x80093017:
    ans = L"OSS_UNAVAIL_ENCRULES";
    break;
  case 0x80093018:
    ans = L"OSS_CANT_OPEN_TRACE_WINDOW";
    break;
  case 0x80093019:
    ans = L"OSS_UNIMPLEMENTED";
    break;
  case 0x8009301A:
    ans = L"OSS_OID_DLL_NOT_LINKED";
    break;
  case 0x8009301B:
    ans = L"OSS_CANT_OPEN_TRACE_FILE";
    break;
  case 0x8009301C:
    ans = L"OSS_TRACE_FILE_ALREADY_OPEN";
    break;
  case 0x8009301D:
    ans = L"OSS_TABLE_MISMATCH";
    break;
  case 0x8009301E:
    ans = L"OSS_TYPE_NOT_SUPPORTED";
    break;
  case 0x8009301F:
    ans = L"OSS_REAL_DLL_NOT_LINKED";
    break;
  case 0x80093020:
    ans = L"OSS_REAL_CODE_NOT_LINKED";
    break;
  case 0x80093021:
    ans = L"OSS_OUT_OF_RANGE";
    break;
  case 0x80093022:
    ans = L"OSS_COPIER_DLL_NOT_LINKED";
    break;
  case 0x80093023:
    ans = L"OSS_CONSTRAINT_DLL_NOT_LINKED";
    break;
  case 0x80093024:
    ans = L"OSS_COMPARATOR_DLL_NOT_LINKED";
    break;
  case 0x80093025:
    ans = L"OSS_COMPARATOR_CODE_NOT_LINKED";
    break;
  case 0x80093026:
    ans = L"OSS_MEM_MGR_DLL_NOT_LINKED";
    break;
  case 0x80093027:
    ans = L"OSS_PDV_DLL_NOT_LINKED";
    break;
  case 0x80093028:
    ans = L"OSS_PDV_CODE_NOT_LINKED";
    break;
  case 0x80093029:
    ans = L"OSS_API_DLL_NOT_LINKED";
    break;
  case 0x8009302A:
    ans = L"OSS_BERDER_DLL_NOT_LINKED";
    break;
  case 0x8009302B:
    ans = L"OSS_PER_DLL_NOT_LINKED";
    break;
  case 0x8009302C:
    ans = L"OSS_OPEN_TYPE_ERROR";
    break;
  case 0x8009302D:
    ans = L"OSS_MUTEX_NOT_CREATED";
    break;
  case 0x8009302E:
    ans = L"OSS_CANT_CLOSE_TRACE_FILE";
    break;
  case 0x80093100:
    ans = L"CRYPT_E_ASN1_ERROR";
    break;
  case 0x80093101:
    ans = L"CRYPT_E_ASN1_INTERNAL";
    break;
  case 0x80093102:
    ans = L"CRYPT_E_ASN1_EOD";
    break;
  case 0x80093103:
    ans = L"CRYPT_E_ASN1_CORRUPT";
    break;
  case 0x80093104:
    ans = L"CRYPT_E_ASN1_LARGE";
    break;
  case 0x80093105:
    ans = L"CRYPT_E_ASN1_CONSTRAINT";
    break;
  case 0x80093106:
    ans = L"CRYPT_E_ASN1_MEMORY";
    break;
  case 0x80093107:
    ans = L"CRYPT_E_ASN1_OVERFLOW";
    break;
  case 0x80093108:
    ans = L"CRYPT_E_ASN1_BADPDU";
    break;
  case 0x80093109:
    ans = L"CRYPT_E_ASN1_BADARGS";
    break;
  case 0x8009310A:
    ans = L"CRYPT_E_ASN1_BADREAL";
    break;
  case 0x8009310B:
    ans = L"CRYPT_E_ASN1_BADTAG";
    break;
  case 0x8009310C:
    ans = L"CRYPT_E_ASN1_CHOICE";
    break;
  case 0x8009310D:
    ans = L"CRYPT_E_ASN1_RULE";
    break;
  case 0x8009310E:
    ans = L"CRYPT_E_ASN1_UTF8";
    break;
  case 0x80093133:
    ans = L"CRYPT_E_ASN1_PDU_TYPE";
    break;
  case 0x80093134:
    ans = L"CRYPT_E_ASN1_NYI";
    break;
  case 0x80093201:
    ans = L"CRYPT_E_ASN1_EXTENDED";
    break;
  case 0x80093202:
    ans = L"CRYPT_E_ASN1_NOEOD";
    break;
  case 0x80094001:
    ans = L"CERTSRV_E_BAD_REQUESTSUBJECT";
    break;
  case 0x80094002:
    ans = L"CERTSRV_E_NO_REQUEST";
    break;
  case 0x80094003:
    ans = L"CERTSRV_E_BAD_REQUESTSTATUS";
    break;
  case 0x80094004:
    ans = L"CERTSRV_E_PROPERTY_EMPTY";
    break;
  case 0x80094005:
    ans = L"CERTSRV_E_INVALID_CA_CERTIFICATE";
    break;
  case 0x80094006:
    ans = L"CERTSRV_E_SERVER_SUSPENDED";
    break;
  case 0x80094007:
    ans = L"CERTSRV_E_ENCODING_LENGTH";
    break;
  case 0x80094008:
    ans = L"CERTSRV_E_ROLECONFLICT";
    break;
  case 0x80094009:
    ans = L"CERTSRV_E_RESTRICTEDOFFICER";
    break;
  case 0x8009400A:
    ans = L"CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED";
    break;
  case 0x8009400B:
    ans = L"CERTSRV_E_NO_VALID_KRA";
    break;
  case 0x8009400C:
    ans = L"CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL";
    break;
  case 0x8009400D:
    ans = L"CERTSRV_E_NO_CAADMIN_DEFINED";
    break;
  case 0x8009400E:
    ans = L"CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE";
    break;
  case 0x8009400F:
    ans = L"CERTSRV_E_NO_DB_SESSIONS";
    break;
  case 0x80094010:
    ans = L"CERTSRV_E_ALIGNMENT_FAULT";
    break;
  case 0x80094011:
    ans = L"CERTSRV_E_ENROLL_DENIED";
    break;
  case 0x80094012:
    ans = L"CERTSRV_E_TEMPLATE_DENIED";
    break;
  case 0x80094013:
    ans = L"CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE";
    break;
  case 0x80094014:
    ans = L"CERTSRV_E_ADMIN_DENIED_REQUEST";
    break;
  case 0x80094015:
    ans = L"CERTSRV_E_NO_POLICY_SERVER";
    break;
  case 0x80094016:
    ans = L"CERTSRV_E_WEAK_SIGNATURE_OR_KEY";
    break;
  case 0x80094017:
    ans = L"CERTSRV_E_KEY_ATTESTATION_NOT_SUPPORTED";
    break;
  case 0x80094018:
    ans = L"CERTSRV_E_ENCRYPTION_CERT_REQUIRED";
    break;
  case 0x80094800:
    ans = L"CERTSRV_E_UNSUPPORTED_CERT_TYPE";
    break;
  case 0x80094801:
    ans = L"CERTSRV_E_NO_CERT_TYPE";
    break;
  case 0x80094802:
    ans = L"CERTSRV_E_TEMPLATE_CONFLICT";
    break;
  case 0x80094803:
    ans = L"CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED";
    break;
  case 0x80094804:
    ans = L"CERTSRV_E_ARCHIVED_KEY_REQUIRED";
    break;
  case 0x80094805:
    ans = L"CERTSRV_E_SMIME_REQUIRED";
    break;
  case 0x80094806:
    ans = L"CERTSRV_E_BAD_RENEWAL_SUBJECT";
    break;
  case 0x80094807:
    ans = L"CERTSRV_E_BAD_TEMPLATE_VERSION";
    break;
  case 0x80094808:
    ans = L"CERTSRV_E_TEMPLATE_POLICY_REQUIRED";
    break;
  case 0x80094809:
    ans = L"CERTSRV_E_SIGNATURE_POLICY_REQUIRED";
    break;
  case 0x8009480A:
    ans = L"CERTSRV_E_SIGNATURE_COUNT";
    break;
  case 0x8009480B:
    ans = L"CERTSRV_E_SIGNATURE_REJECTED";
    break;
  case 0x8009480C:
    ans = L"CERTSRV_E_ISSUANCE_POLICY_REQUIRED";
    break;
  case 0x8009480D:
    ans = L"CERTSRV_E_SUBJECT_UPN_REQUIRED";
    break;
  case 0x8009480E:
    ans = L"CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED";
    break;
  case 0x8009480F:
    ans = L"CERTSRV_E_SUBJECT_DNS_REQUIRED";
    break;
  case 0x80094810:
    ans = L"CERTSRV_E_ARCHIVED_KEY_UNEXPECTED";
    break;
  case 0x80094811:
    ans = L"CERTSRV_E_KEY_LENGTH";
    break;
  case 0x80094812:
    ans = L"CERTSRV_E_SUBJECT_EMAIL_REQUIRED";
    break;
  case 0x80094813:
    ans = L"CERTSRV_E_UNKNOWN_CERT_TYPE";
    break;
  case 0x80094814:
    ans = L"CERTSRV_E_CERT_TYPE_OVERLAP";
    break;
  case 0x80094815:
    ans = L"CERTSRV_E_TOO_MANY_SIGNATURES";
    break;
  case 0x80094816:
    ans = L"CERTSRV_E_RENEWAL_BAD_PUBLIC_KEY";
    break;
  case 0x80094817:
    ans = L"CERTSRV_E_INVALID_EK";
    break;
  case 0x80094818:
    ans = L"CERTSRV_E_INVALID_IDBINDING";
    break;
  case 0x80094819:
    ans = L"CERTSRV_E_INVALID_ATTESTATION";
    break;
  case 0x8009481A:
    ans = L"CERTSRV_E_KEY_ATTESTATION";
    break;
  case 0x8009481B:
    ans = L"CERTSRV_E_CORRUPT_KEY_ATTESTATION";
    break;
  case 0x8009481C:
    ans = L"CERTSRV_E_EXPIRED_CHALLENGE";
    break;
  case 0x8009481D:
    ans = L"CERTSRV_E_INVALID_RESPONSE";
    break;
  case 0x8009481E:
    ans = L"CERTSRV_E_INVALID_REQUESTID";
    break;
  case 0x8009481F:
    ans = L"CERTSRV_E_REQUEST_PRECERTIFICATE_MISMATCH";
    break;
  case 0x80094820:
    ans = L"CERTSRV_E_PENDING_CLIENT_RESPONSE";
    break;
  case 0x80095000:
    ans = L"XENROLL_E_KEY_NOT_EXPORTABLE";
    break;
  case 0x80095001:
    ans = L"XENROLL_E_CANNOT_ADD_ROOT_CERT";
    break;
  case 0x80095002:
    ans = L"XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND";
    break;
  case 0x80095003:
    ans = L"XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH";
    break;
  case 0x80095004:
    ans = L"XENROLL_E_RESPONSE_KA_HASH_MISMATCH";
    break;
  case 0x80095005:
    ans = L"XENROLL_E_KEYSPEC_SMIME_MISMATCH";
    break;
  case 0x80096001:
    ans = L"TRUST_E_SYSTEM_ERROR";
    break;
  case 0x80096002:
    ans = L"TRUST_E_NO_SIGNER_CERT";
    break;
  case 0x80096003:
    ans = L"TRUST_E_COUNTER_SIGNER";
    break;
  case 0x80096004:
    ans = L"TRUST_E_CERT_SIGNATURE";
    break;
  case 0x80096005:
    ans = L"TRUST_E_TIME_STAMP";
    break;
  case 0x80096010:
    ans = L"TRUST_E_BAD_DIGEST";
    break;
  case 0x80096011:
    ans = L"TRUST_E_MALFORMED_SIGNATURE";
    break;
  case 0x80096019:
    ans = L"TRUST_E_BASIC_CONSTRAINTS";
    break;
  case 0x8009601E:
    ans = L"TRUST_E_FINANCIAL_CRITERIA";
    break;
  case 0x80097001:
    ans = L"MSSIPOTF_E_OUTOFMEMRANGE";
    break;
  case 0x80097002:
    ans = L"MSSIPOTF_E_CANTGETOBJECT";
    break;
  case 0x80097003:
    ans = L"MSSIPOTF_E_NOHEADTABLE";
    break;
  case 0x80097004:
    ans = L"MSSIPOTF_E_BAD_MAGICNUMBER";
    break;
  case 0x80097005:
    ans = L"MSSIPOTF_E_BAD_OFFSET_TABLE";
    break;
  case 0x80097006:
    ans = L"MSSIPOTF_E_TABLE_TAGORDER";
    break;
  case 0x80097007:
    ans = L"MSSIPOTF_E_TABLE_LONGWORD";
    break;
  case 0x80097008:
    ans = L"MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT";
    break;
  case 0x80097009:
    ans = L"MSSIPOTF_E_TABLES_OVERLAP";
    break;
  case 0x8009700A:
    ans = L"MSSIPOTF_E_TABLE_PADBYTES";
    break;
  case 0x8009700B:
    ans = L"MSSIPOTF_E_FILETOOSMALL";
    break;
  case 0x8009700C:
    ans = L"MSSIPOTF_E_TABLE_CHECKSUM";
    break;
  case 0x8009700D:
    ans = L"MSSIPOTF_E_FILE_CHECKSUM";
    break;
  case 0x80097010:
    ans = L"MSSIPOTF_E_FAILED_POLICY";
    break;
  case 0x80097011:
    ans = L"MSSIPOTF_E_FAILED_HINTS_CHECK";
    break;
  case 0x80097012:
    ans = L"MSSIPOTF_E_NOT_OPENTYPE";
    break;
  case 0x80097013:
    ans = L"MSSIPOTF_E_FILE";
    break;
  case 0x80097014:
    ans = L"MSSIPOTF_E_CRYPT";
    break;
  case 0x80097015:
    ans = L"MSSIPOTF_E_BADVERSION";
    break;
  case 0x80097016:
    ans = L"MSSIPOTF_E_DSIG_STRUCTURE";
    break;
  case 0x80097017:
    ans = L"MSSIPOTF_E_PCONST_CHECK";
    break;
  case 0x80097018:
    ans = L"MSSIPOTF_E_STRUCTURE";
    break;
  case 0x80097019:
    ans = L"ERROR_CRED_REQUIRES_CONFIRMATION";
    break;
  case 0x800B0001:
    ans = L"TRUST_E_PROVIDER_UNKNOWN";
    break;
  case 0x800B0002:
    ans = L"TRUST_E_ACTION_UNKNOWN";
    break;
  case 0x800B0003:
    ans = L"TRUST_E_SUBJECT_FORM_UNKNOWN";
    break;
  case 0x800B0004:
    ans = L"TRUST_E_SUBJECT_NOT_TRUSTED";
    break;
  case 0x800B0005:
    ans = L"DIGSIG_E_ENCODE";
    break;
  case 0x800B0006:
    ans = L"DIGSIG_E_DECODE";
    break;
  case 0x800B0007:
    ans = L"DIGSIG_E_EXTENSIBILITY";
    break;
  case 0x800B0008:
    ans = L"DIGSIG_E_CRYPTO";
    break;
  case 0x800B0009:
    ans = L"PERSIST_E_SIZEDEFINITE";
    break;
  case 0x800B000A:
    ans = L"PERSIST_E_SIZEINDEFINITE";
    break;
  case 0x800B000B:
    ans = L"PERSIST_E_NOTSELFSIZING";
    break;
  case 0x800B0100:
    ans = L"TRUST_E_NOSIGNATURE";
    break;
  case 0x800B0101:
    ans = L"CERT_E_EXPIRED";
    break;
  case 0x800B0102:
    ans = L"CERT_E_VALIDITYPERIODNESTING";
    break;
  case 0x800B0103:
    ans = L"CERT_E_ROLE";
    break;
  case 0x800B0104:
    ans = L"CERT_E_PATHLENCONST";
    break;
  case 0x800B0105:
    ans = L"CERT_E_CRITICAL";
    break;
  case 0x800B0106:
    ans = L"CERT_E_PURPOSE";
    break;
  case 0x800B0107:
    ans = L"CERT_E_ISSUERCHAINING";
    break;
  case 0x800B0108:
    ans = L"CERT_E_MALFORMED";
    break;
  case 0x800B0109:
    ans = L"CERT_E_UNTRUSTEDROOT";
    break;
  case 0x800B010A:
    ans = L"CERT_E_CHAINING";
    break;
  case 0x800B010B:
    ans = L"TRUST_E_FAIL";
    break;
  case 0x800B010C:
    ans = L"CERT_E_REVOKED";
    break;
  case 0x800B010D:
    ans = L"CERT_E_UNTRUSTEDTESTROOT";
    break;
  case 0x800B010E:
    ans = L"CERT_E_REVOCATION_FAILURE";
    break;
  case 0x800B010F:
    ans = L"CERT_E_CN_NO_MATCH";
    break;
  case 0x800B0110:
    ans = L"CERT_E_WRONG_USAGE";
    break;
  case 0x800B0111:
    ans = L"TRUST_E_EXPLICIT_DISTRUST";
    break;
  case 0x800B0112:
    ans = L"CERT_E_UNTRUSTEDCA";
    break;
  case 0x800B0113:
    ans = L"CERT_E_INVALID_POLICY";
    break;
  case 0x800B0114:
    ans = L"CERT_E_INVALID_NAME";
    break;
  case 0x800F0000:
    ans = L"SPAPI_E_EXPECTED_SECTION_NAME";
    break;
  case 0x800F0001:
    ans = L"SPAPI_E_BAD_SECTION_NAME_LINE";
    break;
  case 0x800F0002:
    ans = L"SPAPI_E_SECTION_NAME_TOO_LONG";
    break;
  case 0x800F0003:
    ans = L"SPAPI_E_GENERAL_SYNTAX";
    break;
  case 0x800F0100:
    ans = L"SPAPI_E_WRONG_INF_STYLE";
    break;
  case 0x800F0101:
    ans = L"SPAPI_E_SECTION_NOT_FOUND";
    break;
  case 0x800F0102:
    ans = L"SPAPI_E_LINE_NOT_FOUND";
    break;
  case 0x800F0103:
    ans = L"SPAPI_E_NO_BACKUP";
    break;
  case 0x800F0200:
    ans = L"SPAPI_E_NO_ASSOCIATED_CLASS";
    break;
  case 0x800F0201:
    ans = L"SPAPI_E_CLASS_MISMATCH";
    break;
  case 0x800F0202:
    ans = L"SPAPI_E_DUPLICATE_FOUND";
    break;
  case 0x800F0203:
    ans = L"SPAPI_E_NO_DRIVER_SELECTED";
    break;
  case 0x800F0204:
    ans = L"SPAPI_E_KEY_DOES_NOT_EXIST";
    break;
  case 0x800F0205:
    ans = L"SPAPI_E_INVALID_DEVINST_NAME";
    break;
  case 0x800F0206:
    ans = L"SPAPI_E_INVALID_CLASS";
    break;
  case 0x800F0207:
    ans = L"SPAPI_E_DEVINST_ALREADY_EXISTS";
    break;
  case 0x800F0208:
    ans = L"SPAPI_E_DEVINFO_NOT_REGISTERED";
    break;
  case 0x800F0209:
    ans = L"SPAPI_E_INVALID_REG_PROPERTY";
    break;
  case 0x800F020A:
    ans = L"SPAPI_E_NO_INF";
    break;
  case 0x800F020B:
    ans = L"SPAPI_E_NO_SUCH_DEVINST";
    break;
  case 0x800F020C:
    ans = L"SPAPI_E_CANT_LOAD_CLASS_ICON";
    break;
  case 0x800F020D:
    ans = L"SPAPI_E_INVALID_CLASS_INSTALLER";
    break;
  case 0x800F020E:
    ans = L"SPAPI_E_DI_DO_DEFAULT";
    break;
  case 0x800F020F:
    ans = L"SPAPI_E_DI_NOFILECOPY";
    break;
  case 0x800F0210:
    ans = L"SPAPI_E_INVALID_HWPROFILE";
    break;
  case 0x800F0211:
    ans = L"SPAPI_E_NO_DEVICE_SELECTED";
    break;
  case 0x800F0212:
    ans = L"SPAPI_E_DEVINFO_LIST_LOCKED";
    break;
  case 0x800F0213:
    ans = L"SPAPI_E_DEVINFO_DATA_LOCKED";
    break;
  case 0x800F0214:
    ans = L"SPAPI_E_DI_BAD_PATH";
    break;
  case 0x800F0215:
    ans = L"SPAPI_E_NO_CLASSINSTALL_PARAMS";
    break;
  case 0x800F0216:
    ans = L"SPAPI_E_FILEQUEUE_LOCKED";
    break;
  case 0x800F0217:
    ans = L"SPAPI_E_BAD_SERVICE_INSTALLSECT";
    break;
  case 0x800F0218:
    ans = L"SPAPI_E_NO_CLASS_DRIVER_LIST";
    break;
  case 0x800F0219:
    ans = L"SPAPI_E_NO_ASSOCIATED_SERVICE";
    break;
  case 0x800F021A:
    ans = L"SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE";
    break;
  case 0x800F021B:
    ans = L"SPAPI_E_DEVICE_INTERFACE_ACTIVE";
    break;
  case 0x800F021C:
    ans = L"SPAPI_E_DEVICE_INTERFACE_REMOVED";
    break;
  case 0x800F021D:
    ans = L"SPAPI_E_BAD_INTERFACE_INSTALLSECT";
    break;
  case 0x800F021E:
    ans = L"SPAPI_E_NO_SUCH_INTERFACE_CLASS";
    break;
  case 0x800F021F:
    ans = L"SPAPI_E_INVALID_REFERENCE_STRING";
    break;
  case 0x800F0220:
    ans = L"SPAPI_E_INVALID_MACHINENAME";
    break;
  case 0x800F0221:
    ans = L"SPAPI_E_REMOTE_COMM_FAILURE";
    break;
  case 0x800F0222:
    ans = L"SPAPI_E_MACHINE_UNAVAILABLE";
    break;
  case 0x800F0223:
    ans = L"SPAPI_E_NO_CONFIGMGR_SERVICES";
    break;
  case 0x800F0224:
    ans = L"SPAPI_E_INVALID_PROPPAGE_PROVIDER";
    break;
  case 0x800F0225:
    ans = L"SPAPI_E_NO_SUCH_DEVICE_INTERFACE";
    break;
  case 0x800F0226:
    ans = L"SPAPI_E_DI_POSTPROCESSING_REQUIRED";
    break;
  case 0x800F0227:
    ans = L"SPAPI_E_INVALID_COINSTALLER";
    break;
  case 0x800F0228:
    ans = L"SPAPI_E_NO_COMPAT_DRIVERS";
    break;
  case 0x800F0229:
    ans = L"SPAPI_E_NO_DEVICE_ICON";
    break;
  case 0x800F022A:
    ans = L"SPAPI_E_INVALID_INF_LOGCONFIG";
    break;
  case 0x800F022B:
    ans = L"SPAPI_E_DI_DONT_INSTALL";
    break;
  case 0x800F022C:
    ans = L"SPAPI_E_INVALID_FILTER_DRIVER";
    break;
  case 0x800F022D:
    ans = L"SPAPI_E_NON_WINDOWS_NT_DRIVER";
    break;
  case 0x800F022E:
    ans = L"SPAPI_E_NON_WINDOWS_DRIVER";
    break;
  case 0x800F022F:
    ans = L"SPAPI_E_NO_CATALOG_FOR_OEM_INF";
    break;
  case 0x800F0230:
    ans = L"SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE";
    break;
  case 0x800F0231:
    ans = L"SPAPI_E_NOT_DISABLEABLE";
    break;
  case 0x800F0232:
    ans = L"SPAPI_E_CANT_REMOVE_DEVINST";
    break;
  case 0x800F0233:
    ans = L"SPAPI_E_INVALID_TARGET";
    break;
  case 0x800F0234:
    ans = L"SPAPI_E_DRIVER_NONNATIVE";
    break;
  case 0x800F0235:
    ans = L"SPAPI_E_IN_WOW64";
    break;
  case 0x800F0236:
    ans = L"SPAPI_E_SET_SYSTEM_RESTORE_POINT";
    break;
  case 0x800F0237:
    ans = L"SPAPI_E_INCORRECTLY_COPIED_INF";
    break;
  case 0x800F0238:
    ans = L"SPAPI_E_SCE_DISABLED";
    break;
  case 0x800F0239:
    ans = L"SPAPI_E_UNKNOWN_EXCEPTION";
    break;
  case 0x800F023A:
    ans = L"SPAPI_E_PNP_REGISTRY_ERROR";
    break;
  case 0x800F023B:
    ans = L"SPAPI_E_REMOTE_REQUEST_UNSUPPORTED";
    break;
  case 0x800F023C:
    ans = L"SPAPI_E_NOT_AN_INSTALLED_OEM_INF";
    break;
  case 0x800F023D:
    ans = L"SPAPI_E_INF_IN_USE_BY_DEVICES";
    break;
  case 0x800F023E:
    ans = L"SPAPI_E_DI_FUNCTION_OBSOLETE";
    break;
  case 0x800F023F:
    ans = L"SPAPI_E_NO_AUTHENTICODE_CATALOG";
    break;
  case 0x800F0240:
    ans = L"SPAPI_E_AUTHENTICODE_DISALLOWED";
    break;
  case 0x800F0241:
    ans = L"SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER";
    break;
  case 0x800F0242:
    ans = L"SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED";
    break;
  case 0x800F0243:
    ans = L"SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED";
    break;
  case 0x800F0244:
    ans = L"SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH";
    break;
  case 0x800F0245:
    ans = L"SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE";
    break;
  case 0x800F0246:
    ans = L"SPAPI_E_DEVICE_INSTALLER_NOT_READY";
    break;
  case 0x800F0247:
    ans = L"SPAPI_E_DRIVER_STORE_ADD_FAILED";
    break;
  case 0x800F0248:
    ans = L"SPAPI_E_DEVICE_INSTALL_BLOCKED";
    break;
  case 0x800F0249:
    ans = L"SPAPI_E_DRIVER_INSTALL_BLOCKED";
    break;
  case 0x800F024A:
    ans = L"SPAPI_E_WRONG_INF_TYPE";
    break;
  case 0x800F024B:
    ans = L"SPAPI_E_FILE_HASH_NOT_IN_CATALOG";
    break;
  case 0x800F024C:
    ans = L"SPAPI_E_DRIVER_STORE_DELETE_FAILED";
    break;
  case 0x800F0300:
    ans = L"SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW";
    break;
  case 0x800F1000:
    ans = L"SPAPI_E_ERROR_NOT_INSTALLED";
    break;
  case 0x80100001:
    ans = L"SCARD_F_INTERNAL_ERROR";
    break;
  case 0x80100002:
    ans = L"SCARD_E_CANCELLED";
    break;
  case 0x80100003:
    ans = L"SCARD_E_INVALID_HANDLE";
    break;
  case 0x80100004:
    ans = L"SCARD_E_INVALID_PARAMETER";
    break;
  case 0x80100005:
    ans = L"SCARD_E_INVALID_TARGET";
    break;
  case 0x80100006:
    ans = L"SCARD_E_NO_MEMORY";
    break;
  case 0x80100007:
    ans = L"SCARD_F_WAITED_TOO_LONG";
    break;
  case 0x80100008:
    ans = L"SCARD_E_INSUFFICIENT_BUFFER";
    break;
  case 0x80100009:
    ans = L"SCARD_E_UNKNOWN_READER";
    break;
  case 0x8010000A:
    ans = L"SCARD_E_TIMEOUT";
    break;
  case 0x8010000B:
    ans = L"SCARD_E_SHARING_VIOLATION";
    break;
  case 0x8010000C:
    ans = L"SCARD_E_NO_SMARTCARD";
    break;
  case 0x8010000D:
    ans = L"SCARD_E_UNKNOWN_CARD";
    break;
  case 0x8010000E:
    ans = L"SCARD_E_CANT_DISPOSE";
    break;
  case 0x8010000F:
    ans = L"SCARD_E_PROTO_MISMATCH";
    break;
  case 0x80100010:
    ans = L"SCARD_E_NOT_READY";
    break;
  case 0x80100011:
    ans = L"SCARD_E_INVALID_VALUE";
    break;
  case 0x80100012:
    ans = L"SCARD_E_SYSTEM_CANCELLED";
    break;
  case 0x80100013:
    ans = L"SCARD_F_COMM_ERROR";
    break;
  case 0x80100014:
    ans = L"SCARD_F_UNKNOWN_ERROR";
    break;
  case 0x80100015:
    ans = L"SCARD_E_INVALID_ATR";
    break;
  case 0x80100016:
    ans = L"SCARD_E_NOT_TRANSACTED";
    break;
  case 0x80100017:
    ans = L"SCARD_E_READER_UNAVAILABLE";
    break;
  case 0x80100018:
    ans = L"SCARD_P_SHUTDOWN";
    break;
  case 0x80100019:
    ans = L"SCARD_E_PCI_TOO_SMALL";
    break;
  case 0x8010001A:
    ans = L"SCARD_E_READER_UNSUPPORTED";
    break;
  case 0x8010001B:
    ans = L"SCARD_E_DUPLICATE_READER";
    break;
  case 0x8010001C:
    ans = L"SCARD_E_CARD_UNSUPPORTED";
    break;
  case 0x8010001D:
    ans = L"SCARD_E_NO_SERVICE";
    break;
  case 0x8010001E:
    ans = L"SCARD_E_SERVICE_STOPPED";
    break;
  case 0x8010001F:
    ans = L"SCARD_E_UNEXPECTED";
    break;
  case 0x80100020:
    ans = L"SCARD_E_ICC_INSTALLATION";
    break;
  case 0x80100021:
    ans = L"SCARD_E_ICC_CREATEORDER";
    break;
  case 0x80100022:
    ans = L"SCARD_E_UNSUPPORTED_FEATURE";
    break;
  case 0x80100023:
    ans = L"SCARD_E_DIR_NOT_FOUND";
    break;
  case 0x80100024:
    ans = L"SCARD_E_FILE_NOT_FOUND";
    break;
  case 0x80100025:
    ans = L"SCARD_E_NO_DIR";
    break;
  case 0x80100026:
    ans = L"SCARD_E_NO_FILE";
    break;
  case 0x80100027:
    ans = L"SCARD_E_NO_ACCESS";
    break;
  case 0x80100028:
    ans = L"SCARD_E_WRITE_TOO_MANY";
    break;
  case 0x80100029:
    ans = L"SCARD_E_BAD_SEEK";
    break;
  case 0x8010002A:
    ans = L"SCARD_E_INVALID_CHV";
    break;
  case 0x8010002B:
    ans = L"SCARD_E_UNKNOWN_RES_MNG";
    break;
  case 0x8010002C:
    ans = L"SCARD_E_NO_SUCH_CERTIFICATE";
    break;
  case 0x8010002D:
    ans = L"SCARD_E_CERTIFICATE_UNAVAILABLE";
    break;
  case 0x8010002E:
    ans = L"SCARD_E_NO_READERS_AVAILABLE";
    break;
  case 0x8010002F:
    ans = L"SCARD_E_COMM_DATA_LOST";
    break;
  case 0x80100030:
    ans = L"SCARD_E_NO_KEY_CONTAINER";
    break;
  case 0x80100031:
    ans = L"SCARD_E_SERVER_TOO_BUSY";
    break;
  case 0x80100032:
    ans = L"SCARD_E_PIN_CACHE_EXPIRED";
    break;
  case 0x80100033:
    ans = L"SCARD_E_NO_PIN_CACHE";
    break;
  case 0x80100034:
    ans = L"SCARD_E_READ_ONLY_CARD";
    break;
  case 0x80100065:
    ans = L"SCARD_W_UNSUPPORTED_CARD";
    break;
  case 0x80100066:
    ans = L"SCARD_W_UNRESPONSIVE_CARD";
    break;
  case 0x80100067:
    ans = L"SCARD_W_UNPOWERED_CARD";
    break;
  case 0x80100068:
    ans = L"SCARD_W_RESET_CARD";
    break;
  case 0x80100069:
    ans = L"SCARD_W_REMOVED_CARD";
    break;
  case 0x8010006A:
    ans = L"SCARD_W_SECURITY_VIOLATION";
    break;
  case 0x8010006B:
    ans = L"SCARD_W_WRONG_CHV";
    break;
  case 0x8010006C:
    ans = L"SCARD_W_CHV_BLOCKED";
    break;
  case 0x8010006D:
    ans = L"SCARD_W_EOF";
    break;
  case 0x8010006E:
    ans = L"SCARD_W_CANCELLED_BY_USER";
    break;
  case 0x8010006F:
    ans = L"SCARD_W_CARD_NOT_AUTHENTICATED";
    break;
  case 0x80100070:
    ans = L"SCARD_W_CACHE_ITEM_NOT_FOUND";
    break;
  case 0x80100071:
    ans = L"SCARD_W_CACHE_ITEM_STALE";
    break;
  case 0x80100072:
    ans = L"SCARD_W_CACHE_ITEM_TOO_BIG";
    break;
  case 0x80110401:
    ans = L"COMADMIN_E_OBJECTERRORS";
    break;
  case 0x80110402:
    ans = L"COMADMIN_E_OBJECTINVALID";
    break;
  case 0x80110403:
    ans = L"COMADMIN_E_KEYMISSING";
    break;
  case 0x80110404:
    ans = L"COMADMIN_E_ALREADYINSTALLED";
    break;
  case 0x80110407:
    ans = L"COMADMIN_E_APP_FILE_WRITEFAIL";
    break;
  case 0x80110408:
    ans = L"COMADMIN_E_APP_FILE_READFAIL";
    break;
  case 0x80110409:
    ans = L"COMADMIN_E_APP_FILE_VERSION";
    break;
  case 0x8011040A:
    ans = L"COMADMIN_E_BADPATH";
    break;
  case 0x8011040B:
    ans = L"COMADMIN_E_APPLICATIONEXISTS";
    break;
  case 0x8011040C:
    ans = L"COMADMIN_E_ROLEEXISTS";
    break;
  case 0x8011040D:
    ans = L"COMADMIN_E_CANTCOPYFILE";
    break;
  case 0x8011040F:
    ans = L"COMADMIN_E_NOUSER";
    break;
  case 0x80110410:
    ans = L"COMADMIN_E_INVALIDUSERIDS";
    break;
  case 0x80110411:
    ans = L"COMADMIN_E_NOREGISTRYCLSID";
    break;
  case 0x80110412:
    ans = L"COMADMIN_E_BADREGISTRYPROGID";
    break;
  case 0x80110413:
    ans = L"COMADMIN_E_AUTHENTICATIONLEVEL";
    break;
  case 0x80110414:
    ans = L"COMADMIN_E_USERPASSWDNOTVALID";
    break;
  case 0x80110418:
    ans = L"COMADMIN_E_CLSIDORIIDMISMATCH";
    break;
  case 0x80110419:
    ans = L"COMADMIN_E_REMOTEINTERFACE";
    break;
  case 0x8011041A:
    ans = L"COMADMIN_E_DLLREGISTERSERVER";
    break;
  case 0x8011041B:
    ans = L"COMADMIN_E_NOSERVERSHARE";
    break;
  case 0x8011041D:
    ans = L"COMADMIN_E_DLLLOADFAILED";
    break;
  case 0x8011041E:
    ans = L"COMADMIN_E_BADREGISTRYLIBID";
    break;
  case 0x8011041F:
    ans = L"COMADMIN_E_APPDIRNOTFOUND";
    break;
  case 0x80110423:
    ans = L"COMADMIN_E_REGISTRARFAILED";
    break;
  case 0x80110424:
    ans = L"COMADMIN_E_COMPFILE_DOESNOTEXIST";
    break;
  case 0x80110425:
    ans = L"COMADMIN_E_COMPFILE_LOADDLLFAIL";
    break;
  case 0x80110426:
    ans = L"COMADMIN_E_COMPFILE_GETCLASSOBJ";
    break;
  case 0x80110427:
    ans = L"COMADMIN_E_COMPFILE_CLASSNOTAVAIL";
    break;
  case 0x80110428:
    ans = L"COMADMIN_E_COMPFILE_BADTLB";
    break;
  case 0x80110429:
    ans = L"COMADMIN_E_COMPFILE_NOTINSTALLABLE";
    break;
  case 0x8011042A:
    ans = L"COMADMIN_E_NOTCHANGEABLE";
    break;
  case 0x8011042B:
    ans = L"COMADMIN_E_NOTDELETEABLE";
    break;
  case 0x8011042C:
    ans = L"COMADMIN_E_SESSION";
    break;
  case 0x8011042D:
    ans = L"COMADMIN_E_COMP_MOVE_LOCKED";
    break;
  case 0x8011042E:
    ans = L"COMADMIN_E_COMP_MOVE_BAD_DEST";
    break;
  case 0x80110430:
    ans = L"COMADMIN_E_REGISTERTLB";
    break;
  case 0x80110433:
    ans = L"COMADMIN_E_SYSTEMAPP";
    break;
  case 0x80110434:
    ans = L"COMADMIN_E_COMPFILE_NOREGISTRAR";
    break;
  case 0x80110435:
    ans = L"COMADMIN_E_COREQCOMPINSTALLED";
    break;
  case 0x80110436:
    ans = L"COMADMIN_E_SERVICENOTINSTALLED";
    break;
  case 0x80110437:
    ans = L"COMADMIN_E_PROPERTYSAVEFAILED";
    break;
  case 0x80110438:
    ans = L"COMADMIN_E_OBJECTEXISTS";
    break;
  case 0x80110439:
    ans = L"COMADMIN_E_COMPONENTEXISTS";
    break;
  case 0x8011043B:
    ans = L"COMADMIN_E_REGFILE_CORRUPT";
    break;
  case 0x8011043C:
    ans = L"COMADMIN_E_PROPERTY_OVERFLOW";
    break;
  case 0x8011043E:
    ans = L"COMADMIN_E_NOTINREGISTRY";
    break;
  case 0x8011043F:
    ans = L"COMADMIN_E_OBJECTNOTPOOLABLE";
    break;
  case 0x80110446:
    ans = L"COMADMIN_E_APPLID_MATCHES_CLSID";
    break;
  case 0x80110447:
    ans = L"COMADMIN_E_ROLE_DOES_NOT_EXIST";
    break;
  case 0x80110448:
    ans = L"COMADMIN_E_START_APP_NEEDS_COMPONENTS";
    break;
  case 0x80110449:
    ans = L"COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM";
    break;
  case 0x8011044A:
    ans = L"COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY";
    break;
  case 0x8011044B:
    ans = L"COMADMIN_E_CAN_NOT_START_APP";
    break;
  case 0x8011044C:
    ans = L"COMADMIN_E_CAN_NOT_EXPORT_SYS_APP";
    break;
  case 0x8011044D:
    ans = L"COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT";
    break;
  case 0x8011044E:
    ans = L"COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER";
    break;
  case 0x8011044F:
    ans = L"COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE";
    break;
  case 0x80110450:
    ans = L"COMADMIN_E_BASE_PARTITION_ONLY";
    break;
  case 0x80110451:
    ans = L"COMADMIN_E_START_APP_DISABLED";
    break;
  case 0x80110457:
    ans = L"COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME";
    break;
  case 0x80110458:
    ans = L"COMADMIN_E_CAT_INVALID_PARTITION_NAME";
    break;
  case 0x80110459:
    ans = L"COMADMIN_E_CAT_PARTITION_IN_USE";
    break;
  case 0x8011045A:
    ans = L"COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES";
    break;
  case 0x8011045B:
    ans = L"COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED";
    break;
  case 0x8011045C:
    ans = L"COMADMIN_E_AMBIGUOUS_APPLICATION_NAME";
    break;
  case 0x8011045D:
    ans = L"COMADMIN_E_AMBIGUOUS_PARTITION_NAME";
    break;
  case 0x80110472:
    ans = L"COMADMIN_E_REGDB_NOTINITIALIZED";
    break;
  case 0x80110473:
    ans = L"COMADMIN_E_REGDB_NOTOPEN";
    break;
  case 0x80110474:
    ans = L"COMADMIN_E_REGDB_SYSTEMERR";
    break;
  case 0x80110475:
    ans = L"COMADMIN_E_REGDB_ALREADYRUNNING";
    break;
  case 0x80110480:
    ans = L"COMADMIN_E_MIG_VERSIONNOTSUPPORTED";
    break;
  case 0x80110481:
    ans = L"COMADMIN_E_MIG_SCHEMANOTFOUND";
    break;
  case 0x80110482:
    ans = L"COMADMIN_E_CAT_BITNESSMISMATCH";
    break;
  case 0x80110483:
    ans = L"COMADMIN_E_CAT_UNACCEPTABLEBITNESS";
    break;
  case 0x80110484:
    ans = L"COMADMIN_E_CAT_WRONGAPPBITNESS";
    break;
  case 0x80110485:
    ans = L"COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED";
    break;
  case 0x80110486:
    ans = L"COMADMIN_E_CAT_SERVERFAULT";
    break;
  case 0x80110600:
    ans = L"COMQC_E_APPLICATION_NOT_QUEUED";
    break;
  case 0x80110601:
    ans = L"COMQC_E_NO_QUEUEABLE_INTERFACES";
    break;
  case 0x80110602:
    ans = L"COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE";
    break;
  case 0x80110603:
    ans = L"COMQC_E_NO_IPERSISTSTREAM";
    break;
  case 0x80110604:
    ans = L"COMQC_E_BAD_MESSAGE";
    break;
  case 0x80110605:
    ans = L"COMQC_E_UNAUTHENTICATED";
    break;
  case 0x80110606:
    ans = L"COMQC_E_UNTRUSTED_ENQUEUER";
    break;
  case 0x80110701:
    ans = L"MSDTC_E_DUPLICATE_RESOURCE";
    break;
  case 0x80110808:
    ans = L"COMADMIN_E_OBJECT_PARENT_MISSING";
    break;
  case 0x80110809:
    ans = L"COMADMIN_E_OBJECT_DOES_NOT_EXIST";
    break;
  case 0x8011080A:
    ans = L"COMADMIN_E_APP_NOT_RUNNING";
    break;
  case 0x8011080B:
    ans = L"COMADMIN_E_INVALID_PARTITION";
    break;
  case 0x8011080D:
    ans = L"COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE";
    break;
  case 0x8011080E:
    ans = L"COMADMIN_E_USER_IN_SET";
    break;
  case 0x8011080F:
    ans = L"COMADMIN_E_CANTRECYCLELIBRARYAPPS";
    break;
  case 0x80110811:
    ans = L"COMADMIN_E_CANTRECYCLESERVICEAPPS";
    break;
  case 0x80110812:
    ans = L"COMADMIN_E_PROCESSALREADYRECYCLED";
    break;
  case 0x80110813:
    ans = L"COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED";
    break;
  case 0x80110814:
    ans = L"COMADMIN_E_CANTMAKEINPROCSERVICE";
    break;
  case 0x80110815:
    ans = L"COMADMIN_E_PROGIDINUSEBYCLSID";
    break;
  case 0x80110816:
    ans = L"COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET";
    break;
  case 0x80110817:
    ans = L"COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED";
    break;
  case 0x80110818:
    ans = L"COMADMIN_E_PARTITION_ACCESSDENIED";
    break;
  case 0x80110819:
    ans = L"COMADMIN_E_PARTITION_MSI_ONLY";
    break;
  case 0x8011081A:
    ans = L"COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT";
    break;
  case 0x8011081B:
    ans = L"COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS";
    break;
  case 0x8011081C:
    ans = L"COMADMIN_E_COMP_MOVE_SOURCE";
    break;
  case 0x8011081D:
    ans = L"COMADMIN_E_COMP_MOVE_DEST";
    break;
  case 0x8011081E:
    ans = L"COMADMIN_E_COMP_MOVE_PRIVATE";
    break;
  case 0x8011081F:
    ans = L"COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET";
    break;
  case 0x80110820:
    ans = L"COMADMIN_E_CANNOT_ALIAS_EVENTCLASS";
    break;
  case 0x80110821:
    ans = L"COMADMIN_E_PRIVATE_ACCESSDENIED";
    break;
  case 0x80110822:
    ans = L"COMADMIN_E_SAFERINVALID";
    break;
  case 0x80110823:
    ans = L"COMADMIN_E_REGISTRY_ACCESSDENIED";
    break;
  case 0x80110824:
    ans = L"COMADMIN_E_PARTITIONS_DISABLED";
    break;
  case 0x001B0000:
    ans = L"WER_S_REPORT_DEBUG";
    break;
  case 0x001B0001:
    ans = L"WER_S_REPORT_UPLOADED";
    break;
  case 0x001B0002:
    ans = L"WER_S_REPORT_QUEUED";
    break;
  case 0x001B0003:
    ans = L"WER_S_DISABLED";
    break;
  case 0x001B0004:
    ans = L"WER_S_SUSPENDED_UPLOAD";
    break;
  case 0x001B0005:
    ans = L"WER_S_DISABLED_QUEUE";
    break;
  case 0x001B0006:
    ans = L"WER_S_DISABLED_ARCHIVE";
    break;
  case 0x001B0007:
    ans = L"WER_S_REPORT_ASYNC";
    break;
  case 0x001B0008:
    ans = L"WER_S_IGNORE_ASSERT_INSTANCE";
    break;
  case 0x001B0009:
    ans = L"WER_S_IGNORE_ALL_ASSERTS";
    break;
  case 0x001B000A:
    ans = L"WER_S_ASSERT_CONTINUE";
    break;
  case 0x001B000B:
    ans = L"WER_S_THROTTLED";
    break;
  case 0x001B000C:
    ans = L"WER_S_REPORT_UPLOADED_CAB";
    break;
  case 0x801B8000:
    ans = L"WER_E_CRASH_FAILURE";
    break;
  case 0x801B8001:
    ans = L"WER_E_CANCELED";
    break;
  case 0x801B8002:
    ans = L"WER_E_NETWORK_FAILURE";
    break;
  case 0x801B8003:
    ans = L"WER_E_NOT_INITIALIZED";
    break;
  case 0x801B8004:
    ans = L"WER_E_ALREADY_REPORTING";
    break;
  case 0x801B8005:
    ans = L"WER_E_DUMP_THROTTLED";
    break;
  case 0x801B8006:
    ans = L"WER_E_INSUFFICIENT_CONSENT";
    break;
  case 0x801B8007:
    ans = L"WER_E_TOO_HEAVY";
    break;
  case 0x001F0001:
    ans = L"ERROR_FLT_IO_COMPLETE";
    break;
  case 0x801F0001:
    ans = L"ERROR_FLT_NO_HANDLER_DEFINED";
    break;
  case 0x801F0002:
    ans = L"ERROR_FLT_CONTEXT_ALREADY_DEFINED";
    break;
  case 0x801F0003:
    ans = L"ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST";
    break;
  case 0x801F0004:
    ans = L"ERROR_FLT_DISALLOW_FAST_IO";
    break;
  case 0x801F0005:
    ans = L"ERROR_FLT_INVALID_NAME_REQUEST";
    break;
  case 0x801F0006:
    ans = L"ERROR_FLT_NOT_SAFE_TO_POST_OPERATION";
    break;
  case 0x801F0007:
    ans = L"ERROR_FLT_NOT_INITIALIZED";
    break;
  case 0x801F0008:
    ans = L"ERROR_FLT_FILTER_NOT_READY";
    break;
  case 0x801F0009:
    ans = L"ERROR_FLT_POST_OPERATION_CLEANUP";
    break;
  case 0x801F000A:
    ans = L"ERROR_FLT_INTERNAL_ERROR";
    break;
  case 0x801F000B:
    ans = L"ERROR_FLT_DELETING_OBJECT";
    break;
  case 0x801F000C:
    ans = L"ERROR_FLT_MUST_BE_NONPAGED_POOL";
    break;
  case 0x801F000D:
    ans = L"ERROR_FLT_DUPLICATE_ENTRY";
    break;
  case 0x801F000E:
    ans = L"ERROR_FLT_CBDQ_DISABLED";
    break;
  case 0x801F000F:
    ans = L"ERROR_FLT_DO_NOT_ATTACH";
    break;
  case 0x801F0010:
    ans = L"ERROR_FLT_DO_NOT_DETACH";
    break;
  case 0x801F0011:
    ans = L"ERROR_FLT_INSTANCE_ALTITUDE_COLLISION";
    break;
  case 0x801F0012:
    ans = L"ERROR_FLT_INSTANCE_NAME_COLLISION";
    break;
  case 0x801F0013:
    ans = L"ERROR_FLT_FILTER_NOT_FOUND";
    break;
  case 0x801F0014:
    ans = L"ERROR_FLT_VOLUME_NOT_FOUND";
    break;
  case 0x801F0015:
    ans = L"ERROR_FLT_INSTANCE_NOT_FOUND";
    break;
  case 0x801F0016:
    ans = L"ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND";
    break;
  case 0x801F0017:
    ans = L"ERROR_FLT_INVALID_CONTEXT_REGISTRATION";
    break;
  case 0x801F0018:
    ans = L"ERROR_FLT_NAME_CACHE_MISS";
    break;
  case 0x801F0019:
    ans = L"ERROR_FLT_NO_DEVICE_OBJECT";
    break;
  case 0x801F001A:
    ans = L"ERROR_FLT_VOLUME_ALREADY_MOUNTED";
    break;
  case 0x801F001B:
    ans = L"ERROR_FLT_ALREADY_ENLISTED";
    break;
  case 0x801F001C:
    ans = L"ERROR_FLT_CONTEXT_ALREADY_LINKED";
    break;
  case 0x801F0020:
    ans = L"ERROR_FLT_NO_WAITER_FOR_REPLY";
    break;
  case 0x801F0023:
    ans = L"ERROR_FLT_REGISTRATION_BUSY";
    break;
  case 0x80260001:
    ans = L"ERROR_HUNG_DISPLAY_DRIVER_THREAD";
    break;
  case 0x80263001:
    ans = L"DWM_E_COMPOSITIONDISABLED";
    break;
  case 0x80263002:
    ans = L"DWM_E_REMOTING_NOT_SUPPORTED";
    break;
  case 0x80263003:
    ans = L"DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE";
    break;
  case 0x80263004:
    ans = L"DWM_E_NOT_QUEUING_PRESENTS";
    break;
  case 0x80263005:
    ans = L"DWM_E_ADAPTER_NOT_FOUND";
    break;
  case 0x00263005:
    ans = L"DWM_S_GDI_REDIRECTION_SURFACE";
    break;
  case 0x80263007:
    ans = L"DWM_E_TEXTURE_TOO_LARGE";
    break;
  case 0x00263008:
    ans = L"DWM_S_GDI_REDIRECTION_SURFACE_BLT_VIA_GDI";
    break;
  case 0x00261001:
    ans = L"ERROR_MONITOR_NO_DESCRIPTOR";
    break;
  case 0x00261002:
    ans = L"ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT";
    break;
  case 0xC0261003:
    ans = L"ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM";
    break;
  case 0xC0261004:
    ans = L"ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK";
    break;
  case 0xC0261005:
    ans = L"ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED";
    break;
  case 0xC0261006:
    ans = L"ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK";
    break;
  case 0xC0261007:
    ans = L"ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK";
    break;
  case 0xC0261008:
    ans = L"ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA";
    break;
  case 0xC0261009:
    ans = L"ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK";
    break;
  case 0xC026100A:
    ans = L"ERROR_MONITOR_INVALID_MANUFACTURE_DATE";
    break;
  case 0xC0262000:
    ans = L"ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER";
    break;
  case 0xC0262001:
    ans = L"ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER";
    break;
  case 0xC0262002:
    ans = L"ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER";
    break;
  case 0xC0262003:
    ans = L"ERROR_GRAPHICS_ADAPTER_WAS_RESET";
    break;
  case 0xC0262004:
    ans = L"ERROR_GRAPHICS_INVALID_DRIVER_MODEL";
    break;
  case 0xC0262005:
    ans = L"ERROR_GRAPHICS_PRESENT_MODE_CHANGED";
    break;
  case 0xC0262006:
    ans = L"ERROR_GRAPHICS_PRESENT_OCCLUDED";
    break;
  case 0xC0262007:
    ans = L"ERROR_GRAPHICS_PRESENT_DENIED";
    break;
  case 0xC0262008:
    ans = L"ERROR_GRAPHICS_CANNOTCOLORCONVERT";
    break;
  case 0xC0262009:
    ans = L"ERROR_GRAPHICS_DRIVER_MISMATCH";
    break;
  case 0x4026200A:
    ans = L"ERROR_GRAPHICS_PARTIAL_DATA_POPULATED";
    break;
  case 0xC026200B:
    ans = L"ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED";
    break;
  case 0xC026200C:
    ans = L"ERROR_GRAPHICS_PRESENT_UNOCCLUDED";
    break;
  case 0xC026200D:
    ans = L"ERROR_GRAPHICS_WINDOWDC_NOT_AVAILABLE";
    break;
  case 0xC026200E:
    ans = L"ERROR_GRAPHICS_WINDOWLESS_PRESENT_DISABLED";
    break;
  case 0xC026200F:
    ans = L"ERROR_GRAPHICS_PRESENT_INVALID_WINDOW";
    break;
  case 0xC0262010:
    ans = L"ERROR_GRAPHICS_PRESENT_BUFFER_NOT_BOUND";
    break;
  case 0xC0262011:
    ans = L"ERROR_GRAPHICS_VAIL_STATE_CHANGED";
    break;
  case 0xC0262100:
    ans = L"ERROR_GRAPHICS_NO_VIDEO_MEMORY";
    break;
  case 0xC0262101:
    ans = L"ERROR_GRAPHICS_CANT_LOCK_MEMORY";
    break;
  case 0xC0262102:
    ans = L"ERROR_GRAPHICS_ALLOCATION_BUSY";
    break;
  case 0xC0262103:
    ans = L"ERROR_GRAPHICS_TOO_MANY_REFERENCES";
    break;
  case 0xC0262104:
    ans = L"ERROR_GRAPHICS_TRY_AGAIN_LATER";
    break;
  case 0xC0262105:
    ans = L"ERROR_GRAPHICS_TRY_AGAIN_NOW";
    break;
  case 0xC0262106:
    ans = L"ERROR_GRAPHICS_ALLOCATION_INVALID";
    break;
  case 0xC0262107:
    ans = L"ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE";
    break;
  case 0xC0262108:
    ans = L"ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED";
    break;
  case 0xC0262109:
    ans = L"ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION";
    break;
  case 0xC0262110:
    ans = L"ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE";
    break;
  case 0xC0262111:
    ans = L"ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION";
    break;
  case 0xC0262112:
    ans = L"ERROR_GRAPHICS_ALLOCATION_CLOSED";
    break;
  case 0xC0262113:
    ans = L"ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE";
    break;
  case 0xC0262114:
    ans = L"ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE";
    break;
  case 0xC0262115:
    ans = L"ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE";
    break;
  case 0xC0262116:
    ans = L"ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST";
    break;
  case 0xC0262200:
    ans = L"ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE";
    break;
  case 0x40262201:
    ans = L"ERROR_GRAPHICS_SKIP_ALLOCATION_PREPARATION";
    break;
  case 0xC0262300:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY";
    break;
  case 0xC0262301:
    ans = L"ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED";
    break;
  case 0xC0262302:
    ans = L"ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED";
    break;
  case 0xC0262303:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN";
    break;
  case 0xC0262304:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE";
    break;
  case 0xC0262305:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET";
    break;
  case 0xC0262306:
    ans = L"ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED";
    break;
  case 0x00262307:
    ans = L"ERROR_GRAPHICS_MODE_NOT_PINNED";
    break;
  case 0xC0262308:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET";
    break;
  case 0xC0262309:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET";
    break;
  case 0xC026230A:
    ans = L"ERROR_GRAPHICS_INVALID_FREQUENCY";
    break;
  case 0xC026230B:
    ans = L"ERROR_GRAPHICS_INVALID_ACTIVE_REGION";
    break;
  case 0xC026230C:
    ans = L"ERROR_GRAPHICS_INVALID_TOTAL_REGION";
    break;
  case 0xC0262310:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE";
    break;
  case 0xC0262311:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE";
    break;
  case 0xC0262312:
    ans = L"ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET";
    break;
  case 0xC0262313:
    ans = L"ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY";
    break;
  case 0xC0262314:
    ans = L"ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET";
    break;
  case 0xC0262315:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET";
    break;
  case 0xC0262316:
    ans = L"ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET";
    break;
  case 0xC0262317:
    ans = L"ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET";
    break;
  case 0xC0262318:
    ans = L"ERROR_GRAPHICS_TARGET_ALREADY_IN_SET";
    break;
  case 0xC0262319:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH";
    break;
  case 0xC026231A:
    ans = L"ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY";
    break;
  case 0xC026231B:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET";
    break;
  case 0xC026231C:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE";
    break;
  case 0xC026231D:
    ans = L"ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET";
    break;
  case 0x0026231E:
    ans = L"ERROR_GRAPHICS_NO_PREFERRED_MODE";
    break;
  case 0xC026231F:
    ans = L"ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET";
    break;
  case 0xC0262320:
    ans = L"ERROR_GRAPHICS_STALE_MODESET";
    break;
  case 0xC0262321:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET";
    break;
  case 0xC0262322:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE";
    break;
  case 0xC0262323:
    ans = L"ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN";
    break;
  case 0xC0262324:
    ans = L"ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE";
    break;
  case 0xC0262325:
    ans = L"ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION";
    break;
  case 0xC0262326:
    ans = L"ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES";
    break;
  case 0xC0262327:
    ans = L"ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY";
    break;
  case 0xC0262328:
    ans = L"ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE";
    break;
  case 0xC0262329:
    ans = L"ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET";
    break;
  case 0xC026232A:
    ans = L"ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET";
    break;
  case 0xC026232B:
    ans = L"ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR";
    break;
  case 0xC026232C:
    ans = L"ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET";
    break;
  case 0xC026232D:
    ans = L"ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET";
    break;
  case 0xC026232E:
    ans = L"ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE";
    break;
  case 0xC026232F:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE";
    break;
  case 0xC0262330:
    ans = L"ERROR_GRAPHICS_RESOURCES_NOT_RELATED";
    break;
  case 0xC0262331:
    ans = L"ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE";
    break;
  case 0xC0262332:
    ans = L"ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE";
    break;
  case 0xC0262333:
    ans = L"ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET";
    break;
  case 0xC0262334:
    ans = L"ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER";
    break;
  case 0xC0262335:
    ans = L"ERROR_GRAPHICS_NO_VIDPNMGR";
    break;
  case 0xC0262336:
    ans = L"ERROR_GRAPHICS_NO_ACTIVE_VIDPN";
    break;
  case 0xC0262337:
    ans = L"ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY";
    break;
  case 0xC0262338:
    ans = L"ERROR_GRAPHICS_MONITOR_NOT_CONNECTED";
    break;
  case 0xC0262339:
    ans = L"ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY";
    break;
  case 0xC026233A:
    ans = L"ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE";
    break;
  case 0xC026233B:
    ans = L"ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE";
    break;
  case 0xC026233C:
    ans = L"ERROR_GRAPHICS_INVALID_STRIDE";
    break;
  case 0xC026233D:
    ans = L"ERROR_GRAPHICS_INVALID_PIXELFORMAT";
    break;
  case 0xC026233E:
    ans = L"ERROR_GRAPHICS_INVALID_COLORBASIS";
    break;
  case 0xC026233F:
    ans = L"ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE";
    break;
  case 0xC0262340:
    ans = L"ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY";
    break;
  case 0xC0262341:
    ans = L"ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT";
    break;
  case 0xC0262342:
    ans = L"ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
    break;
  case 0xC0262343:
    ans = L"ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN";
    break;
  case 0xC0262344:
    ans = L"ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL";
    break;
  case 0xC0262345:
    ans = L"ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION";
    break;
  case 0xC0262346:
    ans = L"ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED";
    break;
  case 0xC0262347:
    ans = L"ERROR_GRAPHICS_INVALID_GAMMA_RAMP";
    break;
  case 0xC0262348:
    ans = L"ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED";
    break;
  case 0xC0262349:
    ans = L"ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED";
    break;
  case 0xC026234A:
    ans = L"ERROR_GRAPHICS_MODE_NOT_IN_MODESET";
    break;
  case 0x0026234B:
    ans = L"ERROR_GRAPHICS_DATASET_IS_EMPTY";
    break;
  case 0x0026234C:
    ans = L"ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET";
    break;
  case 0xC026234D:
    ans = L"ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON";
    break;
  case 0xC026234E:
    ans = L"ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE";
    break;
  case 0xC026234F:
    ans = L"ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE";
    break;
  case 0xC0262350:
    ans = L"ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS";
    break;
  case 0x00262351:
    ans = L"ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED";
    break;
  case 0xC0262352:
    ans = L"ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING";
    break;
  case 0xC0262353:
    ans = L"ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED";
    break;
  case 0xC0262354:
    ans = L"ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS";
    break;
  case 0xC0262355:
    ans = L"ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT";
    break;
  case 0xC0262356:
    ans = L"ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM";
    break;
  case 0xC0262357:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN";
    break;
  case 0xC0262358:
    ans = L"ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT";
    break;
  case 0xC0262359:
    ans = L"ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED";
    break;
  case 0xC026235A:
    ans = L"ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION";
    break;
  case 0xC026235B:
    ans = L"ERROR_GRAPHICS_INVALID_CLIENT_TYPE";
    break;
  case 0xC026235C:
    ans = L"ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET";
    break;
  case 0xC0262400:
    ans = L"ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED";
    break;
  case 0xC0262401:
    ans = L"ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED";
    break;
  case 0x4026242F:
    ans = L"ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS";
    break;
  case 0xC0262430:
    ans = L"ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER";
    break;
  case 0xC0262431:
    ans = L"ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED";
    break;
  case 0xC0262432:
    ans = L"ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED";
    break;
  case 0xC0262433:
    ans = L"ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY";
    break;
  case 0xC0262434:
    ans = L"ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED";
    break;
  case 0xC0262435:
    ans = L"ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON";
    break;
  case 0xC0262436:
    ans = L"ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE";
    break;
  case 0x40262437:
    ans = L"ERROR_GRAPHICS_LEADLINK_START_DEFERRED";
    break;
  case 0xC0262438:
    ans = L"ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER";
    break;
  case 0x40262439:
    ans = L"ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY";
    break;
  case 0x4026243A:
    ans = L"ERROR_GRAPHICS_START_DEFERRED";
    break;
  case 0xC026243B:
    ans = L"ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED";
    break;
  case 0x4026243C:
    ans = L"ERROR_GRAPHICS_DEPENDABLE_CHILD_STATUS";
    break;
  case 0xC0262500:
    ans = L"ERROR_GRAPHICS_OPM_NOT_SUPPORTED";
    break;
  case 0xC0262501:
    ans = L"ERROR_GRAPHICS_COPP_NOT_SUPPORTED";
    break;
  case 0xC0262502:
    ans = L"ERROR_GRAPHICS_UAB_NOT_SUPPORTED";
    break;
  case 0xC0262503:
    ans = L"ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS";
    break;
  case 0xC0262505:
    ans = L"ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST";
    break;
  case 0xC026250B:
    ans = L"ERROR_GRAPHICS_OPM_INTERNAL_ERROR";
    break;
  case 0xC026250C:
    ans = L"ERROR_GRAPHICS_OPM_INVALID_HANDLE";
    break;
  case 0xC026250E:
    ans = L"ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH";
    break;
  case 0xC026250F:
    ans = L"ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED";
    break;
  case 0xC0262510:
    ans = L"ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED";
    break;
  case 0xC0262511:
    ans = L"ERROR_GRAPHICS_PVP_HFS_FAILED";
    break;
  case 0xC0262512:
    ans = L"ERROR_GRAPHICS_OPM_INVALID_SRM";
    break;
  case 0xC0262513:
    ans = L"ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP";
    break;
  case 0xC0262514:
    ans = L"ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP";
    break;
  case 0xC0262515:
    ans = L"ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA";
    break;
  case 0xC0262516:
    ans = L"ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET";
    break;
  case 0xC0262517:
    ans = L"ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH";
    break;
  case 0xC0262518:
    ans = L"ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE";
    break;
  case 0xC026251A:
    ans = L"ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS";
    break;
  case 0xC026251B:
    ans = L"ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS";
    break;
  case 0xC026251C:
    ans = L"ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS";
    break;
  case 0xC026251D:
    ans = L"ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST";
    break;
  case 0xC026251E:
    ans = L"ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR";
    break;
  case 0xC026251F:
    ans = L"ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS";
    break;
  case 0xC0262520:
    ans = L"ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED";
    break;
  case 0xC0262521:
    ans = L"ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST";
    break;
  case 0xC0262580:
    ans = L"ERROR_GRAPHICS_I2C_NOT_SUPPORTED";
    break;
  case 0xC0262581:
    ans = L"ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST";
    break;
  case 0xC0262582:
    ans = L"ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA";
    break;
  case 0xC0262583:
    ans = L"ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA";
    break;
  case 0xC0262584:
    ans = L"ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED";
    break;
  case 0xC0262585:
    ans = L"ERROR_GRAPHICS_DDCCI_INVALID_DATA";
    break;
  case 0xC0262586:
    ans = L"ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE";
    break;
  case 0xC0262587:
    ans = L"ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING";
    break;
  case 0xC0262588:
    ans = L"ERROR_GRAPHICS_MCA_INTERNAL_ERROR";
    break;
  case 0xC0262589:
    ans = L"ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND";
    break;
  case 0xC026258A:
    ans = L"ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH";
    break;
  case 0xC026258B:
    ans = L"ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM";
    break;
  case 0xC026258C:
    ans = L"ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE";
    break;
  case 0xC026258D:
    ans = L"ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS";
    break;
  case 0xC02625D8:
    ans = L"ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE";
    break;
  case 0xC02625D9:
    ans = L"ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION";
    break;
  case 0xC02625DA:
    ans = L"ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION";
    break;
  case 0xC02625DB:
    ans = L"ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH";
    break;
  case 0xC02625DC:
    ans = L"ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION";
    break;
  case 0xC02625DE:
    ans = L"ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED";
    break;
  case 0xC02625DF:
    ans = L"ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE";
    break;
  case 0xC02625E0:
    ans = L"ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED";
    break;
  case 0xC02625E1:
    ans = L"ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME";
    break;
  case 0xC02625E2:
    ans = L"ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP";
    break;
  case 0xC02625E3:
    ans = L"ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED";
    break;
  case 0xC02625E4:
    ans = L"ERROR_GRAPHICS_INVALID_POINTER";
    break;
  case 0xC02625E5:
    ans = L"ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE";
    break;
  case 0xC02625E6:
    ans = L"ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL";
    break;
  case 0xC02625E7:
    ans = L"ERROR_GRAPHICS_INTERNAL_ERROR";
    break;
  case 0xC02605E8:
    ans = L"ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS";
    break;
  case 0x80270001:
    ans = L"NAP_E_INVALID_PACKET";
    break;
  case 0x80270002:
    ans = L"NAP_E_MISSING_SOH";
    break;
  case 0x80270003:
    ans = L"NAP_E_CONFLICTING_ID";
    break;
  case 0x80270004:
    ans = L"NAP_E_NO_CACHED_SOH";
    break;
  case 0x80270005:
    ans = L"NAP_E_STILL_BOUND";
    break;
  case 0x80270006:
    ans = L"NAP_E_NOT_REGISTERED";
    break;
  case 0x80270007:
    ans = L"NAP_E_NOT_INITIALIZED";
    break;
  case 0x80270008:
    ans = L"NAP_E_MISMATCHED_ID";
    break;
  case 0x80270009:
    ans = L"NAP_E_NOT_PENDING";
    break;
  case 0x8027000A:
    ans = L"NAP_E_ID_NOT_FOUND";
    break;
  case 0x8027000B:
    ans = L"NAP_E_MAXSIZE_TOO_SMALL";
    break;
  case 0x8027000C:
    ans = L"NAP_E_SERVICE_NOT_RUNNING";
    break;
  case 0x0027000D:
    ans = L"NAP_S_CERT_ALREADY_PRESENT";
    break;
  case 0x8027000E:
    ans = L"NAP_E_ENTITY_DISABLED";
    break;
  case 0x8027000F:
    ans = L"NAP_E_NETSH_GROUPPOLICY_ERROR";
    break;
  case 0x80270010:
    ans = L"NAP_E_TOO_MANY_CALLS";
    break;
  case 0x80270011:
    ans = L"NAP_E_SHV_CONFIG_EXISTED";
    break;
  case 0x80270012:
    ans = L"NAP_E_SHV_CONFIG_NOT_FOUND";
    break;
  case 0x80270013:
    ans = L"NAP_E_SHV_TIMEOUT";
    break;
  case 0x80280000:
    ans = L"TPM_E_ERROR_MASK";
    break;
  case 0x80280001:
    ans = L"TPM_E_AUTHFAIL";
    break;
  case 0x80280002:
    ans = L"TPM_E_BADINDEX";
    break;
  case 0x80280003:
    ans = L"TPM_E_BAD_PARAMETER";
    break;
  case 0x80280004:
    ans = L"TPM_E_AUDITFAILURE";
    break;
  case 0x80280005:
    ans = L"TPM_E_CLEAR_DISABLED";
    break;
  case 0x80280006:
    ans = L"TPM_E_DEACTIVATED";
    break;
  case 0x80280007:
    ans = L"TPM_E_DISABLED";
    break;
  case 0x80280008:
    ans = L"TPM_E_DISABLED_CMD";
    break;
  case 0x80280009:
    ans = L"TPM_E_FAIL";
    break;
  case 0x8028000A:
    ans = L"TPM_E_BAD_ORDINAL";
    break;
  case 0x8028000B:
    ans = L"TPM_E_INSTALL_DISABLED";
    break;
  case 0x8028000C:
    ans = L"TPM_E_INVALID_KEYHANDLE";
    break;
  case 0x8028000D:
    ans = L"TPM_E_KEYNOTFOUND";
    break;
  case 0x8028000E:
    ans = L"TPM_E_INAPPROPRIATE_ENC";
    break;
  case 0x8028000F:
    ans = L"TPM_E_MIGRATEFAIL";
    break;
  case 0x80280010:
    ans = L"TPM_E_INVALID_PCR_INFO";
    break;
  case 0x80280011:
    ans = L"TPM_E_NOSPACE";
    break;
  case 0x80280012:
    ans = L"TPM_E_NOSRK";
    break;
  case 0x80280013:
    ans = L"TPM_E_NOTSEALED_BLOB";
    break;
  case 0x80280014:
    ans = L"TPM_E_OWNER_SET";
    break;
  case 0x80280015:
    ans = L"TPM_E_RESOURCES";
    break;
  case 0x80280016:
    ans = L"TPM_E_SHORTRANDOM";
    break;
  case 0x80280017:
    ans = L"TPM_E_SIZE";
    break;
  case 0x80280018:
    ans = L"TPM_E_WRONGPCRVAL";
    break;
  case 0x80280019:
    ans = L"TPM_E_BAD_PARAM_SIZE";
    break;
  case 0x8028001A:
    ans = L"TPM_E_SHA_THREAD";
    break;
  case 0x8028001B:
    ans = L"TPM_E_SHA_ERROR";
    break;
  case 0x8028001C:
    ans = L"TPM_E_FAILEDSELFTEST";
    break;
  case 0x8028001D:
    ans = L"TPM_E_AUTH2FAIL";
    break;
  case 0x8028001E:
    ans = L"TPM_E_BADTAG";
    break;
  case 0x8028001F:
    ans = L"TPM_E_IOERROR";
    break;
  case 0x80280020:
    ans = L"TPM_E_ENCRYPT_ERROR";
    break;
  case 0x80280021:
    ans = L"TPM_E_DECRYPT_ERROR";
    break;
  case 0x80280022:
    ans = L"TPM_E_INVALID_AUTHHANDLE";
    break;
  case 0x80280023:
    ans = L"TPM_E_NO_ENDORSEMENT";
    break;
  case 0x80280024:
    ans = L"TPM_E_INVALID_KEYUSAGE";
    break;
  case 0x80280025:
    ans = L"TPM_E_WRONG_ENTITYTYPE";
    break;
  case 0x80280026:
    ans = L"TPM_E_INVALID_POSTINIT";
    break;
  case 0x80280027:
    ans = L"TPM_E_INAPPROPRIATE_SIG";
    break;
  case 0x80280028:
    ans = L"TPM_E_BAD_KEY_PROPERTY";
    break;
  case 0x80280029:
    ans = L"TPM_E_BAD_MIGRATION";
    break;
  case 0x8028002A:
    ans = L"TPM_E_BAD_SCHEME";
    break;
  case 0x8028002B:
    ans = L"TPM_E_BAD_DATASIZE";
    break;
  case 0x8028002C:
    ans = L"TPM_E_BAD_MODE";
    break;
  case 0x8028002D:
    ans = L"TPM_E_BAD_PRESENCE";
    break;
  case 0x8028002E:
    ans = L"TPM_E_BAD_VERSION";
    break;
  case 0x8028002F:
    ans = L"TPM_E_NO_WRAP_TRANSPORT";
    break;
  case 0x80280030:
    ans = L"TPM_E_AUDITFAIL_UNSUCCESSFUL";
    break;
  case 0x80280031:
    ans = L"TPM_E_AUDITFAIL_SUCCESSFUL";
    break;
  case 0x80280032:
    ans = L"TPM_E_NOTRESETABLE";
    break;
  case 0x80280033:
    ans = L"TPM_E_NOTLOCAL";
    break;
  case 0x80280034:
    ans = L"TPM_E_BAD_TYPE";
    break;
  case 0x80280035:
    ans = L"TPM_E_INVALID_RESOURCE";
    break;
  case 0x80280036:
    ans = L"TPM_E_NOTFIPS";
    break;
  case 0x80280037:
    ans = L"TPM_E_INVALID_FAMILY";
    break;
  case 0x80280038:
    ans = L"TPM_E_NO_NV_PERMISSION";
    break;
  case 0x80280039:
    ans = L"TPM_E_REQUIRES_SIGN";
    break;
  case 0x8028003A:
    ans = L"TPM_E_KEY_NOTSUPPORTED";
    break;
  case 0x8028003B:
    ans = L"TPM_E_AUTH_CONFLICT";
    break;
  case 0x8028003C:
    ans = L"TPM_E_AREA_LOCKED";
    break;
  case 0x8028003D:
    ans = L"TPM_E_BAD_LOCALITY";
    break;
  case 0x8028003E:
    ans = L"TPM_E_READ_ONLY";
    break;
  case 0x8028003F:
    ans = L"TPM_E_PER_NOWRITE";
    break;
  case 0x80280040:
    ans = L"TPM_E_FAMILYCOUNT";
    break;
  case 0x80280041:
    ans = L"TPM_E_WRITE_LOCKED";
    break;
  case 0x80280042:
    ans = L"TPM_E_BAD_ATTRIBUTES";
    break;
  case 0x80280043:
    ans = L"TPM_E_INVALID_STRUCTURE";
    break;
  case 0x80280044:
    ans = L"TPM_E_KEY_OWNER_CONTROL";
    break;
  case 0x80280045:
    ans = L"TPM_E_BAD_COUNTER";
    break;
  case 0x80280046:
    ans = L"TPM_E_NOT_FULLWRITE";
    break;
  case 0x80280047:
    ans = L"TPM_E_CONTEXT_GAP";
    break;
  case 0x80280048:
    ans = L"TPM_E_MAXNVWRITES";
    break;
  case 0x80280049:
    ans = L"TPM_E_NOOPERATOR";
    break;
  case 0x8028004A:
    ans = L"TPM_E_RESOURCEMISSING";
    break;
  case 0x8028004B:
    ans = L"TPM_E_DELEGATE_LOCK";
    break;
  case 0x8028004C:
    ans = L"TPM_E_DELEGATE_FAMILY";
    break;
  case 0x8028004D:
    ans = L"TPM_E_DELEGATE_ADMIN";
    break;
  case 0x8028004E:
    ans = L"TPM_E_TRANSPORT_NOTEXCLUSIVE";
    break;
  case 0x8028004F:
    ans = L"TPM_E_OWNER_CONTROL";
    break;
  case 0x80280050:
    ans = L"TPM_E_DAA_RESOURCES";
    break;
  case 0x80280051:
    ans = L"TPM_E_DAA_INPUT_DATA0";
    break;
  case 0x80280052:
    ans = L"TPM_E_DAA_INPUT_DATA1";
    break;
  case 0x80280053:
    ans = L"TPM_E_DAA_ISSUER_SETTINGS";
    break;
  case 0x80280054:
    ans = L"TPM_E_DAA_TPM_SETTINGS";
    break;
  case 0x80280055:
    ans = L"TPM_E_DAA_STAGE";
    break;
  case 0x80280056:
    ans = L"TPM_E_DAA_ISSUER_VALIDITY";
    break;
  case 0x80280057:
    ans = L"TPM_E_DAA_WRONG_W";
    break;
  case 0x80280058:
    ans = L"TPM_E_BAD_HANDLE";
    break;
  case 0x80280059:
    ans = L"TPM_E_BAD_DELEGATE";
    break;
  case 0x8028005A:
    ans = L"TPM_E_BADCONTEXT";
    break;
  case 0x8028005B:
    ans = L"TPM_E_TOOMANYCONTEXTS";
    break;
  case 0x8028005C:
    ans = L"TPM_E_MA_TICKET_SIGNATURE";
    break;
  case 0x8028005D:
    ans = L"TPM_E_MA_DESTINATION";
    break;
  case 0x8028005E:
    ans = L"TPM_E_MA_SOURCE";
    break;
  case 0x8028005F:
    ans = L"TPM_E_MA_AUTHORITY";
    break;
  case 0x80280061:
    ans = L"TPM_E_PERMANENTEK";
    break;
  case 0x80280062:
    ans = L"TPM_E_BAD_SIGNATURE";
    break;
  case 0x80280063:
    ans = L"TPM_E_NOCONTEXTSPACE";
    break;
  case 0x80280081:
    ans = L"TPM_20_E_ASYMMETRIC";
    break;
  case 0x80280082:
    ans = L"TPM_20_E_ATTRIBUTES";
    break;
  case 0x80280083:
    ans = L"TPM_20_E_HASH";
    break;
  case 0x80280084:
    ans = L"TPM_20_E_VALUE";
    break;
  case 0x80280085:
    ans = L"TPM_20_E_HIERARCHY";
    break;
  case 0x80280087:
    ans = L"TPM_20_E_KEY_SIZE";
    break;
  case 0x80280088:
    ans = L"TPM_20_E_MGF";
    break;
  case 0x80280089:
    ans = L"TPM_20_E_MODE";
    break;
  case 0x8028008A:
    ans = L"TPM_20_E_TYPE";
    break;
  case 0x8028008B:
    ans = L"TPM_20_E_HANDLE";
    break;
  case 0x8028008C:
    ans = L"TPM_20_E_KDF";
    break;
  case 0x8028008D:
    ans = L"TPM_20_E_RANGE";
    break;
  case 0x8028008E:
    ans = L"TPM_20_E_AUTH_FAIL";
    break;
  case 0x8028008F:
    ans = L"TPM_20_E_NONCE";
    break;
  case 0x80280090:
    ans = L"TPM_20_E_PP";
    break;
  case 0x80280092:
    ans = L"TPM_20_E_SCHEME";
    break;
  case 0x80280095:
    ans = L"TPM_20_E_SIZE";
    break;
  case 0x80280096:
    ans = L"TPM_20_E_SYMMETRIC";
    break;
  case 0x80280097:
    ans = L"TPM_20_E_TAG";
    break;
  case 0x80280098:
    ans = L"TPM_20_E_SELECTOR";
    break;
  case 0x8028009A:
    ans = L"TPM_20_E_INSUFFICIENT";
    break;
  case 0x8028009B:
    ans = L"TPM_20_E_SIGNATURE";
    break;
  case 0x8028009C:
    ans = L"TPM_20_E_KEY";
    break;
  case 0x8028009D:
    ans = L"TPM_20_E_POLICY_FAIL";
    break;
  case 0x8028009F:
    ans = L"TPM_20_E_INTEGRITY";
    break;
  case 0x802800A0:
    ans = L"TPM_20_E_TICKET";
    break;
  case 0x802800A1:
    ans = L"TPM_20_E_RESERVED_BITS";
    break;
  case 0x802800A2:
    ans = L"TPM_20_E_BAD_AUTH";
    break;
  case 0x802800A3:
    ans = L"TPM_20_E_EXPIRED";
    break;
  case 0x802800A4:
    ans = L"TPM_20_E_POLICY_CC";
    break;
  case 0x802800A5:
    ans = L"TPM_20_E_BINDING";
    break;
  case 0x802800A6:
    ans = L"TPM_20_E_CURVE";
    break;
  case 0x802800A7:
    ans = L"TPM_20_E_ECC_POINT";
    break;
  case 0x80280100:
    ans = L"TPM_20_E_INITIALIZE";
    break;
  case 0x80280101:
    ans = L"TPM_20_E_FAILURE";
    break;
  case 0x80280103:
    ans = L"TPM_20_E_SEQUENCE";
    break;
  case 0x8028010B:
    ans = L"TPM_20_E_PRIVATE";
    break;
  case 0x80280119:
    ans = L"TPM_20_E_HMAC";
    break;
  case 0x80280120:
    ans = L"TPM_20_E_DISABLED";
    break;
  case 0x80280121:
    ans = L"TPM_20_E_EXCLUSIVE";
    break;
  case 0x80280123:
    ans = L"TPM_20_E_ECC_CURVE";
    break;
  case 0x80280124:
    ans = L"TPM_20_E_AUTH_TYPE";
    break;
  case 0x80280125:
    ans = L"TPM_20_E_AUTH_MISSING";
    break;
  case 0x80280126:
    ans = L"TPM_20_E_POLICY";
    break;
  case 0x80280127:
    ans = L"TPM_20_E_PCR";
    break;
  case 0x80280128:
    ans = L"TPM_20_E_PCR_CHANGED";
    break;
  case 0x8028012D:
    ans = L"TPM_20_E_UPGRADE";
    break;
  case 0x8028012E:
    ans = L"TPM_20_E_TOO_MANY_CONTEXTS";
    break;
  case 0x8028012F:
    ans = L"TPM_20_E_AUTH_UNAVAILABLE";
    break;
  case 0x80280130:
    ans = L"TPM_20_E_REBOOT";
    break;
  case 0x80280131:
    ans = L"TPM_20_E_UNBALANCED";
    break;
  case 0x80280142:
    ans = L"TPM_20_E_COMMAND_SIZE";
    break;
  case 0x80280143:
    ans = L"TPM_20_E_COMMAND_CODE";
    break;
  case 0x80280144:
    ans = L"TPM_20_E_AUTHSIZE";
    break;
  case 0x80280145:
    ans = L"TPM_20_E_AUTH_CONTEXT";
    break;
  case 0x80280146:
    ans = L"TPM_20_E_NV_RANGE";
    break;
  case 0x80280147:
    ans = L"TPM_20_E_NV_SIZE";
    break;
  case 0x80280148:
    ans = L"TPM_20_E_NV_LOCKED";
    break;
  case 0x80280149:
    ans = L"TPM_20_E_NV_AUTHORIZATION";
    break;
  case 0x8028014A:
    ans = L"TPM_20_E_NV_UNINITIALIZED";
    break;
  case 0x8028014B:
    ans = L"TPM_20_E_NV_SPACE";
    break;
  case 0x8028014C:
    ans = L"TPM_20_E_NV_DEFINED";
    break;
  case 0x80280150:
    ans = L"TPM_20_E_BAD_CONTEXT";
    break;
  case 0x80280151:
    ans = L"TPM_20_E_CPHASH";
    break;
  case 0x80280152:
    ans = L"TPM_20_E_PARENT";
    break;
  case 0x80280153:
    ans = L"TPM_20_E_NEEDS_TEST";
    break;
  case 0x80280154:
    ans = L"TPM_20_E_NO_RESULT";
    break;
  case 0x80280155:
    ans = L"TPM_20_E_SENSITIVE";
    break;
  case 0x80280400:
    ans = L"TPM_E_COMMAND_BLOCKED";
    break;
  case 0x80280401:
    ans = L"TPM_E_INVALID_HANDLE";
    break;
  case 0x80280402:
    ans = L"TPM_E_DUPLICATE_VHANDLE";
    break;
  case 0x80280403:
    ans = L"TPM_E_EMBEDDED_COMMAND_BLOCKED";
    break;
  case 0x80280404:
    ans = L"TPM_E_EMBEDDED_COMMAND_UNSUPPORTED";
    break;
  case 0x80280800:
    ans = L"TPM_E_RETRY";
    break;
  case 0x80280801:
    ans = L"TPM_E_NEEDS_SELFTEST";
    break;
  case 0x80280802:
    ans = L"TPM_E_DOING_SELFTEST";
    break;
  case 0x80280803:
    ans = L"TPM_E_DEFEND_LOCK_RUNNING";
    break;
  case 0x80280901:
    ans = L"TPM_20_E_CONTEXT_GAP";
    break;
  case 0x80280902:
    ans = L"TPM_20_E_OBJECT_MEMORY";
    break;
  case 0x80280903:
    ans = L"TPM_20_E_SESSION_MEMORY";
    break;
  case 0x80280904:
    ans = L"TPM_20_E_MEMORY";
    break;
  case 0x80280905:
    ans = L"TPM_20_E_SESSION_HANDLES";
    break;
  case 0x80280906:
    ans = L"TPM_20_E_OBJECT_HANDLES";
    break;
  case 0x80280907:
    ans = L"TPM_20_E_LOCALITY";
    break;
  case 0x80280908:
    ans = L"TPM_20_E_YIELDED";
    break;
  case 0x80280909:
    ans = L"TPM_20_E_CANCELED";
    break;
  case 0x8028090A:
    ans = L"TPM_20_E_TESTING";
    break;
  case 0x80280920:
    ans = L"TPM_20_E_NV_RATE";
    break;
  case 0x80280921:
    ans = L"TPM_20_E_LOCKOUT";
    break;
  case 0x80280922:
    ans = L"TPM_20_E_RETRY";
    break;
  case 0x80280923:
    ans = L"TPM_20_E_NV_UNAVAILABLE";
    break;
  case 0x80284001:
    ans = L"TBS_E_INTERNAL_ERROR";
    break;
  case 0x80284002:
    ans = L"TBS_E_BAD_PARAMETER";
    break;
  case 0x80284003:
    ans = L"TBS_E_INVALID_OUTPUT_POINTER";
    break;
  case 0x80284004:
    ans = L"TBS_E_INVALID_CONTEXT";
    break;
  case 0x80284005:
    ans = L"TBS_E_INSUFFICIENT_BUFFER";
    break;
  case 0x80284006:
    ans = L"TBS_E_IOERROR";
    break;
  case 0x80284007:
    ans = L"TBS_E_INVALID_CONTEXT_PARAM";
    break;
  case 0x80284008:
    ans = L"TBS_E_SERVICE_NOT_RUNNING";
    break;
  case 0x80284009:
    ans = L"TBS_E_TOO_MANY_TBS_CONTEXTS";
    break;
  case 0x8028400A:
    ans = L"TBS_E_TOO_MANY_RESOURCES";
    break;
  case 0x8028400B:
    ans = L"TBS_E_SERVICE_START_PENDING";
    break;
  case 0x8028400C:
    ans = L"TBS_E_PPI_NOT_SUPPORTED";
    break;
  case 0x8028400D:
    ans = L"TBS_E_COMMAND_CANCELED";
    break;
  case 0x8028400E:
    ans = L"TBS_E_BUFFER_TOO_LARGE";
    break;
  case 0x8028400F:
    ans = L"TBS_E_TPM_NOT_FOUND";
    break;
  case 0x80284010:
    ans = L"TBS_E_SERVICE_DISABLED";
    break;
  case 0x80284011:
    ans = L"TBS_E_NO_EVENT_LOG";
    break;
  case 0x80284012:
    ans = L"TBS_E_ACCESS_DENIED";
    break;
  case 0x80284013:
    ans = L"TBS_E_PROVISIONING_NOT_ALLOWED";
    break;
  case 0x80284014:
    ans = L"TBS_E_PPI_FUNCTION_UNSUPPORTED";
    break;
  case 0x80284015:
    ans = L"TBS_E_OWNERAUTH_NOT_FOUND";
    break;
  case 0x80284016:
    ans = L"TBS_E_PROVISIONING_INCOMPLETE";
    break;
  case 0x80290100:
    ans = L"TPMAPI_E_INVALID_STATE";
    break;
  case 0x80290101:
    ans = L"TPMAPI_E_NOT_ENOUGH_DATA";
    break;
  case 0x80290102:
    ans = L"TPMAPI_E_TOO_MUCH_DATA";
    break;
  case 0x80290103:
    ans = L"TPMAPI_E_INVALID_OUTPUT_POINTER";
    break;
  case 0x80290104:
    ans = L"TPMAPI_E_INVALID_PARAMETER";
    break;
  case 0x80290105:
    ans = L"TPMAPI_E_OUT_OF_MEMORY";
    break;
  case 0x80290106:
    ans = L"TPMAPI_E_BUFFER_TOO_SMALL";
    break;
  case 0x80290107:
    ans = L"TPMAPI_E_INTERNAL_ERROR";
    break;
  case 0x80290108:
    ans = L"TPMAPI_E_ACCESS_DENIED";
    break;
  case 0x80290109:
    ans = L"TPMAPI_E_AUTHORIZATION_FAILED";
    break;
  case 0x8029010A:
    ans = L"TPMAPI_E_INVALID_CONTEXT_HANDLE";
    break;
  case 0x8029010B:
    ans = L"TPMAPI_E_TBS_COMMUNICATION_ERROR";
    break;
  case 0x8029010C:
    ans = L"TPMAPI_E_TPM_COMMAND_ERROR";
    break;
  case 0x8029010D:
    ans = L"TPMAPI_E_MESSAGE_TOO_LARGE";
    break;
  case 0x8029010E:
    ans = L"TPMAPI_E_INVALID_ENCODING";
    break;
  case 0x8029010F:
    ans = L"TPMAPI_E_INVALID_KEY_SIZE";
    break;
  case 0x80290110:
    ans = L"TPMAPI_E_ENCRYPTION_FAILED";
    break;
  case 0x80290111:
    ans = L"TPMAPI_E_INVALID_KEY_PARAMS";
    break;
  case 0x80290112:
    ans = L"TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB";
    break;
  case 0x80290113:
    ans = L"TPMAPI_E_INVALID_PCR_INDEX";
    break;
  case 0x80290114:
    ans = L"TPMAPI_E_INVALID_DELEGATE_BLOB";
    break;
  case 0x80290115:
    ans = L"TPMAPI_E_INVALID_CONTEXT_PARAMS";
    break;
  case 0x80290116:
    ans = L"TPMAPI_E_INVALID_KEY_BLOB";
    break;
  case 0x80290117:
    ans = L"TPMAPI_E_INVALID_PCR_DATA";
    break;
  case 0x80290118:
    ans = L"TPMAPI_E_INVALID_OWNER_AUTH";
    break;
  case 0x80290119:
    ans = L"TPMAPI_E_FIPS_RNG_CHECK_FAILED";
    break;
  case 0x8029011A:
    ans = L"TPMAPI_E_EMPTY_TCG_LOG";
    break;
  case 0x8029011B:
    ans = L"TPMAPI_E_INVALID_TCG_LOG_ENTRY";
    break;
  case 0x8029011C:
    ans = L"TPMAPI_E_TCG_SEPARATOR_ABSENT";
    break;
  case 0x8029011D:
    ans = L"TPMAPI_E_TCG_INVALID_DIGEST_ENTRY";
    break;
  case 0x8029011E:
    ans = L"TPMAPI_E_POLICY_DENIES_OPERATION";
    break;
  case 0x8029011F:
    ans = L"TPMAPI_E_NV_BITS_NOT_DEFINED";
    break;
  case 0x80290120:
    ans = L"TPMAPI_E_NV_BITS_NOT_READY";
    break;
  case 0x80290121:
    ans = L"TPMAPI_E_SEALING_KEY_NOT_AVAILABLE";
    break;
  case 0x80290122:
    ans = L"TPMAPI_E_NO_AUTHORIZATION_CHAIN_FOUND";
    break;
  case 0x80290123:
    ans = L"TPMAPI_E_SVN_COUNTER_NOT_AVAILABLE";
    break;
  case 0x80290124:
    ans = L"TPMAPI_E_OWNER_AUTH_NOT_NULL";
    break;
  case 0x80290125:
    ans = L"TPMAPI_E_ENDORSEMENT_AUTH_NOT_NULL";
    break;
  case 0x80290126:
    ans = L"TPMAPI_E_AUTHORIZATION_REVOKED";
    break;
  case 0x80290127:
    ans = L"TPMAPI_E_MALFORMED_AUTHORIZATION_KEY";
    break;
  case 0x80290128:
    ans = L"TPMAPI_E_AUTHORIZING_KEY_NOT_SUPPORTED";
    break;
  case 0x80290129:
    ans = L"TPMAPI_E_INVALID_AUTHORIZATION_SIGNATURE";
    break;
  case 0x8029012A:
    ans = L"TPMAPI_E_MALFORMED_AUTHORIZATION_POLICY";
    break;
  case 0x8029012B:
    ans = L"TPMAPI_E_MALFORMED_AUTHORIZATION_OTHER";
    break;
  case 0x8029012C:
    ans = L"TPMAPI_E_SEALING_KEY_CHANGED";
    break;
  case 0x80290200:
    ans = L"TBSIMP_E_BUFFER_TOO_SMALL";
    break;
  case 0x80290201:
    ans = L"TBSIMP_E_CLEANUP_FAILED";
    break;
  case 0x80290202:
    ans = L"TBSIMP_E_INVALID_CONTEXT_HANDLE";
    break;
  case 0x80290203:
    ans = L"TBSIMP_E_INVALID_CONTEXT_PARAM";
    break;
  case 0x80290204:
    ans = L"TBSIMP_E_TPM_ERROR";
    break;
  case 0x80290205:
    ans = L"TBSIMP_E_HASH_BAD_KEY";
    break;
  case 0x80290206:
    ans = L"TBSIMP_E_DUPLICATE_VHANDLE";
    break;
  case 0x80290207:
    ans = L"TBSIMP_E_INVALID_OUTPUT_POINTER";
    break;
  case 0x80290208:
    ans = L"TBSIMP_E_INVALID_PARAMETER";
    break;
  case 0x80290209:
    ans = L"TBSIMP_E_RPC_INIT_FAILED";
    break;
  case 0x8029020A:
    ans = L"TBSIMP_E_SCHEDULER_NOT_RUNNING";
    break;
  case 0x8029020B:
    ans = L"TBSIMP_E_COMMAND_CANCELED";
    break;
  case 0x8029020C:
    ans = L"TBSIMP_E_OUT_OF_MEMORY";
    break;
  case 0x8029020D:
    ans = L"TBSIMP_E_LIST_NO_MORE_ITEMS";
    break;
  case 0x8029020E:
    ans = L"TBSIMP_E_LIST_NOT_FOUND";
    break;
  case 0x8029020F:
    ans = L"TBSIMP_E_NOT_ENOUGH_SPACE";
    break;
  case 0x80290210:
    ans = L"TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS";
    break;
  case 0x80290211:
    ans = L"TBSIMP_E_COMMAND_FAILED";
    break;
  case 0x80290212:
    ans = L"TBSIMP_E_UNKNOWN_ORDINAL";
    break;
  case 0x80290213:
    ans = L"TBSIMP_E_RESOURCE_EXPIRED";
    break;
  case 0x80290214:
    ans = L"TBSIMP_E_INVALID_RESOURCE";
    break;
  case 0x80290215:
    ans = L"TBSIMP_E_NOTHING_TO_UNLOAD";
    break;
  case 0x80290216:
    ans = L"TBSIMP_E_HASH_TABLE_FULL";
    break;
  case 0x80290217:
    ans = L"TBSIMP_E_TOO_MANY_TBS_CONTEXTS";
    break;
  case 0x80290218:
    ans = L"TBSIMP_E_TOO_MANY_RESOURCES";
    break;
  case 0x80290219:
    ans = L"TBSIMP_E_PPI_NOT_SUPPORTED";
    break;
  case 0x8029021A:
    ans = L"TBSIMP_E_TPM_INCOMPATIBLE";
    break;
  case 0x8029021B:
    ans = L"TBSIMP_E_NO_EVENT_LOG";
    break;
  case 0x80290300:
    ans = L"TPM_E_PPI_ACPI_FAILURE";
    break;
  case 0x80290301:
    ans = L"TPM_E_PPI_USER_ABORT";
    break;
  case 0x80290302:
    ans = L"TPM_E_PPI_BIOS_FAILURE";
    break;
  case 0x80290303:
    ans = L"TPM_E_PPI_NOT_SUPPORTED";
    break;
  case 0x80290304:
    ans = L"TPM_E_PPI_BLOCKED_IN_BIOS";
    break;
  case 0x80290400:
    ans = L"TPM_E_PCP_ERROR_MASK";
    break;
  case 0x80290401:
    ans = L"TPM_E_PCP_DEVICE_NOT_READY";
    break;
  case 0x80290402:
    ans = L"TPM_E_PCP_INVALID_HANDLE";
    break;
  case 0x80290403:
    ans = L"TPM_E_PCP_INVALID_PARAMETER";
    break;
  case 0x80290404:
    ans = L"TPM_E_PCP_FLAG_NOT_SUPPORTED";
    break;
  case 0x80290405:
    ans = L"TPM_E_PCP_NOT_SUPPORTED";
    break;
  case 0x80290406:
    ans = L"TPM_E_PCP_BUFFER_TOO_SMALL";
    break;
  case 0x80290407:
    ans = L"TPM_E_PCP_INTERNAL_ERROR";
    break;
  case 0x80290408:
    ans = L"TPM_E_PCP_AUTHENTICATION_FAILED";
    break;
  case 0x80290409:
    ans = L"TPM_E_PCP_AUTHENTICATION_IGNORED";
    break;
  case 0x8029040A:
    ans = L"TPM_E_PCP_POLICY_NOT_FOUND";
    break;
  case 0x8029040B:
    ans = L"TPM_E_PCP_PROFILE_NOT_FOUND";
    break;
  case 0x8029040C:
    ans = L"TPM_E_PCP_VALIDATION_FAILED";
    break;
  case 0x8029040E:
    ans = L"TPM_E_PCP_WRONG_PARENT";
    break;
  case 0x8029040F:
    ans = L"TPM_E_KEY_NOT_LOADED";
    break;
  case 0x80290410:
    ans = L"TPM_E_NO_KEY_CERTIFICATION";
    break;
  case 0x80290411:
    ans = L"TPM_E_KEY_NOT_FINALIZED";
    break;
  case 0x80290412:
    ans = L"TPM_E_ATTESTATION_CHALLENGE_NOT_SET";
    break;
  case 0x80290413:
    ans = L"TPM_E_NOT_PCR_BOUND";
    break;
  case 0x80290414:
    ans = L"TPM_E_KEY_ALREADY_FINALIZED";
    break;
  case 0x80290415:
    ans = L"TPM_E_KEY_USAGE_POLICY_NOT_SUPPORTED";
    break;
  case 0x80290416:
    ans = L"TPM_E_KEY_USAGE_POLICY_INVALID";
    break;
  case 0x80290417:
    ans = L"TPM_E_SOFT_KEY_ERROR";
    break;
  case 0x80290418:
    ans = L"TPM_E_KEY_NOT_AUTHENTICATED";
    break;
  case 0x80290419:
    ans = L"TPM_E_PCP_KEY_NOT_AIK";
    break;
  case 0x8029041A:
    ans = L"TPM_E_KEY_NOT_SIGNING_KEY";
    break;
  case 0x8029041B:
    ans = L"TPM_E_LOCKED_OUT";
    break;
  case 0x8029041C:
    ans = L"TPM_E_CLAIM_TYPE_NOT_SUPPORTED";
    break;
  case 0x8029041D:
    ans = L"TPM_E_VERSION_NOT_SUPPORTED";
    break;
  case 0x8029041E:
    ans = L"TPM_E_BUFFER_LENGTH_MISMATCH";
    break;
  case 0x8029041F:
    ans = L"TPM_E_PCP_IFX_RSA_KEY_CREATION_BLOCKED";
    break;
  case 0x80290420:
    ans = L"TPM_E_PCP_TICKET_MISSING";
    break;
  case 0x80290421:
    ans = L"TPM_E_PCP_RAW_POLICY_NOT_SUPPORTED";
    break;
  case 0x80290422:
    ans = L"TPM_E_PCP_KEY_HANDLE_INVALIDATED";
    break;
  case 0x40290423:
    ans = L"TPM_E_PCP_UNSUPPORTED_PSS_SALT";
    break;
  case 0x80290500:
    ans = L"TPM_E_ZERO_EXHAUST_ENABLED";
    break;
  case 0x80300002:
    ans = L"PLA_E_DCS_NOT_FOUND";
    break;
  case 0x803000AA:
    ans = L"PLA_E_DCS_IN_USE";
    break;
  case 0x80300045:
    ans = L"PLA_E_TOO_MANY_FOLDERS";
    break;
  case 0x80300070:
    ans = L"PLA_E_NO_MIN_DISK";
    break;
  case 0x803000B7:
    ans = L"PLA_E_DCS_ALREADY_EXISTS";
    break;
  case 0x00300100:
    ans = L"PLA_S_PROPERTY_IGNORED";
    break;
  case 0x80300101:
    ans = L"PLA_E_PROPERTY_CONFLICT";
    break;
  case 0x80300102:
    ans = L"PLA_E_DCS_SINGLETON_REQUIRED";
    break;
  case 0x80300103:
    ans = L"PLA_E_CREDENTIALS_REQUIRED";
    break;
  case 0x80300104:
    ans = L"PLA_E_DCS_NOT_RUNNING";
    break;
  case 0x80300105:
    ans = L"PLA_E_CONFLICT_INCL_EXCL_API";
    break;
  case 0x80300106:
    ans = L"PLA_E_NETWORK_EXE_NOT_VALID";
    break;
  case 0x80300107:
    ans = L"PLA_E_EXE_ALREADY_CONFIGURED";
    break;
  case 0x80300108:
    ans = L"PLA_E_EXE_PATH_NOT_VALID";
    break;
  case 0x80300109:
    ans = L"PLA_E_DC_ALREADY_EXISTS";
    break;
  case 0x8030010A:
    ans = L"PLA_E_DCS_START_WAIT_TIMEOUT";
    break;
  case 0x8030010B:
    ans = L"PLA_E_DC_START_WAIT_TIMEOUT";
    break;
  case 0x8030010C:
    ans = L"PLA_E_REPORT_WAIT_TIMEOUT";
    break;
  case 0x8030010D:
    ans = L"PLA_E_NO_DUPLICATES";
    break;
  case 0x8030010E:
    ans = L"PLA_E_EXE_FULL_PATH_REQUIRED";
    break;
  case 0x8030010F:
    ans = L"PLA_E_INVALID_SESSION_NAME";
    break;
  case 0x80300110:
    ans = L"PLA_E_PLA_CHANNEL_NOT_ENABLED";
    break;
  case 0x80300111:
    ans = L"PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED";
    break;
  case 0x80300112:
    ans = L"PLA_E_RULES_MANAGER_FAILED";
    break;
  case 0x80300113:
    ans = L"PLA_E_CABAPI_FAILURE";
    break;
  case 0x80310000:
    ans = L"FVE_E_LOCKED_VOLUME";
    break;
  case 0x80310001:
    ans = L"FVE_E_NOT_ENCRYPTED";
    break;
  case 0x80310002:
    ans = L"FVE_E_NO_TPM_BIOS";
    break;
  case 0x80310003:
    ans = L"FVE_E_NO_MBR_METRIC";
    break;
  case 0x80310004:
    ans = L"FVE_E_NO_BOOTSECTOR_METRIC";
    break;
  case 0x80310005:
    ans = L"FVE_E_NO_BOOTMGR_METRIC";
    break;
  case 0x80310006:
    ans = L"FVE_E_WRONG_BOOTMGR";
    break;
  case 0x80310007:
    ans = L"FVE_E_SECURE_KEY_REQUIRED";
    break;
  case 0x80310008:
    ans = L"FVE_E_NOT_ACTIVATED";
    break;
  case 0x80310009:
    ans = L"FVE_E_ACTION_NOT_ALLOWED";
    break;
  case 0x8031000A:
    ans = L"FVE_E_AD_SCHEMA_NOT_INSTALLED";
    break;
  case 0x8031000B:
    ans = L"FVE_E_AD_INVALID_DATATYPE";
    break;
  case 0x8031000C:
    ans = L"FVE_E_AD_INVALID_DATASIZE";
    break;
  case 0x8031000D:
    ans = L"FVE_E_AD_NO_VALUES";
    break;
  case 0x8031000E:
    ans = L"FVE_E_AD_ATTR_NOT_SET";
    break;
  case 0x8031000F:
    ans = L"FVE_E_AD_GUID_NOT_FOUND";
    break;
  case 0x80310010:
    ans = L"FVE_E_BAD_INFORMATION";
    break;
  case 0x80310011:
    ans = L"FVE_E_TOO_SMALL";
    break;
  case 0x80310012:
    ans = L"FVE_E_SYSTEM_VOLUME";
    break;
  case 0x80310013:
    ans = L"FVE_E_FAILED_WRONG_FS";
    break;
  case 0x80310014:
    ans = L"FVE_E_BAD_PARTITION_SIZE";
    break;
  case 0x80310015:
    ans = L"FVE_E_NOT_SUPPORTED";
    break;
  case 0x80310016:
    ans = L"FVE_E_BAD_DATA";
    break;
  case 0x80310017:
    ans = L"FVE_E_VOLUME_NOT_BOUND";
    break;
  case 0x80310018:
    ans = L"FVE_E_TPM_NOT_OWNED";
    break;
  case 0x80310019:
    ans = L"FVE_E_NOT_DATA_VOLUME";
    break;
  case 0x8031001A:
    ans = L"FVE_E_AD_INSUFFICIENT_BUFFER";
    break;
  case 0x8031001B:
    ans = L"FVE_E_CONV_READ";
    break;
  case 0x8031001C:
    ans = L"FVE_E_CONV_WRITE";
    break;
  case 0x8031001D:
    ans = L"FVE_E_KEY_REQUIRED";
    break;
  case 0x8031001E:
    ans = L"FVE_E_CLUSTERING_NOT_SUPPORTED";
    break;
  case 0x8031001F:
    ans = L"FVE_E_VOLUME_BOUND_ALREADY";
    break;
  case 0x80310020:
    ans = L"FVE_E_OS_NOT_PROTECTED";
    break;
  case 0x80310021:
    ans = L"FVE_E_PROTECTION_DISABLED";
    break;
  case 0x80310022:
    ans = L"FVE_E_RECOVERY_KEY_REQUIRED";
    break;
  case 0x80310023:
    ans = L"FVE_E_FOREIGN_VOLUME";
    break;
  case 0x80310024:
    ans = L"FVE_E_OVERLAPPED_UPDATE";
    break;
  case 0x80310025:
    ans = L"FVE_E_TPM_SRK_AUTH_NOT_ZERO";
    break;
  case 0x80310026:
    ans = L"FVE_E_FAILED_SECTOR_SIZE";
    break;
  case 0x80310027:
    ans = L"FVE_E_FAILED_AUTHENTICATION";
    break;
  case 0x80310028:
    ans = L"FVE_E_NOT_OS_VOLUME";
    break;
  case 0x80310029:
    ans = L"FVE_E_AUTOUNLOCK_ENABLED";
    break;
  case 0x8031002A:
    ans = L"FVE_E_WRONG_BOOTSECTOR";
    break;
  case 0x8031002B:
    ans = L"FVE_E_WRONG_SYSTEM_FS";
    break;
  case 0x8031002C:
    ans = L"FVE_E_POLICY_PASSWORD_REQUIRED";
    break;
  case 0x8031002D:
    ans = L"FVE_E_CANNOT_SET_FVEK_ENCRYPTED";
    break;
  case 0x8031002E:
    ans = L"FVE_E_CANNOT_ENCRYPT_NO_KEY";
    break;
  case 0x80310030:
    ans = L"FVE_E_BOOTABLE_CDDVD";
    break;
  case 0x80310031:
    ans = L"FVE_E_PROTECTOR_EXISTS";
    break;
  case 0x80310032:
    ans = L"FVE_E_RELATIVE_PATH";
    break;
  case 0x80310033:
    ans = L"FVE_E_PROTECTOR_NOT_FOUND";
    break;
  case 0x80310034:
    ans = L"FVE_E_INVALID_KEY_FORMAT";
    break;
  case 0x80310035:
    ans = L"FVE_E_INVALID_PASSWORD_FORMAT";
    break;
  case 0x80310036:
    ans = L"FVE_E_FIPS_RNG_CHECK_FAILED";
    break;
  case 0x80310037:
    ans = L"FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD";
    break;
  case 0x80310038:
    ans = L"FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT";
    break;
  case 0x80310039:
    ans = L"FVE_E_NOT_DECRYPTED";
    break;
  case 0x8031003A:
    ans = L"FVE_E_INVALID_PROTECTOR_TYPE";
    break;
  case 0x8031003B:
    ans = L"FVE_E_NO_PROTECTORS_TO_TEST";
    break;
  case 0x8031003C:
    ans = L"FVE_E_KEYFILE_NOT_FOUND";
    break;
  case 0x8031003D:
    ans = L"FVE_E_KEYFILE_INVALID";
    break;
  case 0x8031003E:
    ans = L"FVE_E_KEYFILE_NO_VMK";
    break;
  case 0x8031003F:
    ans = L"FVE_E_TPM_DISABLED";
    break;
  case 0x80310040:
    ans = L"FVE_E_NOT_ALLOWED_IN_SAFE_MODE";
    break;
  case 0x80310041:
    ans = L"FVE_E_TPM_INVALID_PCR";
    break;
  case 0x80310042:
    ans = L"FVE_E_TPM_NO_VMK";
    break;
  case 0x80310043:
    ans = L"FVE_E_PIN_INVALID";
    break;
  case 0x80310044:
    ans = L"FVE_E_AUTH_INVALID_APPLICATION";
    break;
  case 0x80310045:
    ans = L"FVE_E_AUTH_INVALID_CONFIG";
    break;
  case 0x80310046:
    ans = L"FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED";
    break;
  case 0x80310047:
    ans = L"FVE_E_FS_NOT_EXTENDED";
    break;
  case 0x80310048:
    ans = L"FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED";
    break;
  case 0x80310049:
    ans = L"FVE_E_NO_LICENSE";
    break;
  case 0x8031004A:
    ans = L"FVE_E_NOT_ON_STACK";
    break;
  case 0x8031004B:
    ans = L"FVE_E_FS_MOUNTED";
    break;
  case 0x8031004C:
    ans = L"FVE_E_TOKEN_NOT_IMPERSONATED";
    break;
  case 0x8031004D:
    ans = L"FVE_E_DRY_RUN_FAILED";
    break;
  case 0x8031004E:
    ans = L"FVE_E_REBOOT_REQUIRED";
    break;
  case 0x8031004F:
    ans = L"FVE_E_DEBUGGER_ENABLED";
    break;
  case 0x80310050:
    ans = L"FVE_E_RAW_ACCESS";
    break;
  case 0x80310051:
    ans = L"FVE_E_RAW_BLOCKED";
    break;
  case 0x80310052:
    ans = L"FVE_E_BCD_APPLICATIONS_PATH_INCORRECT";
    break;
  case 0x80310053:
    ans = L"FVE_E_NOT_ALLOWED_IN_VERSION";
    break;
  case 0x80310054:
    ans = L"FVE_E_NO_AUTOUNLOCK_MASTER_KEY";
    break;
  case 0x80310055:
    ans = L"FVE_E_MOR_FAILED";
    break;
  case 0x80310056:
    ans = L"FVE_E_HIDDEN_VOLUME";
    break;
  case 0x80310057:
    ans = L"FVE_E_TRANSIENT_STATE";
    break;
  case 0x80310058:
    ans = L"FVE_E_PUBKEY_NOT_ALLOWED";
    break;
  case 0x80310059:
    ans = L"FVE_E_VOLUME_HANDLE_OPEN";
    break;
  case 0x8031005A:
    ans = L"FVE_E_NO_FEATURE_LICENSE";
    break;
  case 0x8031005B:
    ans = L"FVE_E_INVALID_STARTUP_OPTIONS";
    break;
  case 0x8031005C:
    ans = L"FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED";
    break;
  case 0x8031005D:
    ans = L"FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED";
    break;
  case 0x8031005E:
    ans = L"FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED";
    break;
  case 0x8031005F:
    ans = L"FVE_E_POLICY_RECOVERY_KEY_REQUIRED";
    break;
  case 0x80310060:
    ans = L"FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED";
    break;
  case 0x80310061:
    ans = L"FVE_E_POLICY_STARTUP_PIN_REQUIRED";
    break;
  case 0x80310062:
    ans = L"FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED";
    break;
  case 0x80310063:
    ans = L"FVE_E_POLICY_STARTUP_KEY_REQUIRED";
    break;
  case 0x80310064:
    ans = L"FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED";
    break;
  case 0x80310065:
    ans = L"FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED";
    break;
  case 0x80310066:
    ans = L"FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED";
    break;
  case 0x80310067:
    ans = L"FVE_E_POLICY_STARTUP_TPM_REQUIRED";
    break;
  case 0x80310068:
    ans = L"FVE_E_POLICY_INVALID_PIN_LENGTH";
    break;
  case 0x80310069:
    ans = L"FVE_E_KEY_PROTECTOR_NOT_SUPPORTED";
    break;
  case 0x8031006A:
    ans = L"FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED";
    break;
  case 0x8031006B:
    ans = L"FVE_E_POLICY_PASSPHRASE_REQUIRED";
    break;
  case 0x8031006C:
    ans = L"FVE_E_FIPS_PREVENTS_PASSPHRASE";
    break;
  case 0x8031006D:
    ans = L"FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED";
    break;
  case 0x8031006E:
    ans = L"FVE_E_INVALID_BITLOCKER_OID";
    break;
  case 0x8031006F:
    ans = L"FVE_E_VOLUME_TOO_SMALL";
    break;
  case 0x80310070:
    ans = L"FVE_E_DV_NOT_SUPPORTED_ON_FS";
    break;
  case 0x80310071:
    ans = L"FVE_E_DV_NOT_ALLOWED_BY_GP";
    break;
  case 0x80310072:
    ans = L"FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED";
    break;
  case 0x80310073:
    ans = L"FVE_E_POLICY_USER_CERTIFICATE_REQUIRED";
    break;
  case 0x80310074:
    ans = L"FVE_E_POLICY_USER_CERT_MUST_BE_HW";
    break;
  case 0x80310075:
    ans = L"FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED";
    break;
  case 0x80310076:
    ans = L"FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED";
    break;
  case 0x80310077:
    ans = L"FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED";
    break;
  case 0x80310078:
    ans = L"FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED";
    break;
  case 0x80310079:
    ans = L"FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED";
    break;
  case 0x80310080:
    ans = L"FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH";
    break;
  case 0x80310081:
    ans = L"FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE";
    break;
  case 0x80310082:
    ans = L"FVE_E_RECOVERY_PARTITION";
    break;
  case 0x80310083:
    ans = L"FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON";
    break;
  case 0x80310084:
    ans = L"FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON";
    break;
  case 0x80310085:
    ans = L"FVE_E_NON_BITLOCKER_OID";
    break;
  case 0x80310086:
    ans = L"FVE_E_POLICY_PROHIBITS_SELFSIGNED";
    break;
  case 0x80310087:
    ans = L"FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED";
    break;
  case 0x80310088:
    ans = L"FVE_E_CONV_RECOVERY_FAILED";
    break;
  case 0x80310089:
    ans = L"FVE_E_VIRTUALIZED_SPACE_TOO_BIG";
    break;
  case 0x80310090:
    ans = L"FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON";
    break;
  case 0x80310091:
    ans = L"FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON";
    break;
  case 0x80310092:
    ans = L"FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON";
    break;
  case 0x80310093:
    ans = L"FVE_E_NON_BITLOCKER_KU";
    break;
  case 0x80310094:
    ans = L"FVE_E_PRIVATEKEY_AUTH_FAILED";
    break;
  case 0x80310095:
    ans = L"FVE_E_REMOVAL_OF_DRA_FAILED";
    break;
  case 0x80310096:
    ans = L"FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME";
    break;
  case 0x80310097:
    ans = L"FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME";
    break;
  case 0x80310098:
    ans = L"FVE_E_FIPS_HASH_KDF_NOT_ALLOWED";
    break;
  case 0x80310099:
    ans = L"FVE_E_ENH_PIN_INVALID";
    break;
  case 0x8031009A:
    ans = L"FVE_E_INVALID_PIN_CHARS";
    break;
  case 0x8031009B:
    ans = L"FVE_E_INVALID_DATUM_TYPE";
    break;
  case 0x8031009C:
    ans = L"FVE_E_EFI_ONLY";
    break;
  case 0x8031009D:
    ans = L"FVE_E_MULTIPLE_NKP_CERTS";
    break;
  case 0x8031009E:
    ans = L"FVE_E_REMOVAL_OF_NKP_FAILED";
    break;
  case 0x8031009F:
    ans = L"FVE_E_INVALID_NKP_CERT";
    break;
  case 0x803100A0:
    ans = L"FVE_E_NO_EXISTING_PIN";
    break;
  case 0x803100A1:
    ans = L"FVE_E_PROTECTOR_CHANGE_PIN_MISMATCH";
    break;
  case 0x803100A2:
    ans = L"FVE_E_PIN_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED";
    break;
  case 0x803100A3:
    ans = L"FVE_E_PROTECTOR_CHANGE_MAX_PIN_CHANGE_ATTEMPTS_REACHED";
    break;
  case 0x803100A4:
    ans = L"FVE_E_POLICY_PASSPHRASE_REQUIRES_ASCII";
    break;
  case 0x803100A5:
    ans = L"FVE_E_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE";
    break;
  case 0x803100A6:
    ans = L"FVE_E_WIPE_NOT_ALLOWED_ON_TP_STORAGE";
    break;
  case 0x803100A7:
    ans = L"FVE_E_KEY_LENGTH_NOT_SUPPORTED_BY_EDRIVE";
    break;
  case 0x803100A8:
    ans = L"FVE_E_NO_EXISTING_PASSPHRASE";
    break;
  case 0x803100A9:
    ans = L"FVE_E_PROTECTOR_CHANGE_PASSPHRASE_MISMATCH";
    break;
  case 0x803100AA:
    ans = L"FVE_E_PASSPHRASE_TOO_LONG";
    break;
  case 0x803100AB:
    ans = L"FVE_E_NO_PASSPHRASE_WITH_TPM";
    break;
  case 0x803100AC:
    ans = L"FVE_E_NO_TPM_WITH_PASSPHRASE";
    break;
  case 0x803100AD:
    ans = L"FVE_E_NOT_ALLOWED_ON_CSV_STACK";
    break;
  case 0x803100AE:
    ans = L"FVE_E_NOT_ALLOWED_ON_CLUSTER";
    break;
  case 0x803100AF:
    ans = L"FVE_E_EDRIVE_NO_FAILOVER_TO_SW";
    break;
  case 0x803100B0:
    ans = L"FVE_E_EDRIVE_BAND_IN_USE";
    break;
  case 0x803100B1:
    ans = L"FVE_E_EDRIVE_DISALLOWED_BY_GP";
    break;
  case 0x803100B2:
    ans = L"FVE_E_EDRIVE_INCOMPATIBLE_VOLUME";
    break;
  case 0x803100B3:
    ans = L"FVE_E_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING";
    break;
  case 0x803100B4:
    ans = L"FVE_E_EDRIVE_DV_NOT_SUPPORTED";
    break;
  case 0x803100B5:
    ans = L"FVE_E_NO_PREBOOT_KEYBOARD_DETECTED";
    break;
  case 0x803100B6:
    ans = L"FVE_E_NO_PREBOOT_KEYBOARD_OR_WINRE_DETECTED";
    break;
  case 0x803100B7:
    ans = L"FVE_E_POLICY_REQUIRES_STARTUP_PIN_ON_TOUCH_DEVICE";
    break;
  case 0x803100B8:
    ans = L"FVE_E_POLICY_REQUIRES_RECOVERY_PASSWORD_ON_TOUCH_DEVICE";
    break;
  case 0x803100B9:
    ans = L"FVE_E_WIPE_CANCEL_NOT_APPLICABLE";
    break;
  case 0x803100BA:
    ans = L"FVE_E_SECUREBOOT_DISABLED";
    break;
  case 0x803100BB:
    ans = L"FVE_E_SECUREBOOT_CONFIGURATION_INVALID";
    break;
  case 0x803100BC:
    ans = L"FVE_E_EDRIVE_DRY_RUN_FAILED";
    break;
  case 0x803100BD:
    ans = L"FVE_E_SHADOW_COPY_PRESENT";
    break;
  case 0x803100BE:
    ans = L"FVE_E_POLICY_INVALID_ENHANCED_BCD_SETTINGS";
    break;
  case 0x803100BF:
    ans = L"FVE_E_EDRIVE_INCOMPATIBLE_FIRMWARE";
    break;
  case 0x803100C0:
    ans = L"FVE_E_PROTECTOR_CHANGE_MAX_PASSPHRASE_CHANGE_ATTEMPTS_REACHED";
    break;
  case 0x803100C1:
    ans = L"FVE_E_PASSPHRASE_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED";
    break;
  case 0x803100C2:
    ans = L"FVE_E_LIVEID_ACCOUNT_SUSPENDED";
    break;
  case 0x803100C3:
    ans = L"FVE_E_LIVEID_ACCOUNT_BLOCKED";
    break;
  case 0x803100C4:
    ans = L"FVE_E_NOT_PROVISIONED_ON_ALL_VOLUMES";
    break;
  case 0x803100C5:
    ans = L"FVE_E_DE_FIXED_DATA_NOT_SUPPORTED";
    break;
  case 0x803100C6:
    ans = L"FVE_E_DE_HARDWARE_NOT_COMPLIANT";
    break;
  case 0x803100C7:
    ans = L"FVE_E_DE_WINRE_NOT_CONFIGURED";
    break;
  case 0x803100C8:
    ans = L"FVE_E_DE_PROTECTION_SUSPENDED";
    break;
  case 0x803100C9:
    ans = L"FVE_E_DE_OS_VOLUME_NOT_PROTECTED";
    break;
  case 0x803100CA:
    ans = L"FVE_E_DE_DEVICE_LOCKEDOUT";
    break;
  case 0x803100CB:
    ans = L"FVE_E_DE_PROTECTION_NOT_YET_ENABLED";
    break;
  case 0x803100CC:
    ans = L"FVE_E_INVALID_PIN_CHARS_DETAILED";
    break;
  case 0x803100CD:
    ans = L"FVE_E_DEVICE_LOCKOUT_COUNTER_UNAVAILABLE";
    break;
  case 0x803100CE:
    ans = L"FVE_E_DEVICELOCKOUT_COUNTER_MISMATCH";
    break;
  case 0x803100CF:
    ans = L"FVE_E_BUFFER_TOO_LARGE";
    break;
  case 0x803100D0:
    ans = L"FVE_E_NO_SUCH_CAPABILITY_ON_TARGET";
    break;
  case 0x803100D1:
    ans = L"FVE_E_DE_PREVENTED_FOR_OS";
    break;
  case 0x803100D2:
    ans = L"FVE_E_DE_VOLUME_OPTED_OUT";
    break;
  case 0x803100D3:
    ans = L"FVE_E_DE_VOLUME_NOT_SUPPORTED";
    break;
  case 0x803100D4:
    ans = L"FVE_E_EOW_NOT_SUPPORTED_IN_VERSION";
    break;
  case 0x803100D5:
    ans = L"FVE_E_ADBACKUP_NOT_ENABLED";
    break;
  case 0x803100D6:
    ans = L"FVE_E_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT";
    break;
  case 0x803100D7:
    ans = L"FVE_E_NOT_DE_VOLUME";
    break;
  case 0x803100D8:
    ans = L"FVE_E_PROTECTION_CANNOT_BE_DISABLED";
    break;
  case 0x803100D9:
    ans = L"FVE_E_OSV_KSR_NOT_ALLOWED";
    break;
  case 0x80320001:
    ans = L"FWP_E_CALLOUT_NOT_FOUND";
    break;
  case 0x80320002:
    ans = L"FWP_E_CONDITION_NOT_FOUND";
    break;
  case 0x80320003:
    ans = L"FWP_E_FILTER_NOT_FOUND";
    break;
  case 0x80320004:
    ans = L"FWP_E_LAYER_NOT_FOUND";
    break;
  case 0x80320005:
    ans = L"FWP_E_PROVIDER_NOT_FOUND";
    break;
  case 0x80320006:
    ans = L"FWP_E_PROVIDER_CONTEXT_NOT_FOUND";
    break;
  case 0x80320007:
    ans = L"FWP_E_SUBLAYER_NOT_FOUND";
    break;
  case 0x80320008:
    ans = L"FWP_E_NOT_FOUND";
    break;
  case 0x80320009:
    ans = L"FWP_E_ALREADY_EXISTS";
    break;
  case 0x8032000A:
    ans = L"FWP_E_IN_USE";
    break;
  case 0x8032000B:
    ans = L"FWP_E_DYNAMIC_SESSION_IN_PROGRESS";
    break;
  case 0x8032000C:
    ans = L"FWP_E_WRONG_SESSION";
    break;
  case 0x8032000D:
    ans = L"FWP_E_NO_TXN_IN_PROGRESS";
    break;
  case 0x8032000E:
    ans = L"FWP_E_TXN_IN_PROGRESS";
    break;
  case 0x8032000F:
    ans = L"FWP_E_TXN_ABORTED";
    break;
  case 0x80320010:
    ans = L"FWP_E_SESSION_ABORTED";
    break;
  case 0x80320011:
    ans = L"FWP_E_INCOMPATIBLE_TXN";
    break;
  case 0x80320012:
    ans = L"FWP_E_TIMEOUT";
    break;
  case 0x80320013:
    ans = L"FWP_E_NET_EVENTS_DISABLED";
    break;
  case 0x80320014:
    ans = L"FWP_E_INCOMPATIBLE_LAYER";
    break;
  case 0x80320015:
    ans = L"FWP_E_KM_CLIENTS_ONLY";
    break;
  case 0x80320016:
    ans = L"FWP_E_LIFETIME_MISMATCH";
    break;
  case 0x80320017:
    ans = L"FWP_E_BUILTIN_OBJECT";
    break;
  case 0x80320018:
    ans = L"FWP_E_TOO_MANY_CALLOUTS";
    break;
  case 0x80320019:
    ans = L"FWP_E_NOTIFICATION_DROPPED";
    break;
  case 0x8032001A:
    ans = L"FWP_E_TRAFFIC_MISMATCH";
    break;
  case 0x8032001B:
    ans = L"FWP_E_INCOMPATIBLE_SA_STATE";
    break;
  case 0x8032001C:
    ans = L"FWP_E_NULL_POINTER";
    break;
  case 0x8032001D:
    ans = L"FWP_E_INVALID_ENUMERATOR";
    break;
  case 0x8032001E:
    ans = L"FWP_E_INVALID_FLAGS";
    break;
  case 0x8032001F:
    ans = L"FWP_E_INVALID_NET_MASK";
    break;
  case 0x80320020:
    ans = L"FWP_E_INVALID_RANGE";
    break;
  case 0x80320021:
    ans = L"FWP_E_INVALID_INTERVAL";
    break;
  case 0x80320022:
    ans = L"FWP_E_ZERO_LENGTH_ARRAY";
    break;
  case 0x80320023:
    ans = L"FWP_E_NULL_DISPLAY_NAME";
    break;
  case 0x80320024:
    ans = L"FWP_E_INVALID_ACTION_TYPE";
    break;
  case 0x80320025:
    ans = L"FWP_E_INVALID_WEIGHT";
    break;
  case 0x80320026:
    ans = L"FWP_E_MATCH_TYPE_MISMATCH";
    break;
  case 0x80320027:
    ans = L"FWP_E_TYPE_MISMATCH";
    break;
  case 0x80320028:
    ans = L"FWP_E_OUT_OF_BOUNDS";
    break;
  case 0x80320029:
    ans = L"FWP_E_RESERVED";
    break;
  case 0x8032002A:
    ans = L"FWP_E_DUPLICATE_CONDITION";
    break;
  case 0x8032002B:
    ans = L"FWP_E_DUPLICATE_KEYMOD";
    break;
  case 0x8032002C:
    ans = L"FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER";
    break;
  case 0x8032002D:
    ans = L"FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER";
    break;
  case 0x8032002E:
    ans = L"FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER";
    break;
  case 0x8032002F:
    ans = L"FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT";
    break;
  case 0x80320030:
    ans = L"FWP_E_INCOMPATIBLE_AUTH_METHOD";
    break;
  case 0x80320031:
    ans = L"FWP_E_INCOMPATIBLE_DH_GROUP";
    break;
  case 0x80320032:
    ans = L"FWP_E_EM_NOT_SUPPORTED";
    break;
  case 0x80320033:
    ans = L"FWP_E_NEVER_MATCH";
    break;
  case 0x80320034:
    ans = L"FWP_E_PROVIDER_CONTEXT_MISMATCH";
    break;
  case 0x80320035:
    ans = L"FWP_E_INVALID_PARAMETER";
    break;
  case 0x80320036:
    ans = L"FWP_E_TOO_MANY_SUBLAYERS";
    break;
  case 0x80320037:
    ans = L"FWP_E_CALLOUT_NOTIFICATION_FAILED";
    break;
  case 0x80320038:
    ans = L"FWP_E_INVALID_AUTH_TRANSFORM";
    break;
  case 0x80320039:
    ans = L"FWP_E_INVALID_CIPHER_TRANSFORM";
    break;
  case 0x8032003A:
    ans = L"FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM";
    break;
  case 0x8032003B:
    ans = L"FWP_E_INVALID_TRANSFORM_COMBINATION";
    break;
  case 0x8032003C:
    ans = L"FWP_E_DUPLICATE_AUTH_METHOD";
    break;
  case 0x8032003D:
    ans = L"FWP_E_INVALID_TUNNEL_ENDPOINT";
    break;
  case 0x8032003E:
    ans = L"FWP_E_L2_DRIVER_NOT_READY";
    break;
  case 0x8032003F:
    ans = L"FWP_E_KEY_DICTATOR_ALREADY_REGISTERED";
    break;
  case 0x80320040:
    ans = L"FWP_E_KEY_DICTATION_INVALID_KEYING_MATERIAL";
    break;
  case 0x80320041:
    ans = L"FWP_E_CONNECTIONS_DISABLED";
    break;
  case 0x80320042:
    ans = L"FWP_E_INVALID_DNS_NAME";
    break;
  case 0x80320043:
    ans = L"FWP_E_STILL_ON";
    break;
  case 0x80320044:
    ans = L"FWP_E_IKEEXT_NOT_RUNNING";
    break;
  case 0x80320104:
    ans = L"FWP_E_DROP_NOICMP";
    break;
  case 0x003D0000:
    ans = L"WS_S_ASYNC";
    break;
  case 0x003D0001:
    ans = L"WS_S_END";
    break;
  case 0x803D0000:
    ans = L"WS_E_INVALID_FORMAT";
    break;
  case 0x803D0001:
    ans = L"WS_E_OBJECT_FAULTED";
    break;
  case 0x803D0002:
    ans = L"WS_E_NUMERIC_OVERFLOW";
    break;
  case 0x803D0003:
    ans = L"WS_E_INVALID_OPERATION";
    break;
  case 0x803D0004:
    ans = L"WS_E_OPERATION_ABORTED";
    break;
  case 0x803D0005:
    ans = L"WS_E_ENDPOINT_ACCESS_DENIED";
    break;
  case 0x803D0006:
    ans = L"WS_E_OPERATION_TIMED_OUT";
    break;
  case 0x803D0007:
    ans = L"WS_E_OPERATION_ABANDONED";
    break;
  case 0x803D0008:
    ans = L"WS_E_QUOTA_EXCEEDED";
    break;
  case 0x803D0009:
    ans = L"WS_E_NO_TRANSLATION_AVAILABLE";
    break;
  case 0x803D000A:
    ans = L"WS_E_SECURITY_VERIFICATION_FAILURE";
    break;
  case 0x803D000B:
    ans = L"WS_E_ADDRESS_IN_USE";
    break;
  case 0x803D000C:
    ans = L"WS_E_ADDRESS_NOT_AVAILABLE";
    break;
  case 0x803D000D:
    ans = L"WS_E_ENDPOINT_NOT_FOUND";
    break;
  case 0x803D000E:
    ans = L"WS_E_ENDPOINT_NOT_AVAILABLE";
    break;
  case 0x803D000F:
    ans = L"WS_E_ENDPOINT_FAILURE";
    break;
  case 0x803D0010:
    ans = L"WS_E_ENDPOINT_UNREACHABLE";
    break;
  case 0x803D0011:
    ans = L"WS_E_ENDPOINT_ACTION_NOT_SUPPORTED";
    break;
  case 0x803D0012:
    ans = L"WS_E_ENDPOINT_TOO_BUSY";
    break;
  case 0x803D0013:
    ans = L"WS_E_ENDPOINT_FAULT_RECEIVED";
    break;
  case 0x803D0014:
    ans = L"WS_E_ENDPOINT_DISCONNECTED";
    break;
  case 0x803D0015:
    ans = L"WS_E_PROXY_FAILURE";
    break;
  case 0x803D0016:
    ans = L"WS_E_PROXY_ACCESS_DENIED";
    break;
  case 0x803D0017:
    ans = L"WS_E_NOT_SUPPORTED";
    break;
  case 0x803D0018:
    ans = L"WS_E_PROXY_REQUIRES_BASIC_AUTH";
    break;
  case 0x803D0019:
    ans = L"WS_E_PROXY_REQUIRES_DIGEST_AUTH";
    break;
  case 0x803D001A:
    ans = L"WS_E_PROXY_REQUIRES_NTLM_AUTH";
    break;
  case 0x803D001B:
    ans = L"WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH";
    break;
  case 0x803D001C:
    ans = L"WS_E_SERVER_REQUIRES_BASIC_AUTH";
    break;
  case 0x803D001D:
    ans = L"WS_E_SERVER_REQUIRES_DIGEST_AUTH";
    break;
  case 0x803D001E:
    ans = L"WS_E_SERVER_REQUIRES_NTLM_AUTH";
    break;
  case 0x803D001F:
    ans = L"WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH";
    break;
  case 0x803D0020:
    ans = L"WS_E_INVALID_ENDPOINT_URL";
    break;
  case 0x803D0021:
    ans = L"WS_E_OTHER";
    break;
  case 0x803D0022:
    ans = L"WS_E_SECURITY_TOKEN_EXPIRED";
    break;
  case 0x803D0023:
    ans = L"WS_E_SECURITY_SYSTEM_FAILURE";
    break;
  case 0x80340002:
    ans = L"ERROR_NDIS_INTERFACE_CLOSING";
    break;
  case 0x80340004:
    ans = L"ERROR_NDIS_BAD_VERSION";
    break;
  case 0x80340005:
    ans = L"ERROR_NDIS_BAD_CHARACTERISTICS";
    break;
  case 0x80340006:
    ans = L"ERROR_NDIS_ADAPTER_NOT_FOUND";
    break;
  case 0x80340007:
    ans = L"ERROR_NDIS_OPEN_FAILED";
    break;
  case 0x80340008:
    ans = L"ERROR_NDIS_DEVICE_FAILED";
    break;
  case 0x80340009:
    ans = L"ERROR_NDIS_MULTICAST_FULL";
    break;
  case 0x8034000A:
    ans = L"ERROR_NDIS_MULTICAST_EXISTS";
    break;
  case 0x8034000B:
    ans = L"ERROR_NDIS_MULTICAST_NOT_FOUND";
    break;
  case 0x8034000C:
    ans = L"ERROR_NDIS_REQUEST_ABORTED";
    break;
  case 0x8034000D:
    ans = L"ERROR_NDIS_RESET_IN_PROGRESS";
    break;
  case 0x803400BB:
    ans = L"ERROR_NDIS_NOT_SUPPORTED";
    break;
  case 0x8034000F:
    ans = L"ERROR_NDIS_INVALID_PACKET";
    break;
  case 0x80340011:
    ans = L"ERROR_NDIS_ADAPTER_NOT_READY";
    break;
  case 0x80340014:
    ans = L"ERROR_NDIS_INVALID_LENGTH";
    break;
  case 0x80340015:
    ans = L"ERROR_NDIS_INVALID_DATA";
    break;
  case 0x80340016:
    ans = L"ERROR_NDIS_BUFFER_TOO_SHORT";
    break;
  case 0x80340017:
    ans = L"ERROR_NDIS_INVALID_OID";
    break;
  case 0x80340018:
    ans = L"ERROR_NDIS_ADAPTER_REMOVED";
    break;
  case 0x80340019:
    ans = L"ERROR_NDIS_UNSUPPORTED_MEDIA";
    break;
  case 0x8034001A:
    ans = L"ERROR_NDIS_GROUP_ADDRESS_IN_USE";
    break;
  case 0x8034001B:
    ans = L"ERROR_NDIS_FILE_NOT_FOUND";
    break;
  case 0x8034001C:
    ans = L"ERROR_NDIS_ERROR_READING_FILE";
    break;
  case 0x8034001D:
    ans = L"ERROR_NDIS_ALREADY_MAPPED";
    break;
  case 0x8034001E:
    ans = L"ERROR_NDIS_RESOURCE_CONFLICT";
    break;
  case 0x8034001F:
    ans = L"ERROR_NDIS_MEDIA_DISCONNECTED";
    break;
  case 0x80340022:
    ans = L"ERROR_NDIS_INVALID_ADDRESS";
    break;
  case 0x80340010:
    ans = L"ERROR_NDIS_INVALID_DEVICE_REQUEST";
    break;
  case 0x8034002A:
    ans = L"ERROR_NDIS_PAUSED";
    break;
  case 0x8034002B:
    ans = L"ERROR_NDIS_INTERFACE_NOT_FOUND";
    break;
  case 0x8034002C:
    ans = L"ERROR_NDIS_UNSUPPORTED_REVISION";
    break;
  case 0x8034002D:
    ans = L"ERROR_NDIS_INVALID_PORT";
    break;
  case 0x8034002E:
    ans = L"ERROR_NDIS_INVALID_PORT_STATE";
    break;
  case 0x8034002F:
    ans = L"ERROR_NDIS_LOW_POWER_STATE";
    break;
  case 0x80340030:
    ans = L"ERROR_NDIS_REINIT_REQUIRED";
    break;
  case 0x80340031:
    ans = L"ERROR_NDIS_NO_QUEUES";
    break;
  case 0x80342000:
    ans = L"ERROR_NDIS_DOT11_AUTO_CONFIG_ENABLED";
    break;
  case 0x80342001:
    ans = L"ERROR_NDIS_DOT11_MEDIA_IN_USE";
    break;
  case 0x80342002:
    ans = L"ERROR_NDIS_DOT11_POWER_STATE_INVALID";
    break;
  case 0x80342003:
    ans = L"ERROR_NDIS_PM_WOL_PATTERN_LIST_FULL";
    break;
  case 0x80342004:
    ans = L"ERROR_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL";
    break;
  case 0x80342005:
    ans = L"ERROR_NDIS_DOT11_AP_CHANNEL_CURRENTLY_NOT_AVAILABLE";
    break;
  case 0x80342006:
    ans = L"ERROR_NDIS_DOT11_AP_BAND_CURRENTLY_NOT_AVAILABLE";
    break;
  case 0x80342007:
    ans = L"ERROR_NDIS_DOT11_AP_CHANNEL_NOT_ALLOWED";
    break;
  case 0x80342008:
    ans = L"ERROR_NDIS_DOT11_AP_BAND_NOT_ALLOWED";
    break;
  case 0x00340001:
    ans = L"ERROR_NDIS_INDICATION_REQUIRED";
    break;
  case 0xC034100F:
    ans = L"ERROR_NDIS_OFFLOAD_POLICY";
    break;
  case 0xC0341012:
    ans = L"ERROR_NDIS_OFFLOAD_CONNECTION_REJECTED";
    break;
  case 0xC0341013:
    ans = L"ERROR_NDIS_OFFLOAD_PATH_REJECTED";
    break;
  case 0xC0350002:
    ans = L"ERROR_HV_INVALID_HYPERCALL_CODE";
    break;
  case 0xC0350003:
    ans = L"ERROR_HV_INVALID_HYPERCALL_INPUT";
    break;
  case 0xC0350004:
    ans = L"ERROR_HV_INVALID_ALIGNMENT";
    break;
  case 0xC0350005:
    ans = L"ERROR_HV_INVALID_PARAMETER";
    break;
  case 0xC0350006:
    ans = L"ERROR_HV_ACCESS_DENIED";
    break;
  case 0xC0350007:
    ans = L"ERROR_HV_INVALID_PARTITION_STATE";
    break;
  case 0xC0350008:
    ans = L"ERROR_HV_OPERATION_DENIED";
    break;
  case 0xC0350009:
    ans = L"ERROR_HV_UNKNOWN_PROPERTY";
    break;
  case 0xC035000A:
    ans = L"ERROR_HV_PROPERTY_VALUE_OUT_OF_RANGE";
    break;
  case 0xC035000B:
    ans = L"ERROR_HV_INSUFFICIENT_MEMORY";
    break;
  case 0xC035000C:
    ans = L"ERROR_HV_PARTITION_TOO_DEEP";
    break;
  case 0xC035000D:
    ans = L"ERROR_HV_INVALID_PARTITION_ID";
    break;
  case 0xC035000E:
    ans = L"ERROR_HV_INVALID_VP_INDEX";
    break;
  case 0xC0350011:
    ans = L"ERROR_HV_INVALID_PORT_ID";
    break;
  case 0xC0350012:
    ans = L"ERROR_HV_INVALID_CONNECTION_ID";
    break;
  case 0xC0350013:
    ans = L"ERROR_HV_INSUFFICIENT_BUFFERS";
    break;
  case 0xC0350014:
    ans = L"ERROR_HV_NOT_ACKNOWLEDGED";
    break;
  case 0xC0350015:
    ans = L"ERROR_HV_INVALID_VP_STATE";
    break;
  case 0xC0350016:
    ans = L"ERROR_HV_ACKNOWLEDGED";
    break;
  case 0xC0350017:
    ans = L"ERROR_HV_INVALID_SAVE_RESTORE_STATE";
    break;
  case 0xC0350018:
    ans = L"ERROR_HV_INVALID_SYNIC_STATE";
    break;
  case 0xC0350019:
    ans = L"ERROR_HV_OBJECT_IN_USE";
    break;
  case 0xC035001A:
    ans = L"ERROR_HV_INVALID_PROXIMITY_DOMAIN_INFO";
    break;
  case 0xC035001B:
    ans = L"ERROR_HV_NO_DATA";
    break;
  case 0xC035001C:
    ans = L"ERROR_HV_INACTIVE";
    break;
  case 0xC035001D:
    ans = L"ERROR_HV_NO_RESOURCES";
    break;
  case 0xC035001E:
    ans = L"ERROR_HV_FEATURE_UNAVAILABLE";
    break;
  case 0xC0350033:
    ans = L"ERROR_HV_INSUFFICIENT_BUFFER";
    break;
  case 0xC0350038:
    ans = L"ERROR_HV_INSUFFICIENT_DEVICE_DOMAINS";
    break;
  case 0xC035003C:
    ans = L"ERROR_HV_CPUID_FEATURE_VALIDATION";
    break;
  case 0xC035003D:
    ans = L"ERROR_HV_CPUID_XSAVE_FEATURE_VALIDATION";
    break;
  case 0xC035003E:
    ans = L"ERROR_HV_PROCESSOR_STARTUP_TIMEOUT";
    break;
  case 0xC035003F:
    ans = L"ERROR_HV_SMX_ENABLED";
    break;
  case 0xC0350041:
    ans = L"ERROR_HV_INVALID_LP_INDEX";
    break;
  case 0xC0350050:
    ans = L"ERROR_HV_INVALID_REGISTER_VALUE";
    break;
  case 0xC0350051:
    ans = L"ERROR_HV_INVALID_VTL_STATE";
    break;
  case 0xC0350055:
    ans = L"ERROR_HV_NX_NOT_DETECTED";
    break;
  case 0xC0350057:
    ans = L"ERROR_HV_INVALID_DEVICE_ID";
    break;
  case 0xC0350058:
    ans = L"ERROR_HV_INVALID_DEVICE_STATE";
    break;
  case 0x00350059:
    ans = L"ERROR_HV_PENDING_PAGE_REQUESTS";
    break;
  case 0xC0350060:
    ans = L"ERROR_HV_PAGE_REQUEST_INVALID";
    break;
  case 0xC035006F:
    ans = L"ERROR_HV_INVALID_CPU_GROUP_ID";
    break;
  case 0xC0350070:
    ans = L"ERROR_HV_INVALID_CPU_GROUP_STATE";
    break;
  case 0xC0350071:
    ans = L"ERROR_HV_OPERATION_FAILED";
    break;
  case 0xC0350072:
    ans = L"ERROR_HV_NOT_ALLOWED_WITH_NESTED_VIRT_ACTIVE";
    break;
  case 0xC0350073:
    ans = L"ERROR_HV_INSUFFICIENT_ROOT_MEMORY";
    break;
  case 0xC0351000:
    ans = L"ERROR_HV_NOT_PRESENT";
    break;
  case 0xC0370001:
    ans = L"ERROR_VID_DUPLICATE_HANDLER";
    break;
  case 0xC0370002:
    ans = L"ERROR_VID_TOO_MANY_HANDLERS";
    break;
  case 0xC0370003:
    ans = L"ERROR_VID_QUEUE_FULL";
    break;
  case 0xC0370004:
    ans = L"ERROR_VID_HANDLER_NOT_PRESENT";
    break;
  case 0xC0370005:
    ans = L"ERROR_VID_INVALID_OBJECT_NAME";
    break;
  case 0xC0370006:
    ans = L"ERROR_VID_PARTITION_NAME_TOO_LONG";
    break;
  case 0xC0370007:
    ans = L"ERROR_VID_MESSAGE_QUEUE_NAME_TOO_LONG";
    break;
  case 0xC0370008:
    ans = L"ERROR_VID_PARTITION_ALREADY_EXISTS";
    break;
  case 0xC0370009:
    ans = L"ERROR_VID_PARTITION_DOES_NOT_EXIST";
    break;
  case 0xC037000A:
    ans = L"ERROR_VID_PARTITION_NAME_NOT_FOUND";
    break;
  case 0xC037000B:
    ans = L"ERROR_VID_MESSAGE_QUEUE_ALREADY_EXISTS";
    break;
  case 0xC037000C:
    ans = L"ERROR_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT";
    break;
  case 0xC037000D:
    ans = L"ERROR_VID_MB_STILL_REFERENCED";
    break;
  case 0xC037000E:
    ans = L"ERROR_VID_CHILD_GPA_PAGE_SET_CORRUPTED";
    break;
  case 0xC037000F:
    ans = L"ERROR_VID_INVALID_NUMA_SETTINGS";
    break;
  case 0xC0370010:
    ans = L"ERROR_VID_INVALID_NUMA_NODE_INDEX";
    break;
  case 0xC0370011:
    ans = L"ERROR_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED";
    break;
  case 0xC0370012:
    ans = L"ERROR_VID_INVALID_MEMORY_BLOCK_HANDLE";
    break;
  case 0xC0370013:
    ans = L"ERROR_VID_PAGE_RANGE_OVERFLOW";
    break;
  case 0xC0370014:
    ans = L"ERROR_VID_INVALID_MESSAGE_QUEUE_HANDLE";
    break;
  case 0xC0370015:
    ans = L"ERROR_VID_INVALID_GPA_RANGE_HANDLE";
    break;
  case 0xC0370016:
    ans = L"ERROR_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE";
    break;
  case 0xC0370017:
    ans = L"ERROR_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED";
    break;
  case 0xC0370018:
    ans = L"ERROR_VID_INVALID_PPM_HANDLE";
    break;
  case 0xC0370019:
    ans = L"ERROR_VID_MBPS_ARE_LOCKED";
    break;
  case 0xC037001A:
    ans = L"ERROR_VID_MESSAGE_QUEUE_CLOSED";
    break;
  case 0xC037001B:
    ans = L"ERROR_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED";
    break;
  case 0xC037001C:
    ans = L"ERROR_VID_STOP_PENDING";
    break;
  case 0xC037001D:
    ans = L"ERROR_VID_INVALID_PROCESSOR_STATE";
    break;
  case 0xC037001E:
    ans = L"ERROR_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT";
    break;
  case 0xC037001F:
    ans = L"ERROR_VID_KM_INTERFACE_ALREADY_INITIALIZED";
    break;
  case 0xC0370020:
    ans = L"ERROR_VID_MB_PROPERTY_ALREADY_SET_RESET";
    break;
  case 0xC0370021:
    ans = L"ERROR_VID_MMIO_RANGE_DESTROYED";
    break;
  case 0xC0370022:
    ans = L"ERROR_VID_INVALID_CHILD_GPA_PAGE_SET";
    break;
  case 0xC0370023:
    ans = L"ERROR_VID_RESERVE_PAGE_SET_IS_BEING_USED";
    break;
  case 0xC0370024:
    ans = L"ERROR_VID_RESERVE_PAGE_SET_TOO_SMALL";
    break;
  case 0xC0370025:
    ans = L"ERROR_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE";
    break;
  case 0xC0370026:
    ans = L"ERROR_VID_MBP_COUNT_EXCEEDED_LIMIT";
    break;
  case 0xC0370027:
    ans = L"ERROR_VID_SAVED_STATE_CORRUPT";
    break;
  case 0xC0370028:
    ans = L"ERROR_VID_SAVED_STATE_UNRECOGNIZED_ITEM";
    break;
  case 0xC0370029:
    ans = L"ERROR_VID_SAVED_STATE_INCOMPATIBLE";
    break;
  case 0xC037002A:
    ans = L"ERROR_VID_VTL_ACCESS_DENIED";
    break;
  case 0xC0370100:
    ans = L"ERROR_VMCOMPUTE_TERMINATED_DURING_START";
    break;
  case 0xC0370101:
    ans = L"ERROR_VMCOMPUTE_IMAGE_MISMATCH";
    break;
  case 0xC0370102:
    ans = L"ERROR_VMCOMPUTE_HYPERV_NOT_INSTALLED";
    break;
  case 0xC0370103:
    ans = L"ERROR_VMCOMPUTE_OPERATION_PENDING";
    break;
  case 0xC0370104:
    ans = L"ERROR_VMCOMPUTE_TOO_MANY_NOTIFICATIONS";
    break;
  case 0xC0370105:
    ans = L"ERROR_VMCOMPUTE_INVALID_STATE";
    break;
  case 0xC0370106:
    ans = L"ERROR_VMCOMPUTE_UNEXPECTED_EXIT";
    break;
  case 0xC0370107:
    ans = L"ERROR_VMCOMPUTE_TERMINATED";
    break;
  case 0xC0370108:
    ans = L"ERROR_VMCOMPUTE_CONNECT_FAILED";
    break;
  case 0xC0370109:
    ans = L"ERROR_VMCOMPUTE_TIMEOUT";
    break;
  case 0xC037010A:
    ans = L"ERROR_VMCOMPUTE_CONNECTION_CLOSED";
    break;
  case 0xC037010B:
    ans = L"ERROR_VMCOMPUTE_UNKNOWN_MESSAGE";
    break;
  case 0xC037010C:
    ans = L"ERROR_VMCOMPUTE_UNSUPPORTED_PROTOCOL_VERSION";
    break;
  case 0xC037010D:
    ans = L"ERROR_VMCOMPUTE_INVALID_JSON";
    break;
  case 0xC037010E:
    ans = L"ERROR_VMCOMPUTE_SYSTEM_NOT_FOUND";
    break;
  case 0xC037010F:
    ans = L"ERROR_VMCOMPUTE_SYSTEM_ALREADY_EXISTS";
    break;
  case 0xC0370110:
    ans = L"ERROR_VMCOMPUTE_SYSTEM_ALREADY_STOPPED";
    break;
  case 0xC0370111:
    ans = L"ERROR_VMCOMPUTE_PROTOCOL_ERROR";
    break;
  case 0xC0370112:
    ans = L"ERROR_VMCOMPUTE_INVALID_LAYER";
    break;
  case 0xC0370113:
    ans = L"ERROR_VMCOMPUTE_WINDOWS_INSIDER_REQUIRED";
    break;
  case 0x80370100:
    ans = L"HCS_E_TERMINATED_DURING_START";
    break;
  case 0x80370101:
    ans = L"HCS_E_IMAGE_MISMATCH";
    break;
  case 0x80370102:
    ans = L"HCS_E_HYPERV_NOT_INSTALLED";
    break;
  case 0x80370105:
    ans = L"HCS_E_INVALID_STATE";
    break;
  case 0x80370106:
    ans = L"HCS_E_UNEXPECTED_EXIT";
    break;
  case 0x80370107:
    ans = L"HCS_E_TERMINATED";
    break;
  case 0x80370108:
    ans = L"HCS_E_CONNECT_FAILED";
    break;
  case 0x80370109:
    ans = L"HCS_E_CONNECTION_TIMEOUT";
    break;
  case 0x8037010A:
    ans = L"HCS_E_CONNECTION_CLOSED";
    break;
  case 0x8037010B:
    ans = L"HCS_E_UNKNOWN_MESSAGE";
    break;
  case 0x8037010C:
    ans = L"HCS_E_UNSUPPORTED_PROTOCOL_VERSION";
    break;
  case 0x8037010D:
    ans = L"HCS_E_INVALID_JSON";
    break;
  case 0x8037010E:
    ans = L"HCS_E_SYSTEM_NOT_FOUND";
    break;
  case 0x8037010F:
    ans = L"HCS_E_SYSTEM_ALREADY_EXISTS";
    break;
  case 0x80370110:
    ans = L"HCS_E_SYSTEM_ALREADY_STOPPED";
    break;
  case 0x80370111:
    ans = L"HCS_E_PROTOCOL_ERROR";
    break;
  case 0x80370112:
    ans = L"HCS_E_INVALID_LAYER";
    break;
  case 0x80370113:
    ans = L"HCS_E_WINDOWS_INSIDER_REQUIRED";
    break;
  case 0x80370114:
    ans = L"HCS_E_SERVICE_NOT_AVAILABLE";
    break;
  case 0x80370115:
    ans = L"HCS_E_OPERATION_NOT_STARTED";
    break;
  case 0x80370116:
    ans = L"HCS_E_OPERATION_ALREADY_STARTED";
    break;
  case 0x80370117:
    ans = L"HCS_E_OPERATION_PENDING";
    break;
  case 0x80370118:
    ans = L"HCS_E_OPERATION_TIMEOUT";
    break;
  case 0x80370119:
    ans = L"HCS_E_OPERATION_SYSTEM_CALLBACK_ALREADY_SET";
    break;
  case 0x8037011A:
    ans = L"HCS_E_OPERATION_RESULT_ALLOCATION_FAILED";
    break;
  case 0x8037011B:
    ans = L"HCS_E_ACCESS_DENIED";
    break;
  case 0x8037011C:
    ans = L"HCS_E_GUEST_CRITICAL_ERROR";
    break;
  case 0xC0370200:
    ans = L"ERROR_VNET_VIRTUAL_SWITCH_NAME_NOT_FOUND";
    break;
  case 0x80370001:
    ans = L"ERROR_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED";
    break;
  case 0x80370300:
    ans = L"WHV_E_UNKNOWN_CAPABILITY";
    break;
  case 0x80370301:
    ans = L"WHV_E_INSUFFICIENT_BUFFER";
    break;
  case 0x80370302:
    ans = L"WHV_E_UNKNOWN_PROPERTY";
    break;
  case 0x80370303:
    ans = L"WHV_E_UNSUPPORTED_HYPERVISOR_CONFIG";
    break;
  case 0x80370304:
    ans = L"WHV_E_INVALID_PARTITION_CONFIG";
    break;
  case 0x80370305:
    ans = L"WHV_E_GPA_RANGE_NOT_FOUND";
    break;
  case 0x80370306:
    ans = L"WHV_E_VP_ALREADY_EXISTS";
    break;
  case 0x80370307:
    ans = L"WHV_E_VP_DOES_NOT_EXIST";
    break;
  case 0x80370308:
    ans = L"WHV_E_INVALID_VP_STATE";
    break;
  case 0x80370309:
    ans = L"WHV_E_INVALID_VP_REGISTER_NAME";
    break;
  case 0xC0370400:
    ans = L"ERROR_VSMB_SAVED_STATE_FILE_NOT_FOUND";
    break;
  case 0xC0370401:
    ans = L"ERROR_VSMB_SAVED_STATE_CORRUPT";
    break;
  case 0x80380001:
    ans = L"ERROR_VOLMGR_INCOMPLETE_REGENERATION";
    break;
  case 0x80380002:
    ans = L"ERROR_VOLMGR_INCOMPLETE_DISK_MIGRATION";
    break;
  case 0xC0380001:
    ans = L"ERROR_VOLMGR_DATABASE_FULL";
    break;
  case 0xC0380002:
    ans = L"ERROR_VOLMGR_DISK_CONFIGURATION_CORRUPTED";
    break;
  case 0xC0380003:
    ans = L"ERROR_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC";
    break;
  case 0xC0380004:
    ans = L"ERROR_VOLMGR_PACK_CONFIG_UPDATE_FAILED";
    break;
  case 0xC0380005:
    ans = L"ERROR_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME";
    break;
  case 0xC0380006:
    ans = L"ERROR_VOLMGR_DISK_DUPLICATE";
    break;
  case 0xC0380007:
    ans = L"ERROR_VOLMGR_DISK_DYNAMIC";
    break;
  case 0xC0380008:
    ans = L"ERROR_VOLMGR_DISK_ID_INVALID";
    break;
  case 0xC0380009:
    ans = L"ERROR_VOLMGR_DISK_INVALID";
    break;
  case 0xC038000A:
    ans = L"ERROR_VOLMGR_DISK_LAST_VOTER";
    break;
  case 0xC038000B:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_INVALID";
    break;
  case 0xC038000C:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS";
    break;
  case 0xC038000D:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED";
    break;
  case 0xC038000E:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL";
    break;
  case 0xC038000F:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS";
    break;
  case 0xC0380010:
    ans = L"ERROR_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS";
    break;
  case 0xC0380011:
    ans = L"ERROR_VOLMGR_DISK_MISSING";
    break;
  case 0xC0380012:
    ans = L"ERROR_VOLMGR_DISK_NOT_EMPTY";
    break;
  case 0xC0380013:
    ans = L"ERROR_VOLMGR_DISK_NOT_ENOUGH_SPACE";
    break;
  case 0xC0380014:
    ans = L"ERROR_VOLMGR_DISK_REVECTORING_FAILED";
    break;
  case 0xC0380015:
    ans = L"ERROR_VOLMGR_DISK_SECTOR_SIZE_INVALID";
    break;
  case 0xC0380016:
    ans = L"ERROR_VOLMGR_DISK_SET_NOT_CONTAINED";
    break;
  case 0xC0380017:
    ans = L"ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS";
    break;
  case 0xC0380018:
    ans = L"ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES";
    break;
  case 0xC0380019:
    ans = L"ERROR_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED";
    break;
  case 0xC038001A:
    ans = L"ERROR_VOLMGR_EXTENT_ALREADY_USED";
    break;
  case 0xC038001B:
    ans = L"ERROR_VOLMGR_EXTENT_NOT_CONTIGUOUS";
    break;
  case 0xC038001C:
    ans = L"ERROR_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION";
    break;
  case 0xC038001D:
    ans = L"ERROR_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED";
    break;
  case 0xC038001E:
    ans = L"ERROR_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION";
    break;
  case 0xC038001F:
    ans = L"ERROR_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH";
    break;
  case 0xC0380020:
    ans = L"ERROR_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED";
    break;
  case 0xC0380021:
    ans = L"ERROR_VOLMGR_INTERLEAVE_LENGTH_INVALID";
    break;
  case 0xC0380022:
    ans = L"ERROR_VOLMGR_MAXIMUM_REGISTERED_USERS";
    break;
  case 0xC0380023:
    ans = L"ERROR_VOLMGR_MEMBER_IN_SYNC";
    break;
  case 0xC0380024:
    ans = L"ERROR_VOLMGR_MEMBER_INDEX_DUPLICATE";
    break;
  case 0xC0380025:
    ans = L"ERROR_VOLMGR_MEMBER_INDEX_INVALID";
    break;
  case 0xC0380026:
    ans = L"ERROR_VOLMGR_MEMBER_MISSING";
    break;
  case 0xC0380027:
    ans = L"ERROR_VOLMGR_MEMBER_NOT_DETACHED";
    break;
  case 0xC0380028:
    ans = L"ERROR_VOLMGR_MEMBER_REGENERATING";
    break;
  case 0xC0380029:
    ans = L"ERROR_VOLMGR_ALL_DISKS_FAILED";
    break;
  case 0xC038002A:
    ans = L"ERROR_VOLMGR_NO_REGISTERED_USERS";
    break;
  case 0xC038002B:
    ans = L"ERROR_VOLMGR_NO_SUCH_USER";
    break;
  case 0xC038002C:
    ans = L"ERROR_VOLMGR_NOTIFICATION_RESET";
    break;
  case 0xC038002D:
    ans = L"ERROR_VOLMGR_NUMBER_OF_MEMBERS_INVALID";
    break;
  case 0xC038002E:
    ans = L"ERROR_VOLMGR_NUMBER_OF_PLEXES_INVALID";
    break;
  case 0xC038002F:
    ans = L"ERROR_VOLMGR_PACK_DUPLICATE";
    break;
  case 0xC0380030:
    ans = L"ERROR_VOLMGR_PACK_ID_INVALID";
    break;
  case 0xC0380031:
    ans = L"ERROR_VOLMGR_PACK_INVALID";
    break;
  case 0xC0380032:
    ans = L"ERROR_VOLMGR_PACK_NAME_INVALID";
    break;
  case 0xC0380033:
    ans = L"ERROR_VOLMGR_PACK_OFFLINE";
    break;
  case 0xC0380034:
    ans = L"ERROR_VOLMGR_PACK_HAS_QUORUM";
    break;
  case 0xC0380035:
    ans = L"ERROR_VOLMGR_PACK_WITHOUT_QUORUM";
    break;
  case 0xC0380036:
    ans = L"ERROR_VOLMGR_PARTITION_STYLE_INVALID";
    break;
  case 0xC0380037:
    ans = L"ERROR_VOLMGR_PARTITION_UPDATE_FAILED";
    break;
  case 0xC0380038:
    ans = L"ERROR_VOLMGR_PLEX_IN_SYNC";
    break;
  case 0xC0380039:
    ans = L"ERROR_VOLMGR_PLEX_INDEX_DUPLICATE";
    break;
  case 0xC038003A:
    ans = L"ERROR_VOLMGR_PLEX_INDEX_INVALID";
    break;
  case 0xC038003B:
    ans = L"ERROR_VOLMGR_PLEX_LAST_ACTIVE";
    break;
  case 0xC038003C:
    ans = L"ERROR_VOLMGR_PLEX_MISSING";
    break;
  case 0xC038003D:
    ans = L"ERROR_VOLMGR_PLEX_REGENERATING";
    break;
  case 0xC038003E:
    ans = L"ERROR_VOLMGR_PLEX_TYPE_INVALID";
    break;
  case 0xC038003F:
    ans = L"ERROR_VOLMGR_PLEX_NOT_RAID5";
    break;
  case 0xC0380040:
    ans = L"ERROR_VOLMGR_PLEX_NOT_SIMPLE";
    break;
  case 0xC0380041:
    ans = L"ERROR_VOLMGR_STRUCTURE_SIZE_INVALID";
    break;
  case 0xC0380042:
    ans = L"ERROR_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS";
    break;
  case 0xC0380043:
    ans = L"ERROR_VOLMGR_TRANSACTION_IN_PROGRESS";
    break;
  case 0xC0380044:
    ans = L"ERROR_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE";
    break;
  case 0xC0380045:
    ans = L"ERROR_VOLMGR_VOLUME_CONTAINS_MISSING_DISK";
    break;
  case 0xC0380046:
    ans = L"ERROR_VOLMGR_VOLUME_ID_INVALID";
    break;
  case 0xC0380047:
    ans = L"ERROR_VOLMGR_VOLUME_LENGTH_INVALID";
    break;
  case 0xC0380048:
    ans = L"ERROR_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE";
    break;
  case 0xC0380049:
    ans = L"ERROR_VOLMGR_VOLUME_NOT_MIRRORED";
    break;
  case 0xC038004A:
    ans = L"ERROR_VOLMGR_VOLUME_NOT_RETAINED";
    break;
  case 0xC038004B:
    ans = L"ERROR_VOLMGR_VOLUME_OFFLINE";
    break;
  case 0xC038004C:
    ans = L"ERROR_VOLMGR_VOLUME_RETAINED";
    break;
  case 0xC038004D:
    ans = L"ERROR_VOLMGR_NUMBER_OF_EXTENTS_INVALID";
    break;
  case 0xC038004E:
    ans = L"ERROR_VOLMGR_DIFFERENT_SECTOR_SIZE";
    break;
  case 0xC038004F:
    ans = L"ERROR_VOLMGR_BAD_BOOT_DISK";
    break;
  case 0xC0380050:
    ans = L"ERROR_VOLMGR_PACK_CONFIG_OFFLINE";
    break;
  case 0xC0380051:
    ans = L"ERROR_VOLMGR_PACK_CONFIG_ONLINE";
    break;
  case 0xC0380052:
    ans = L"ERROR_VOLMGR_NOT_PRIMARY_PACK";
    break;
  case 0xC0380053:
    ans = L"ERROR_VOLMGR_PACK_LOG_UPDATE_FAILED";
    break;
  case 0xC0380054:
    ans = L"ERROR_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID";
    break;
  case 0xC0380055:
    ans = L"ERROR_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID";
    break;
  case 0xC0380056:
    ans = L"ERROR_VOLMGR_VOLUME_MIRRORED";
    break;
  case 0xC0380057:
    ans = L"ERROR_VOLMGR_PLEX_NOT_SIMPLE_SPANNED";
    break;
  case 0xC0380058:
    ans = L"ERROR_VOLMGR_NO_VALID_LOG_COPIES";
    break;
  case 0xC0380059:
    ans = L"ERROR_VOLMGR_PRIMARY_PACK_PRESENT";
    break;
  case 0xC038005A:
    ans = L"ERROR_VOLMGR_NUMBER_OF_DISKS_INVALID";
    break;
  case 0xC038005B:
    ans = L"ERROR_VOLMGR_MIRROR_NOT_SUPPORTED";
    break;
  case 0xC038005C:
    ans = L"ERROR_VOLMGR_RAID5_NOT_SUPPORTED";
    break;
  case 0x80390001:
    ans = L"ERROR_BCD_NOT_ALL_ENTRIES_IMPORTED";
    break;
  case 0xC0390002:
    ans = L"ERROR_BCD_TOO_MANY_ELEMENTS";
    break;
  case 0x80390003:
    ans = L"ERROR_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED";
    break;
  case 0xC03A0001:
    ans = L"ERROR_VHD_DRIVE_FOOTER_MISSING";
    break;
  case 0xC03A0002:
    ans = L"ERROR_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH";
    break;
  case 0xC03A0003:
    ans = L"ERROR_VHD_DRIVE_FOOTER_CORRUPT";
    break;
  case 0xC03A0004:
    ans = L"ERROR_VHD_FORMAT_UNKNOWN";
    break;
  case 0xC03A0005:
    ans = L"ERROR_VHD_FORMAT_UNSUPPORTED_VERSION";
    break;
  case 0xC03A0006:
    ans = L"ERROR_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH";
    break;
  case 0xC03A0007:
    ans = L"ERROR_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION";
    break;
  case 0xC03A0008:
    ans = L"ERROR_VHD_SPARSE_HEADER_CORRUPT";
    break;
  case 0xC03A0009:
    ans = L"ERROR_VHD_BLOCK_ALLOCATION_FAILURE";
    break;
  case 0xC03A000A:
    ans = L"ERROR_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT";
    break;
  case 0xC03A000B:
    ans = L"ERROR_VHD_INVALID_BLOCK_SIZE";
    break;
  case 0xC03A000C:
    ans = L"ERROR_VHD_BITMAP_MISMATCH";
    break;
  case 0xC03A000D:
    ans = L"ERROR_VHD_PARENT_VHD_NOT_FOUND";
    break;
  case 0xC03A000E:
    ans = L"ERROR_VHD_CHILD_PARENT_ID_MISMATCH";
    break;
  case 0xC03A000F:
    ans = L"ERROR_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH";
    break;
  case 0xC03A0010:
    ans = L"ERROR_VHD_METADATA_READ_FAILURE";
    break;
  case 0xC03A0011:
    ans = L"ERROR_VHD_METADATA_WRITE_FAILURE";
    break;
  case 0xC03A0012:
    ans = L"ERROR_VHD_INVALID_SIZE";
    break;
  case 0xC03A0013:
    ans = L"ERROR_VHD_INVALID_FILE_SIZE";
    break;
  case 0xC03A0014:
    ans = L"ERROR_VIRTDISK_PROVIDER_NOT_FOUND";
    break;
  case 0xC03A0015:
    ans = L"ERROR_VIRTDISK_NOT_VIRTUAL_DISK";
    break;
  case 0xC03A0016:
    ans = L"ERROR_VHD_PARENT_VHD_ACCESS_DENIED";
    break;
  case 0xC03A0017:
    ans = L"ERROR_VHD_CHILD_PARENT_SIZE_MISMATCH";
    break;
  case 0xC03A0018:
    ans = L"ERROR_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED";
    break;
  case 0xC03A0019:
    ans = L"ERROR_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT";
    break;
  case 0xC03A001A:
    ans = L"ERROR_VIRTUAL_DISK_LIMITATION";
    break;
  case 0xC03A001B:
    ans = L"ERROR_VHD_INVALID_TYPE";
    break;
  case 0xC03A001C:
    ans = L"ERROR_VHD_INVALID_STATE";
    break;
  case 0xC03A001D:
    ans = L"ERROR_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE";
    break;
  case 0xC03A001E:
    ans = L"ERROR_VIRTDISK_DISK_ALREADY_OWNED";
    break;
  case 0xC03A001F:
    ans = L"ERROR_VIRTDISK_DISK_ONLINE_AND_WRITABLE";
    break;
  case 0xC03A0020:
    ans = L"ERROR_CTLOG_TRACKING_NOT_INITIALIZED";
    break;
  case 0xC03A0021:
    ans = L"ERROR_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE";
    break;
  case 0xC03A0022:
    ans = L"ERROR_CTLOG_VHD_CHANGED_OFFLINE";
    break;
  case 0xC03A0023:
    ans = L"ERROR_CTLOG_INVALID_TRACKING_STATE";
    break;
  case 0xC03A0024:
    ans = L"ERROR_CTLOG_INCONSISTENT_TRACKING_FILE";
    break;
  case 0xC03A0025:
    ans = L"ERROR_VHD_RESIZE_WOULD_TRUNCATE_DATA";
    break;
  case 0xC03A0026:
    ans = L"ERROR_VHD_COULD_NOT_COMPUTE_MINIMUM_VIRTUAL_SIZE";
    break;
  case 0xC03A0027:
    ans = L"ERROR_VHD_ALREADY_AT_OR_BELOW_MINIMUM_VIRTUAL_SIZE";
    break;
  case 0xC03A0028:
    ans = L"ERROR_VHD_METADATA_FULL";
    break;
  case 0xC03A0029:
    ans = L"ERROR_VHD_INVALID_CHANGE_TRACKING_ID";
    break;
  case 0xC03A002A:
    ans = L"ERROR_VHD_CHANGE_TRACKING_DISABLED";
    break;
  case 0xC03A0030:
    ans = L"ERROR_VHD_MISSING_CHANGE_TRACKING_INFORMATION";
    break;
  case 0x803A0001:
    ans = L"ERROR_QUERY_STORAGE_ERROR";
    break;
  case 0x803B0001:
    ans = L"HCN_E_NETWORK_NOT_FOUND";
    break;
  case 0x803B0002:
    ans = L"HCN_E_ENDPOINT_NOT_FOUND";
    break;
  case 0x803B0003:
    ans = L"HCN_E_LAYER_NOT_FOUND";
    break;
  case 0x803B0004:
    ans = L"HCN_E_SWITCH_NOT_FOUND";
    break;
  case 0x803B0005:
    ans = L"HCN_E_SUBNET_NOT_FOUND";
    break;
  case 0x803B0006:
    ans = L"HCN_E_ADAPTER_NOT_FOUND";
    break;
  case 0x803B0007:
    ans = L"HCN_E_PORT_NOT_FOUND";
    break;
  case 0x803B0008:
    ans = L"HCN_E_POLICY_NOT_FOUND";
    break;
  case 0x803B0009:
    ans = L"HCN_E_VFP_PORTSETTING_NOT_FOUND";
    break;
  case 0x803B000A:
    ans = L"HCN_E_INVALID_NETWORK";
    break;
  case 0x803B000B:
    ans = L"HCN_E_INVALID_NETWORK_TYPE";
    break;
  case 0x803B000C:
    ans = L"HCN_E_INVALID_ENDPOINT";
    break;
  case 0x803B000D:
    ans = L"HCN_E_INVALID_POLICY";
    break;
  case 0x803B000E:
    ans = L"HCN_E_INVALID_POLICY_TYPE";
    break;
  case 0x803B000F:
    ans = L"HCN_E_INVALID_REMOTE_ENDPOINT_OPERATION";
    break;
  case 0x803B0010:
    ans = L"HCN_E_NETWORK_ALREADY_EXISTS";
    break;
  case 0x803B0011:
    ans = L"HCN_E_LAYER_ALREADY_EXISTS";
    break;
  case 0x803B0012:
    ans = L"HCN_E_POLICY_ALREADY_EXISTS";
    break;
  case 0x803B0013:
    ans = L"HCN_E_PORT_ALREADY_EXISTS";
    break;
  case 0x803B0014:
    ans = L"HCN_E_ENDPOINT_ALREADY_ATTACHED";
    break;
  case 0x803B0015:
    ans = L"HCN_E_REQUEST_UNSUPPORTED";
    break;
  case 0x803B0016:
    ans = L"HCN_E_MAPPING_NOT_SUPPORTED";
    break;
  case 0x803B0017:
    ans = L"HCN_E_DEGRADED_OPERATION";
    break;
  case 0x803B0018:
    ans = L"HCN_E_SHARED_SWITCH_MODIFICATION";
    break;
  case 0x803B0019:
    ans = L"HCN_E_GUID_CONVERSION_FAILURE";
    break;
  case 0x803B001A:
    ans = L"HCN_E_REGKEY_FAILURE";
    break;
  case 0x803B001B:
    ans = L"HCN_E_INVALID_JSON";
    break;
  case 0x803B001C:
    ans = L"HCN_E_INVALID_JSON_REFERENCE";
    break;
  case 0x803B001D:
    ans = L"HCN_E_ENDPOINT_SHARING_DISABLED";
    break;
  case 0x803B001E:
    ans = L"HCN_E_INVALID_IP";
    break;
  case 0x803B001F:
    ans = L"HCN_E_SWITCH_EXTENSION_NOT_FOUND";
    break;
  case 0x803B0020:
    ans = L"HCN_E_MANAGER_STOPPED";
    break;
  case 0x803B0021:
    ans = L"GCN_E_MODULE_NOT_FOUND";
    break;
  case 0x803B0022:
    ans = L"GCN_E_NO_REQUEST_HANDLERS";
    break;
  case 0x803B0023:
    ans = L"GCN_E_REQUEST_UNSUPPORTED";
    break;
  case 0x803B0024:
    ans = L"GCN_E_RUNTIMEKEYS_FAILED";
    break;
  case 0x803B0025:
    ans = L"GCN_E_NETADAPTER_TIMEOUT";
    break;
  case 0x803B0026:
    ans = L"GCN_E_NETADAPTER_NOT_FOUND";
    break;
  case 0x803B0027:
    ans = L"GCN_E_NETCOMPARTMENT_NOT_FOUND";
    break;
  case 0x803B0028:
    ans = L"GCN_E_NETINTERFACE_NOT_FOUND";
    break;
  case 0x803B0029:
    ans = L"GCN_E_DEFAULTNAMESPACE_EXISTS";
    break;
  case 0x803C0100:
    ans = L"SDIAG_E_CANCELLED";
    break;
  case 0x803C0101:
    ans = L"SDIAG_E_SCRIPT";
    break;
  case 0x803C0102:
    ans = L"SDIAG_E_POWERSHELL";
    break;
  case 0x803C0103:
    ans = L"SDIAG_E_MANAGEDHOST";
    break;
  case 0x803C0104:
    ans = L"SDIAG_E_NOVERIFIER";
    break;
  case 0x003C0105:
    ans = L"SDIAG_S_CANNOTRUN";
    break;
  case 0x803C0106:
    ans = L"SDIAG_E_DISABLED";
    break;
  case 0x803C0107:
    ans = L"SDIAG_E_TRUST";
    break;
  case 0x803C0108:
    ans = L"SDIAG_E_CANNOTRUN";
    break;
  case 0x803C0109:
    ans = L"SDIAG_E_VERSION";
    break;
  case 0x803C010A:
    ans = L"SDIAG_E_RESOURCE";
    break;
  case 0x803C010B:
    ans = L"SDIAG_E_ROOTCAUSE";
    break;
  case 0x803E0100:
    ans = L"WPN_E_CHANNEL_CLOSED";
    break;
  case 0x803E0101:
    ans = L"WPN_E_CHANNEL_REQUEST_NOT_COMPLETE";
    break;
  case 0x803E0102:
    ans = L"WPN_E_INVALID_APP";
    break;
  case 0x803E0103:
    ans = L"WPN_E_OUTSTANDING_CHANNEL_REQUEST";
    break;
  case 0x803E0104:
    ans = L"WPN_E_DUPLICATE_CHANNEL";
    break;
  case 0x803E0105:
    ans = L"WPN_E_PLATFORM_UNAVAILABLE";
    break;
  case 0x803E0106:
    ans = L"WPN_E_NOTIFICATION_POSTED";
    break;
  case 0x803E0107:
    ans = L"WPN_E_NOTIFICATION_HIDDEN";
    break;
  case 0x803E0108:
    ans = L"WPN_E_NOTIFICATION_NOT_POSTED";
    break;
  case 0x803E0109:
    ans = L"WPN_E_CLOUD_DISABLED";
    break;
  case 0x803E0110:
    ans = L"WPN_E_CLOUD_INCAPABLE";
    break;
  case 0x803E011A:
    ans = L"WPN_E_CLOUD_AUTH_UNAVAILABLE";
    break;
  case 0x803E011B:
    ans = L"WPN_E_CLOUD_SERVICE_UNAVAILABLE";
    break;
  case 0x803E011C:
    ans = L"WPN_E_FAILED_LOCK_SCREEN_UPDATE_INTIALIZATION";
    break;
  case 0x803E0111:
    ans = L"WPN_E_NOTIFICATION_DISABLED";
    break;
  case 0x803E0112:
    ans = L"WPN_E_NOTIFICATION_INCAPABLE";
    break;
  case 0x803E0113:
    ans = L"WPN_E_INTERNET_INCAPABLE";
    break;
  case 0x803E0114:
    ans = L"WPN_E_NOTIFICATION_TYPE_DISABLED";
    break;
  case 0x803E0115:
    ans = L"WPN_E_NOTIFICATION_SIZE";
    break;
  case 0x803E0116:
    ans = L"WPN_E_TAG_SIZE";
    break;
  case 0x803E0117:
    ans = L"WPN_E_ACCESS_DENIED";
    break;
  case 0x803E0118:
    ans = L"WPN_E_DUPLICATE_REGISTRATION";
    break;
  case 0x803E0119:
    ans = L"WPN_E_PUSH_NOTIFICATION_INCAPABLE";
    break;
  case 0x803E0120:
    ans = L"WPN_E_DEV_ID_SIZE";
    break;
  case 0x803E012A:
    ans = L"WPN_E_TAG_ALPHANUMERIC";
    break;
  case 0x803E012B:
    ans = L"WPN_E_INVALID_HTTP_STATUS_CODE";
    break;
  case 0x803E0200:
    ans = L"WPN_E_OUT_OF_SESSION";
    break;
  case 0x803E0201:
    ans = L"WPN_E_POWER_SAVE";
    break;
  case 0x803E0202:
    ans = L"WPN_E_IMAGE_NOT_FOUND_IN_CACHE";
    break;
  case 0x803E0203:
    ans = L"WPN_E_ALL_URL_NOT_COMPLETED";
    break;
  case 0x803E0204:
    ans = L"WPN_E_INVALID_CLOUD_IMAGE";
    break;
  case 0x803E0205:
    ans = L"WPN_E_NOTIFICATION_ID_MATCHED";
    break;
  case 0x803E0206:
    ans = L"WPN_E_CALLBACK_ALREADY_REGISTERED";
    break;
  case 0x803E0207:
    ans = L"WPN_E_TOAST_NOTIFICATION_DROPPED";
    break;
  case 0x803E0208:
    ans = L"WPN_E_STORAGE_LOCKED";
    break;
  case 0x803E0209:
    ans = L"WPN_E_GROUP_SIZE";
    break;
  case 0x803E020A:
    ans = L"WPN_E_GROUP_ALPHANUMERIC";
    break;
  case 0x803E020B:
    ans = L"WPN_E_CLOUD_DISABLED_FOR_APP";
    break;
  case 0x80548201:
    ans = L"E_MBN_CONTEXT_NOT_ACTIVATED";
    break;
  case 0x80548202:
    ans = L"E_MBN_BAD_SIM";
    break;
  case 0x80548203:
    ans = L"E_MBN_DATA_CLASS_NOT_AVAILABLE";
    break;
  case 0x80548204:
    ans = L"E_MBN_INVALID_ACCESS_STRING";
    break;
  case 0x80548205:
    ans = L"E_MBN_MAX_ACTIVATED_CONTEXTS";
    break;
  case 0x80548206:
    ans = L"E_MBN_PACKET_SVC_DETACHED";
    break;
  case 0x80548207:
    ans = L"E_MBN_PROVIDER_NOT_VISIBLE";
    break;
  case 0x80548208:
    ans = L"E_MBN_RADIO_POWER_OFF";
    break;
  case 0x80548209:
    ans = L"E_MBN_SERVICE_NOT_ACTIVATED";
    break;
  case 0x8054820A:
    ans = L"E_MBN_SIM_NOT_INSERTED";
    break;
  case 0x8054820B:
    ans = L"E_MBN_VOICE_CALL_IN_PROGRESS";
    break;
  case 0x8054820C:
    ans = L"E_MBN_INVALID_CACHE";
    break;
  case 0x8054820D:
    ans = L"E_MBN_NOT_REGISTERED";
    break;
  case 0x8054820E:
    ans = L"E_MBN_PROVIDERS_NOT_FOUND";
    break;
  case 0x8054820F:
    ans = L"E_MBN_PIN_NOT_SUPPORTED";
    break;
  case 0x80548210:
    ans = L"E_MBN_PIN_REQUIRED";
    break;
  case 0x80548211:
    ans = L"E_MBN_PIN_DISABLED";
    break;
  case 0x80548212:
    ans = L"E_MBN_FAILURE";
    break;
  case 0x80548218:
    ans = L"E_MBN_INVALID_PROFILE";
    break;
  case 0x80548219:
    ans = L"E_MBN_DEFAULT_PROFILE_EXIST";
    break;
  case 0x80548220:
    ans = L"E_MBN_SMS_ENCODING_NOT_SUPPORTED";
    break;
  case 0x80548221:
    ans = L"E_MBN_SMS_FILTER_NOT_SUPPORTED";
    break;
  case 0x80548222:
    ans = L"E_MBN_SMS_INVALID_MEMORY_INDEX";
    break;
  case 0x80548223:
    ans = L"E_MBN_SMS_LANG_NOT_SUPPORTED";
    break;
  case 0x80548224:
    ans = L"E_MBN_SMS_MEMORY_FAILURE";
    break;
  case 0x80548225:
    ans = L"E_MBN_SMS_NETWORK_TIMEOUT";
    break;
  case 0x80548226:
    ans = L"E_MBN_SMS_UNKNOWN_SMSC_ADDRESS";
    break;
  case 0x80548227:
    ans = L"E_MBN_SMS_FORMAT_NOT_SUPPORTED";
    break;
  case 0x80548228:
    ans = L"E_MBN_SMS_OPERATION_NOT_ALLOWED";
    break;
  case 0x80548229:
    ans = L"E_MBN_SMS_MEMORY_FULL";
    break;
  case 0x80630001:
    ans = L"PEER_E_IPV6_NOT_INSTALLED";
    break;
  case 0x80630002:
    ans = L"PEER_E_NOT_INITIALIZED";
    break;
  case 0x80630003:
    ans = L"PEER_E_CANNOT_START_SERVICE";
    break;
  case 0x80630004:
    ans = L"PEER_E_NOT_LICENSED";
    break;
  case 0x80630010:
    ans = L"PEER_E_INVALID_GRAPH";
    break;
  case 0x80630011:
    ans = L"PEER_E_DBNAME_CHANGED";
    break;
  case 0x80630012:
    ans = L"PEER_E_DUPLICATE_GRAPH";
    break;
  case 0x80630013:
    ans = L"PEER_E_GRAPH_NOT_READY";
    break;
  case 0x80630014:
    ans = L"PEER_E_GRAPH_SHUTTING_DOWN";
    break;
  case 0x80630015:
    ans = L"PEER_E_GRAPH_IN_USE";
    break;
  case 0x80630016:
    ans = L"PEER_E_INVALID_DATABASE";
    break;
  case 0x80630017:
    ans = L"PEER_E_TOO_MANY_ATTRIBUTES";
    break;
  case 0x80630103:
    ans = L"PEER_E_CONNECTION_NOT_FOUND";
    break;
  case 0x80630106:
    ans = L"PEER_E_CONNECT_SELF";
    break;
  case 0x80630107:
    ans = L"PEER_E_ALREADY_LISTENING";
    break;
  case 0x80630108:
    ans = L"PEER_E_NODE_NOT_FOUND";
    break;
  case 0x80630109:
    ans = L"PEER_E_CONNECTION_FAILED";
    break;
  case 0x8063010A:
    ans = L"PEER_E_CONNECTION_NOT_AUTHENTICATED";
    break;
  case 0x8063010B:
    ans = L"PEER_E_CONNECTION_REFUSED";
    break;
  case 0x80630201:
    ans = L"PEER_E_CLASSIFIER_TOO_LONG";
    break;
  case 0x80630202:
    ans = L"PEER_E_TOO_MANY_IDENTITIES";
    break;
  case 0x80630203:
    ans = L"PEER_E_NO_KEY_ACCESS";
    break;
  case 0x80630204:
    ans = L"PEER_E_GROUPS_EXIST";
    break;
  case 0x80630301:
    ans = L"PEER_E_RECORD_NOT_FOUND";
    break;
  case 0x80630302:
    ans = L"PEER_E_DATABASE_ACCESSDENIED";
    break;
  case 0x80630303:
    ans = L"PEER_E_DBINITIALIZATION_FAILED";
    break;
  case 0x80630304:
    ans = L"PEER_E_MAX_RECORD_SIZE_EXCEEDED";
    break;
  case 0x80630305:
    ans = L"PEER_E_DATABASE_ALREADY_PRESENT";
    break;
  case 0x80630306:
    ans = L"PEER_E_DATABASE_NOT_PRESENT";
    break;
  case 0x80630401:
    ans = L"PEER_E_IDENTITY_NOT_FOUND";
    break;
  case 0x80630501:
    ans = L"PEER_E_EVENT_HANDLE_NOT_FOUND";
    break;
  case 0x80630601:
    ans = L"PEER_E_INVALID_SEARCH";
    break;
  case 0x80630602:
    ans = L"PEER_E_INVALID_ATTRIBUTES";
    break;
  case 0x80630701:
    ans = L"PEER_E_INVITATION_NOT_TRUSTED";
    break;
  case 0x80630703:
    ans = L"PEER_E_CHAIN_TOO_LONG";
    break;
  case 0x80630705:
    ans = L"PEER_E_INVALID_TIME_PERIOD";
    break;
  case 0x80630706:
    ans = L"PEER_E_CIRCULAR_CHAIN_DETECTED";
    break;
  case 0x80630801:
    ans = L"PEER_E_CERT_STORE_CORRUPTED";
    break;
  case 0x80631001:
    ans = L"PEER_E_NO_CLOUD";
    break;
  case 0x80631005:
    ans = L"PEER_E_CLOUD_NAME_AMBIGUOUS";
    break;
  case 0x80632010:
    ans = L"PEER_E_INVALID_RECORD";
    break;
  case 0x80632020:
    ans = L"PEER_E_NOT_AUTHORIZED";
    break;
  case 0x80632021:
    ans = L"PEER_E_PASSWORD_DOES_NOT_MEET_POLICY";
    break;
  case 0x80632030:
    ans = L"PEER_E_DEFERRED_VALIDATION";
    break;
  case 0x80632040:
    ans = L"PEER_E_INVALID_GROUP_PROPERTIES";
    break;
  case 0x80632050:
    ans = L"PEER_E_INVALID_PEER_NAME";
    break;
  case 0x80632060:
    ans = L"PEER_E_INVALID_CLASSIFIER";
    break;
  case 0x80632070:
    ans = L"PEER_E_INVALID_FRIENDLY_NAME";
    break;
  case 0x80632071:
    ans = L"PEER_E_INVALID_ROLE_PROPERTY";
    break;
  case 0x80632072:
    ans = L"PEER_E_INVALID_CLASSIFIER_PROPERTY";
    break;
  case 0x80632080:
    ans = L"PEER_E_INVALID_RECORD_EXPIRATION";
    break;
  case 0x80632081:
    ans = L"PEER_E_INVALID_CREDENTIAL_INFO";
    break;
  case 0x80632082:
    ans = L"PEER_E_INVALID_CREDENTIAL";
    break;
  case 0x80632083:
    ans = L"PEER_E_INVALID_RECORD_SIZE";
    break;
  case 0x80632090:
    ans = L"PEER_E_UNSUPPORTED_VERSION";
    break;
  case 0x80632091:
    ans = L"PEER_E_GROUP_NOT_READY";
    break;
  case 0x80632092:
    ans = L"PEER_E_GROUP_IN_USE";
    break;
  case 0x80632093:
    ans = L"PEER_E_INVALID_GROUP";
    break;
  case 0x80632094:
    ans = L"PEER_E_NO_MEMBERS_FOUND";
    break;
  case 0x80632095:
    ans = L"PEER_E_NO_MEMBER_CONNECTIONS";
    break;
  case 0x80632096:
    ans = L"PEER_E_UNABLE_TO_LISTEN";
    break;
  case 0x806320A0:
    ans = L"PEER_E_IDENTITY_DELETED";
    break;
  case 0x806320A1:
    ans = L"PEER_E_SERVICE_NOT_AVAILABLE";
    break;
  case 0x80636001:
    ans = L"PEER_E_CONTACT_NOT_FOUND";
    break;
  case 0x00630001:
    ans = L"PEER_S_GRAPH_DATA_CREATED";
    break;
  case 0x00630002:
    ans = L"PEER_S_NO_EVENT_DATA";
    break;
  case 0x00632000:
    ans = L"PEER_S_ALREADY_CONNECTED";
    break;
  case 0x00636000:
    ans = L"PEER_S_SUBSCRIPTION_EXISTS";
    break;
  case 0x00630005:
    ans = L"PEER_S_NO_CONNECTIVITY";
    break;
  case 0x00630006:
    ans = L"PEER_S_ALREADY_A_MEMBER";
    break;
  case 0x80634001:
    ans = L"PEER_E_CANNOT_CONVERT_PEER_NAME";
    break;
  case 0x80634002:
    ans = L"PEER_E_INVALID_PEER_HOST_NAME";
    break;
  case 0x80634003:
    ans = L"PEER_E_NO_MORE";
    break;
  case 0x80634005:
    ans = L"PEER_E_PNRP_DUPLICATE_PEER_NAME";
    break;
  case 0x80637000:
    ans = L"PEER_E_INVITE_CANCELLED";
    break;
  case 0x80637001:
    ans = L"PEER_E_INVITE_RESPONSE_NOT_AVAILABLE";
    break;
  case 0x80637003:
    ans = L"PEER_E_NOT_SIGNED_IN";
    break;
  case 0x80637004:
    ans = L"PEER_E_PRIVACY_DECLINED";
    break;
  case 0x80637005:
    ans = L"PEER_E_TIMEOUT";
    break;
  case 0x80637007:
    ans = L"PEER_E_INVALID_ADDRESS";
    break;
  case 0x80637008:
    ans = L"PEER_E_FW_EXCEPTION_DISABLED";
    break;
  case 0x80637009:
    ans = L"PEER_E_FW_BLOCKED_BY_POLICY";
    break;
  case 0x8063700A:
    ans = L"PEER_E_FW_BLOCKED_BY_SHIELDS_UP";
    break;
  case 0x8063700B:
    ans = L"PEER_E_FW_DECLINED";
    break;
  case 0x802A0001:
    ans = L"UI_E_CREATE_FAILED";
    break;
  case 0x802A0002:
    ans = L"UI_E_SHUTDOWN_CALLED";
    break;
  case 0x802A0003:
    ans = L"UI_E_ILLEGAL_REENTRANCY";
    break;
  case 0x802A0004:
    ans = L"UI_E_OBJECT_SEALED";
    break;
  case 0x802A0005:
    ans = L"UI_E_VALUE_NOT_SET";
    break;
  case 0x802A0006:
    ans = L"UI_E_VALUE_NOT_DETERMINED";
    break;
  case 0x802A0007:
    ans = L"UI_E_INVALID_OUTPUT";
    break;
  case 0x802A0008:
    ans = L"UI_E_BOOLEAN_EXPECTED";
    break;
  case 0x802A0009:
    ans = L"UI_E_DIFFERENT_OWNER";
    break;
  case 0x802A000A:
    ans = L"UI_E_AMBIGUOUS_MATCH";
    break;
  case 0x802A000B:
    ans = L"UI_E_FP_OVERFLOW";
    break;
  case 0x802A000C:
    ans = L"UI_E_WRONG_THREAD";
    break;
  case 0x802A0101:
    ans = L"UI_E_STORYBOARD_ACTIVE";
    break;
  case 0x802A0102:
    ans = L"UI_E_STORYBOARD_NOT_PLAYING";
    break;
  case 0x802A0103:
    ans = L"UI_E_START_KEYFRAME_AFTER_END";
    break;
  case 0x802A0104:
    ans = L"UI_E_END_KEYFRAME_NOT_DETERMINED";
    break;
  case 0x802A0105:
    ans = L"UI_E_LOOPS_OVERLAP";
    break;
  case 0x802A0106:
    ans = L"UI_E_TRANSITION_ALREADY_USED";
    break;
  case 0x802A0107:
    ans = L"UI_E_TRANSITION_NOT_IN_STORYBOARD";
    break;
  case 0x802A0108:
    ans = L"UI_E_TRANSITION_ECLIPSED";
    break;
  case 0x802A0109:
    ans = L"UI_E_TIME_BEFORE_LAST_UPDATE";
    break;
  case 0x802A010A:
    ans = L"UI_E_TIMER_CLIENT_ALREADY_CONNECTED";
    break;
  case 0x802A010B:
    ans = L"UI_E_INVALID_DIMENSION";
    break;
  case 0x802A010C:
    ans = L"UI_E_PRIMITIVE_OUT_OF_BOUNDS";
    break;
  case 0x802A0201:
    ans = L"UI_E_WINDOW_CLOSED";
    break;
  case 0x80650001:
    ans = L"E_BLUETOOTH_ATT_INVALID_HANDLE";
    break;
  case 0x80650002:
    ans = L"E_BLUETOOTH_ATT_READ_NOT_PERMITTED";
    break;
  case 0x80650003:
    ans = L"E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED";
    break;
  case 0x80650004:
    ans = L"E_BLUETOOTH_ATT_INVALID_PDU";
    break;
  case 0x80650005:
    ans = L"E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION";
    break;
  case 0x80650006:
    ans = L"E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED";
    break;
  case 0x80650007:
    ans = L"E_BLUETOOTH_ATT_INVALID_OFFSET";
    break;
  case 0x80650008:
    ans = L"E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION";
    break;
  case 0x80650009:
    ans = L"E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL";
    break;
  case 0x8065000A:
    ans = L"E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND";
    break;
  case 0x8065000B:
    ans = L"E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG";
    break;
  case 0x8065000C:
    ans = L"E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE";
    break;
  case 0x8065000D:
    ans = L"E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH";
    break;
  case 0x8065000E:
    ans = L"E_BLUETOOTH_ATT_UNLIKELY";
    break;
  case 0x8065000F:
    ans = L"E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION";
    break;
  case 0x80650010:
    ans = L"E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE";
    break;
  case 0x80650011:
    ans = L"E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES";
    break;
  case 0x80651000:
    ans = L"E_BLUETOOTH_ATT_UNKNOWN_ERROR";
    break;
  case 0x80660001:
    ans = L"E_AUDIO_ENGINE_NODE_NOT_FOUND";
    break;
  case 0x80660002:
    ans = L"E_HDAUDIO_EMPTY_CONNECTION_LIST";
    break;
  case 0x80660003:
    ans = L"E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED";
    break;
  case 0x80660004:
    ans = L"E_HDAUDIO_NO_LOGICAL_DEVICES_CREATED";
    break;
  case 0x80660005:
    ans = L"E_HDAUDIO_NULL_LINKED_LIST_ENTRY";
    break;
  case 0x80670001:
    ans = L"STATEREPOSITORY_E_CONCURRENCY_LOCKING_FAILURE";
    break;
  case 0x80670002:
    ans = L"STATEREPOSITORY_E_STATEMENT_INPROGRESS";
    break;
  case 0x80670003:
    ans = L"STATEREPOSITORY_E_CONFIGURATION_INVALID";
    break;
  case 0x80670004:
    ans = L"STATEREPOSITORY_E_UNKNOWN_SCHEMA_VERSION";
    break;
  case 0x80670005:
    ans = L"STATEREPOSITORY_ERROR_DICTIONARY_CORRUPTED";
    break;
  case 0x80670006:
    ans = L"STATEREPOSITORY_E_BLOCKED";
    break;
  case 0x80670007:
    ans = L"STATEREPOSITORY_E_BUSY_RETRY";
    break;
  case 0x80670008:
    ans = L"STATEREPOSITORY_E_BUSY_RECOVERY_RETRY";
    break;
  case 0x80670009:
    ans = L"STATEREPOSITORY_E_LOCKED_RETRY";
    break;
  case 0x8067000A:
    ans = L"STATEREPOSITORY_E_LOCKED_SHAREDCACHE_RETRY";
    break;
  case 0x8067000B:
    ans = L"STATEREPOSITORY_E_TRANSACTION_REQUIRED";
    break;
  case 0x8067000C:
    ans = L"STATEREPOSITORY_E_BUSY_TIMEOUT_EXCEEDED";
    break;
  case 0x8067000D:
    ans = L"STATEREPOSITORY_E_BUSY_RECOVERY_TIMEOUT_EXCEEDED";
    break;
  case 0x8067000E:
    ans = L"STATEREPOSITORY_E_LOCKED_TIMEOUT_EXCEEDED";
    break;
  case 0x8067000F:
    ans = L"STATEREPOSITORY_E_LOCKED_SHAREDCACHE_TIMEOUT_EXCEEDED";
    break;
  case 0x80670010:
    ans = L"STATEREPOSITORY_E_SERVICE_STOP_IN_PROGRESS";
    break;
  case 0x80670011:
    ans = L"STATEREPOSTORY_E_NESTED_TRANSACTION_NOT_SUPPORTED";
    break;
  case 0x80670012:
    ans = L"STATEREPOSITORY_ERROR_CACHE_CORRUPTED";
    break;
  case 0x00670013:
    ans = L"STATEREPOSITORY_TRANSACTION_CALLER_ID_CHANGED";
    break;
  case 0x00670014:
    ans = L"STATEREPOSITORY_TRANSACTION_IN_PROGRESS";
    break;
  case 0x00E70001:
    ans = L"ERROR_SPACES_POOL_WAS_DELETED";
    break;
  case 0x80E70001:
    ans = L"ERROR_SPACES_FAULT_DOMAIN_TYPE_INVALID";
    break;
  case 0x80E70002:
    ans = L"ERROR_SPACES_INTERNAL_ERROR";
    break;
  case 0x80E70003:
    ans = L"ERROR_SPACES_RESILIENCY_TYPE_INVALID";
    break;
  case 0x80E70004:
    ans = L"ERROR_SPACES_DRIVE_SECTOR_SIZE_INVALID";
    break;
  case 0x80E70006:
    ans = L"ERROR_SPACES_DRIVE_REDUNDANCY_INVALID";
    break;
  case 0x80E70007:
    ans = L"ERROR_SPACES_NUMBER_OF_DATA_COPIES_INVALID";
    break;
  case 0x80E70008:
    ans = L"ERROR_SPACES_PARITY_LAYOUT_INVALID";
    break;
  case 0x80E70009:
    ans = L"ERROR_SPACES_INTERLEAVE_LENGTH_INVALID";
    break;
  case 0x80E7000A:
    ans = L"ERROR_SPACES_NUMBER_OF_COLUMNS_INVALID";
    break;
  case 0x80E7000B:
    ans = L"ERROR_SPACES_NOT_ENOUGH_DRIVES";
    break;
  case 0x80E7000C:
    ans = L"ERROR_SPACES_EXTENDED_ERROR";
    break;
  case 0x80E7000D:
    ans = L"ERROR_SPACES_PROVISIONING_TYPE_INVALID";
    break;
  case 0x80E7000E:
    ans = L"ERROR_SPACES_ALLOCATION_SIZE_INVALID";
    break;
  case 0x80E7000F:
    ans = L"ERROR_SPACES_ENCLOSURE_AWARE_INVALID";
    break;
  case 0x80E70010:
    ans = L"ERROR_SPACES_WRITE_CACHE_SIZE_INVALID";
    break;
  case 0x80E70011:
    ans = L"ERROR_SPACES_NUMBER_OF_GROUPS_INVALID";
    break;
  case 0x80E70012:
    ans = L"ERROR_SPACES_DRIVE_OPERATIONAL_STATE_INVALID";
    break;
  case 0x80E70013:
    ans = L"ERROR_SPACES_ENTRY_INCOMPLETE";
    break;
  case 0x80E70014:
    ans = L"ERROR_SPACES_ENTRY_INVALID";
    break;
  case 0x80820001:
    ans = L"ERROR_VOLSNAP_BOOTFILE_NOT_VALID";
    break;
  case 0x80820002:
    ans = L"ERROR_VOLSNAP_ACTIVATION_TIMEOUT";
    break;
  case 0x80830001:
    ans = L"ERROR_TIERING_NOT_SUPPORTED_ON_VOLUME";
    break;
  case 0x80830002:
    ans = L"ERROR_TIERING_VOLUME_DISMOUNT_IN_PROGRESS";
    break;
  case 0x80830003:
    ans = L"ERROR_TIERING_STORAGE_TIER_NOT_FOUND";
    break;
  case 0x80830004:
    ans = L"ERROR_TIERING_INVALID_FILE_ID";
    break;
  case 0x80830005:
    ans = L"ERROR_TIERING_WRONG_CLUSTER_NODE";
    break;
  case 0x80830006:
    ans = L"ERROR_TIERING_ALREADY_PROCESSING";
    break;
  case 0x80830007:
    ans = L"ERROR_TIERING_CANNOT_PIN_OBJECT";
    break;
  case 0x80830008:
    ans = L"ERROR_TIERING_FILE_IS_NOT_PINNED";
    break;
  case 0x80830009:
    ans = L"ERROR_NOT_A_TIERED_VOLUME";
    break;
  case 0x8083000A:
    ans = L"ERROR_ATTRIBUTE_NOT_PRESENT";
    break;
  case 0xC0E80000:
    ans = L"ERROR_SECCORE_INVALID_COMMAND";
    break;
  case 0xC0EA0001:
    ans = L"ERROR_NO_APPLICABLE_APP_LICENSES_FOUND";
    break;
  case 0xC0EA0002:
    ans = L"ERROR_CLIP_LICENSE_NOT_FOUND";
    break;
  case 0xC0EA0003:
    ans = L"ERROR_CLIP_DEVICE_LICENSE_MISSING";
    break;
  case 0xC0EA0004:
    ans = L"ERROR_CLIP_LICENSE_INVALID_SIGNATURE";
    break;
  case 0xC0EA0005:
    ans = L"ERROR_CLIP_KEYHOLDER_LICENSE_MISSING_OR_INVALID";
    break;
  case 0xC0EA0006:
    ans = L"ERROR_CLIP_LICENSE_EXPIRED";
    break;
  case 0xC0EA0007:
    ans = L"ERROR_CLIP_LICENSE_SIGNED_BY_UNKNOWN_SOURCE";
    break;
  case 0xC0EA0008:
    ans = L"ERROR_CLIP_LICENSE_NOT_SIGNED";
    break;
  case 0xC0EA0009:
    ans = L"ERROR_CLIP_LICENSE_HARDWARE_ID_OUT_OF_TOLERANCE";
    break;
  case 0xC0EA000A:
    ans = L"ERROR_CLIP_LICENSE_DEVICE_ID_MISMATCH";
    break;
  case 0x087A0001:
    ans = L"DXGI_STATUS_OCCLUDED";
    break;
  case 0x087A0002:
    ans = L"DXGI_STATUS_CLIPPED";
    break;
  case 0x087A0004:
    ans = L"DXGI_STATUS_NO_REDIRECTION";
    break;
  case 0x087A0005:
    ans = L"DXGI_STATUS_NO_DESKTOP_ACCESS";
    break;
  case 0x087A0006:
    ans = L"DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE";
    break;
  case 0x087A0007:
    ans = L"DXGI_STATUS_MODE_CHANGED";
    break;
  case 0x087A0008:
    ans = L"DXGI_STATUS_MODE_CHANGE_IN_PROGRESS";
    break;
  case 0x887A0001:
    ans = L"DXGI_ERROR_INVALID_CALL";
    break;
  case 0x887A0002:
    ans = L"DXGI_ERROR_NOT_FOUND";
    break;
  case 0x887A0003:
    ans = L"DXGI_ERROR_MORE_DATA";
    break;
  case 0x887A0004:
    ans = L"DXGI_ERROR_UNSUPPORTED";
    break;
  case 0x887A0005:
    ans = L"DXGI_ERROR_DEVICE_REMOVED";
    break;
  case 0x887A0006:
    ans = L"DXGI_ERROR_DEVICE_HUNG";
    break;
  case 0x887A0007:
    ans = L"DXGI_ERROR_DEVICE_RESET";
    break;
  case 0x887A000A:
    ans = L"DXGI_ERROR_WAS_STILL_DRAWING";
    break;
  case 0x887A000B:
    ans = L"DXGI_ERROR_FRAME_STATISTICS_DISJOINT";
    break;
  case 0x887A000C:
    ans = L"DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE";
    break;
  case 0x887A0020:
    ans = L"DXGI_ERROR_DRIVER_INTERNAL_ERROR";
    break;
  case 0x887A0021:
    ans = L"DXGI_ERROR_NONEXCLUSIVE";
    break;
  case 0x887A0022:
    ans = L"DXGI_ERROR_NOT_CURRENTLY_AVAILABLE";
    break;
  case 0x887A0023:
    ans = L"DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED";
    break;
  case 0x887A0024:
    ans = L"DXGI_ERROR_REMOTE_OUTOFMEMORY";
    break;
  case 0x887A0026:
    ans = L"DXGI_ERROR_ACCESS_LOST";
    break;
  case 0x887A0027:
    ans = L"DXGI_ERROR_WAIT_TIMEOUT";
    break;
  case 0x887A0028:
    ans = L"DXGI_ERROR_SESSION_DISCONNECTED";
    break;
  case 0x887A0029:
    ans = L"DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE";
    break;
  case 0x887A002A:
    ans = L"DXGI_ERROR_CANNOT_PROTECT_CONTENT";
    break;
  case 0x887A002B:
    ans = L"DXGI_ERROR_ACCESS_DENIED";
    break;
  case 0x887A002C:
    ans = L"DXGI_ERROR_NAME_ALREADY_EXISTS";
    break;
  case 0x887A002D:
    ans = L"DXGI_ERROR_SDK_COMPONENT_MISSING";
    break;
  case 0x887A002E:
    ans = L"DXGI_ERROR_NOT_CURRENT";
    break;
  case 0x887A0030:
    ans = L"DXGI_ERROR_HW_PROTECTION_OUTOFMEMORY";
    break;
  case 0x887A0031:
    ans = L"DXGI_ERROR_DYNAMIC_CODE_POLICY_VIOLATION";
    break;
  case 0x887A0032:
    ans = L"DXGI_ERROR_NON_COMPOSITED_UI";
    break;
  case 0x087A0009:
    ans = L"DXGI_STATUS_UNOCCLUDED";
    break;
  case 0x087A000A:
    ans = L"DXGI_STATUS_DDA_WAS_STILL_DRAWING";
    break;
  case 0x887A0025:
    ans = L"DXGI_ERROR_MODE_CHANGE_IN_PROGRESS";
    break;
  case 0x087A002F:
    ans = L"DXGI_STATUS_PRESENT_REQUIRED";
    break;
  case 0x887A0033:
    ans = L"DXGI_ERROR_CACHE_CORRUPT";
    break;
  case 0x887A0034:
    ans = L"DXGI_ERROR_CACHE_FULL";
    break;
  case 0x887A0035:
    ans = L"DXGI_ERROR_CACHE_HASH_COLLISION";
    break;
  case 0x887A0036:
    ans = L"DXGI_ERROR_ALREADY_EXISTS";
    break;
  case 0x887B0001:
    ans = L"DXGI_DDI_ERR_WASSTILLDRAWING";
    break;
  case 0x887B0002:
    ans = L"DXGI_DDI_ERR_UNSUPPORTED";
    break;
  case 0x887B0003:
    ans = L"DXGI_DDI_ERR_NONEXCLUSIVE";
    break;
  case 0x88790001:
    ans = L"D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS";
    break;
  case 0x88790002:
    ans = L"D3D10_ERROR_FILE_NOT_FOUND";
    break;
  case 0x887C0001:
    ans = L"D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS";
    break;
  case 0x887C0002:
    ans = L"D3D11_ERROR_FILE_NOT_FOUND";
    break;
  case 0x887C0003:
    ans = L"D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS";
    break;
  case 0x887C0004:
    ans = L"D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD";
    break;
  case 0x887E0001:
    ans = L"D3D12_ERROR_ADAPTER_NOT_FOUND";
    break;
  case 0x887E0002:
    ans = L"D3D12_ERROR_DRIVER_VERSION_MISMATCH";
    break;
  case 0x88990001:
    ans = L"D2DERR_WRONG_STATE";
    break;
  case 0x88990002:
    ans = L"D2DERR_NOT_INITIALIZED";
    break;
  case 0x88990003:
    ans = L"D2DERR_UNSUPPORTED_OPERATION";
    break;
  case 0x88990004:
    ans = L"D2DERR_SCANNER_FAILED";
    break;
  case 0x88990005:
    ans = L"D2DERR_SCREEN_ACCESS_DENIED";
    break;
  case 0x88990006:
    ans = L"D2DERR_DISPLAY_STATE_INVALID";
    break;
  case 0x88990007:
    ans = L"D2DERR_ZERO_VECTOR";
    break;
  case 0x88990008:
    ans = L"D2DERR_INTERNAL_ERROR";
    break;
  case 0x88990009:
    ans = L"D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED";
    break;
  case 0x8899000A:
    ans = L"D2DERR_INVALID_CALL";
    break;
  case 0x8899000B:
    ans = L"D2DERR_NO_HARDWARE_DEVICE";
    break;
  case 0x8899000C:
    ans = L"D2DERR_RECREATE_TARGET";
    break;
  case 0x8899000D:
    ans = L"D2DERR_TOO_MANY_SHADER_ELEMENTS";
    break;
  case 0x8899000E:
    ans = L"D2DERR_SHADER_COMPILE_FAILED";
    break;
  case 0x8899000F:
    ans = L"D2DERR_MAX_TEXTURE_SIZE_EXCEEDED";
    break;
  case 0x88990010:
    ans = L"D2DERR_UNSUPPORTED_VERSION";
    break;
  case 0x88990011:
    ans = L"D2DERR_BAD_NUMBER";
    break;
  case 0x88990012:
    ans = L"D2DERR_WRONG_FACTORY";
    break;
  case 0x88990013:
    ans = L"D2DERR_LAYER_ALREADY_IN_USE";
    break;
  case 0x88990014:
    ans = L"D2DERR_POP_CALL_DID_NOT_MATCH_PUSH";
    break;
  case 0x88990015:
    ans = L"D2DERR_WRONG_RESOURCE_DOMAIN";
    break;
  case 0x88990016:
    ans = L"D2DERR_PUSH_POP_UNBALANCED";
    break;
  case 0x88990017:
    ans = L"D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT";
    break;
  case 0x88990018:
    ans = L"D2DERR_INCOMPATIBLE_BRUSH_TYPES";
    break;
  case 0x88990019:
    ans = L"D2DERR_WIN32_ERROR";
    break;
  case 0x8899001A:
    ans = L"D2DERR_TARGET_NOT_GDI_COMPATIBLE";
    break;
  case 0x8899001B:
    ans = L"D2DERR_TEXT_EFFECT_IS_WRONG_TYPE";
    break;
  case 0x8899001C:
    ans = L"D2DERR_TEXT_RENDERER_NOT_RELEASED";
    break;
  case 0x8899001D:
    ans = L"D2DERR_EXCEEDS_MAX_BITMAP_SIZE";
    break;
  case 0x8899001E:
    ans = L"D2DERR_INVALID_GRAPH_CONFIGURATION";
    break;
  case 0x8899001F:
    ans = L"D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION";
    break;
  case 0x88990020:
    ans = L"D2DERR_CYCLIC_GRAPH";
    break;
  case 0x88990021:
    ans = L"D2DERR_BITMAP_CANNOT_DRAW";
    break;
  case 0x88990022:
    ans = L"D2DERR_OUTSTANDING_BITMAP_REFERENCES";
    break;
  case 0x88990023:
    ans = L"D2DERR_ORIGINAL_TARGET_NOT_BOUND";
    break;
  case 0x88990024:
    ans = L"D2DERR_INVALID_TARGET";
    break;
  case 0x88990025:
    ans = L"D2DERR_BITMAP_BOUND_AS_TARGET";
    break;
  case 0x88990026:
    ans = L"D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES";
    break;
  case 0x88990027:
    ans = L"D2DERR_INTERMEDIATE_TOO_LARGE";
    break;
  case 0x88990028:
    ans = L"D2DERR_EFFECT_IS_NOT_REGISTERED";
    break;
  case 0x88990029:
    ans = L"D2DERR_INVALID_PROPERTY";
    break;
  case 0x8899002A:
    ans = L"D2DERR_NO_SUBPROPERTIES";
    break;
  case 0x8899002B:
    ans = L"D2DERR_PRINT_JOB_CLOSED";
    break;
  case 0x8899002C:
    ans = L"D2DERR_PRINT_FORMAT_NOT_SUPPORTED";
    break;
  case 0x8899002D:
    ans = L"D2DERR_TOO_MANY_TRANSFORM_INPUTS";
    break;
  case 0x8899002E:
    ans = L"D2DERR_INVALID_GLYPH_IMAGE";
    break;
  case 0x88985000:
    ans = L"DWRITE_E_FILEFORMAT";
    break;
  case 0x88985001:
    ans = L"DWRITE_E_UNEXPECTED";
    break;
  case 0x88985002:
    ans = L"DWRITE_E_NOFONT";
    break;
  case 0x88985003:
    ans = L"DWRITE_E_FILENOTFOUND";
    break;
  case 0x88985004:
    ans = L"DWRITE_E_FILEACCESS";
    break;
  case 0x88985005:
    ans = L"DWRITE_E_FONTCOLLECTIONOBSOLETE";
    break;
  case 0x88985006:
    ans = L"DWRITE_E_ALREADYREGISTERED";
    break;
  case 0x88985007:
    ans = L"DWRITE_E_CACHEFORMAT";
    break;
  case 0x88985008:
    ans = L"DWRITE_E_CACHEVERSION";
    break;
  case 0x88985009:
    ans = L"DWRITE_E_UNSUPPORTEDOPERATION";
    break;
  case 0x8898500A:
    ans = L"DWRITE_E_TEXTRENDERERINCOMPATIBLE";
    break;
  case 0x8898500B:
    ans = L"DWRITE_E_FLOWDIRECTIONCONFLICTS";
    break;
  case 0x8898500C:
    ans = L"DWRITE_E_NOCOLOR";
    break;
  case 0x8898500D:
    ans = L"DWRITE_E_REMOTEFONT";
    break;
  case 0x8898500E:
    ans = L"DWRITE_E_DOWNLOADCANCELLED";
    break;
  case 0x8898500F:
    ans = L"DWRITE_E_DOWNLOADFAILED";
    break;
  case 0x88985010:
    ans = L"DWRITE_E_TOOMANYDOWNLOADS";
    break;
  case 0x88982F04:
    ans = L"WINCODEC_ERR_WRONGSTATE";
    break;
  case 0x88982F05:
    ans = L"WINCODEC_ERR_VALUEOUTOFRANGE";
    break;
  case 0x88982F07:
    ans = L"WINCODEC_ERR_UNKNOWNIMAGEFORMAT";
    break;
  case 0x88982F0B:
    ans = L"WINCODEC_ERR_UNSUPPORTEDVERSION";
    break;
  case 0x88982F0C:
    ans = L"WINCODEC_ERR_NOTINITIALIZED";
    break;
  case 0x88982F0D:
    ans = L"WINCODEC_ERR_ALREADYLOCKED";
    break;
  case 0x88982F40:
    ans = L"WINCODEC_ERR_PROPERTYNOTFOUND";
    break;
  case 0x88982F41:
    ans = L"WINCODEC_ERR_PROPERTYNOTSUPPORTED";
    break;
  case 0x88982F42:
    ans = L"WINCODEC_ERR_PROPERTYSIZE";
    break;
  case 0x88982F43:
    ans = L"WINCODEC_ERR_CODECPRESENT";
    break;
  case 0x88982F44:
    ans = L"WINCODEC_ERR_CODECNOTHUMBNAIL";
    break;
  case 0x88982F45:
    ans = L"WINCODEC_ERR_PALETTEUNAVAILABLE";
    break;
  case 0x88982F46:
    ans = L"WINCODEC_ERR_CODECTOOMANYSCANLINES";
    break;
  case 0x88982F48:
    ans = L"WINCODEC_ERR_INTERNALERROR";
    break;
  case 0x88982F49:
    ans = L"WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS";
    break;
  case 0x88982F50:
    ans = L"WINCODEC_ERR_COMPONENTNOTFOUND";
    break;
  case 0x88982F51:
    ans = L"WINCODEC_ERR_IMAGESIZEOUTOFRANGE";
    break;
  case 0x88982F52:
    ans = L"WINCODEC_ERR_TOOMUCHMETADATA";
    break;
  case 0x88982F60:
    ans = L"WINCODEC_ERR_BADIMAGE";
    break;
  case 0x88982F61:
    ans = L"WINCODEC_ERR_BADHEADER";
    break;
  case 0x88982F62:
    ans = L"WINCODEC_ERR_FRAMEMISSING";
    break;
  case 0x88982F63:
    ans = L"WINCODEC_ERR_BADMETADATAHEADER";
    break;
  case 0x88982F70:
    ans = L"WINCODEC_ERR_BADSTREAMDATA";
    break;
  case 0x88982F71:
    ans = L"WINCODEC_ERR_STREAMWRITE";
    break;
  case 0x88982F72:
    ans = L"WINCODEC_ERR_STREAMREAD";
    break;
  case 0x88982F73:
    ans = L"WINCODEC_ERR_STREAMNOTAVAILABLE";
    break;
  case 0x88982F80:
    ans = L"WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT";
    break;
  case 0x88982F81:
    ans = L"WINCODEC_ERR_UNSUPPORTEDOPERATION";
    break;
  case 0x88982F8A:
    ans = L"WINCODEC_ERR_INVALIDREGISTRATION";
    break;
  case 0x88982F8B:
    ans = L"WINCODEC_ERR_COMPONENTINITIALIZEFAILURE";
    break;
  case 0x88982F8C:
    ans = L"WINCODEC_ERR_INSUFFICIENTBUFFER";
    break;
  case 0x88982F8D:
    ans = L"WINCODEC_ERR_DUPLICATEMETADATAPRESENT";
    break;
  case 0x88982F8E:
    ans = L"WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE";
    break;
  case 0x88982F8F:
    ans = L"WINCODEC_ERR_UNEXPECTEDSIZE";
    break;
  case 0x88982F90:
    ans = L"WINCODEC_ERR_INVALIDQUERYREQUEST";
    break;
  case 0x88982F91:
    ans = L"WINCODEC_ERR_UNEXPECTEDMETADATATYPE";
    break;
  case 0x88982F92:
    ans = L"WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT";
    break;
  case 0x88982F93:
    ans = L"WINCODEC_ERR_INVALIDQUERYCHARACTER";
    break;
  case 0x88982F94:
    ans = L"WINCODEC_ERR_WIN32ERROR";
    break;
  case 0x88982F95:
    ans = L"WINCODEC_ERR_INVALIDPROGRESSIVELEVEL";
    break;
  case 0x88982F96:
    ans = L"WINCODEC_ERR_INVALIDJPEGSCANINDEX";
    break;
  case 0x88980001:
    ans = L"MILERR_OBJECTBUSY";
    break;
  case 0x88980002:
    ans = L"MILERR_INSUFFICIENTBUFFER";
    break;
  case 0x88980003:
    ans = L"MILERR_WIN32ERROR";
    break;
  case 0x88980004:
    ans = L"MILERR_SCANNER_FAILED";
    break;
  case 0x88980005:
    ans = L"MILERR_SCREENACCESSDENIED";
    break;
  case 0x88980006:
    ans = L"MILERR_DISPLAYSTATEINVALID";
    break;
  case 0x88980007:
    ans = L"MILERR_NONINVERTIBLEMATRIX";
    break;
  case 0x88980008:
    ans = L"MILERR_ZEROVECTOR";
    break;
  case 0x88980009:
    ans = L"MILERR_TERMINATED";
    break;
  case 0x8898000A:
    ans = L"MILERR_BADNUMBER";
    break;
  case 0x88980080:
    ans = L"MILERR_INTERNALERROR";
    break;
  case 0x88980084:
    ans = L"MILERR_DISPLAYFORMATNOTSUPPORTED";
    break;
  case 0x88980085:
    ans = L"MILERR_INVALIDCALL";
    break;
  case 0x88980086:
    ans = L"MILERR_ALREADYLOCKED";
    break;
  case 0x88980087:
    ans = L"MILERR_NOTLOCKED";
    break;
  case 0x88980088:
    ans = L"MILERR_DEVICECANNOTRENDERTEXT";
    break;
  case 0x88980089:
    ans = L"MILERR_GLYPHBITMAPMISSED";
    break;
  case 0x8898008A:
    ans = L"MILERR_MALFORMEDGLYPHCACHE";
    break;
  case 0x8898008B:
    ans = L"MILERR_GENERIC_IGNORE";
    break;
  case 0x8898008C:
    ans = L"MILERR_MALFORMED_GUIDELINE_DATA";
    break;
  case 0x8898008D:
    ans = L"MILERR_NO_HARDWARE_DEVICE";
    break;
  case 0x8898008E:
    ans = L"MILERR_NEED_RECREATE_AND_PRESENT";
    break;
  case 0x8898008F:
    ans = L"MILERR_ALREADY_INITIALIZED";
    break;
  case 0x88980090:
    ans = L"MILERR_MISMATCHED_SIZE";
    break;
  case 0x88980091:
    ans = L"MILERR_NO_REDIRECTION_SURFACE_AVAILABLE";
    break;
  case 0x88980092:
    ans = L"MILERR_REMOTING_NOT_SUPPORTED";
    break;
  case 0x88980093:
    ans = L"MILERR_QUEUED_PRESENT_NOT_SUPPORTED";
    break;
  case 0x88980094:
    ans = L"MILERR_NOT_QUEUING_PRESENTS";
    break;
  case 0x88980095:
    ans = L"MILERR_NO_REDIRECTION_SURFACE_RETRY_LATER";
    break;
  case 0x88980096:
    ans = L"MILERR_TOOMANYSHADERELEMNTS";
    break;
  case 0x88980097:
    ans = L"MILERR_MROW_READLOCK_FAILED";
    break;
  case 0x88980098:
    ans = L"MILERR_MROW_UPDATE_FAILED";
    break;
  case 0x88980099:
    ans = L"MILERR_SHADER_COMPILE_FAILED";
    break;
  case 0x8898009A:
    ans = L"MILERR_MAX_TEXTURE_SIZE_EXCEEDED";
    break;
  case 0x8898009B:
    ans = L"MILERR_QPC_TIME_WENT_BACKWARD";
    break;
  case 0x8898009D:
    ans = L"MILERR_DXGI_ENUMERATION_OUT_OF_SYNC";
    break;
  case 0x8898009E:
    ans = L"MILERR_ADAPTER_NOT_FOUND";
    break;
  case 0x8898009F:
    ans = L"MILERR_COLORSPACE_NOT_SUPPORTED";
    break;
  case 0x889800A0:
    ans = L"MILERR_PREFILTER_NOT_SUPPORTED";
    break;
  case 0x889800A1:
    ans = L"MILERR_DISPLAYID_ACCESS_DENIED";
    break;
  case 0x88980400:
    ans = L"UCEERR_INVALIDPACKETHEADER";
    break;
  case 0x88980401:
    ans = L"UCEERR_UNKNOWNPACKET";
    break;
  case 0x88980402:
    ans = L"UCEERR_ILLEGALPACKET";
    break;
  case 0x88980403:
    ans = L"UCEERR_MALFORMEDPACKET";
    break;
  case 0x88980404:
    ans = L"UCEERR_ILLEGALHANDLE";
    break;
  case 0x88980405:
    ans = L"UCEERR_HANDLELOOKUPFAILED";
    break;
  case 0x88980406:
    ans = L"UCEERR_RENDERTHREADFAILURE";
    break;
  case 0x88980407:
    ans = L"UCEERR_CTXSTACKFRSTTARGETNULL";
    break;
  case 0x88980408:
    ans = L"UCEERR_CONNECTIONIDLOOKUPFAILED";
    break;
  case 0x88980409:
    ans = L"UCEERR_BLOCKSFULL";
    break;
  case 0x8898040A:
    ans = L"UCEERR_MEMORYFAILURE";
    break;
  case 0x8898040B:
    ans = L"UCEERR_PACKETRECORDOUTOFRANGE";
    break;
  case 0x8898040C:
    ans = L"UCEERR_ILLEGALRECORDTYPE";
    break;
  case 0x8898040D:
    ans = L"UCEERR_OUTOFHANDLES";
    break;
  case 0x8898040E:
    ans = L"UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED";
    break;
  case 0x8898040F:
    ans = L"UCEERR_NO_MULTIPLE_WORKER_THREADS";
    break;
  case 0x88980410:
    ans = L"UCEERR_REMOTINGNOTSUPPORTED";
    break;
  case 0x88980411:
    ans = L"UCEERR_MISSINGENDCOMMAND";
    break;
  case 0x88980412:
    ans = L"UCEERR_MISSINGBEGINCOMMAND";
    break;
  case 0x88980413:
    ans = L"UCEERR_CHANNELSYNCTIMEDOUT";
    break;
  case 0x88980414:
    ans = L"UCEERR_CHANNELSYNCABANDONED";
    break;
  case 0x88980415:
    ans = L"UCEERR_UNSUPPORTEDTRANSPORTVERSION";
    break;
  case 0x88980416:
    ans = L"UCEERR_TRANSPORTUNAVAILABLE";
    break;
  case 0x88980417:
    ans = L"UCEERR_FEEDBACK_UNSUPPORTED";
    break;
  case 0x88980418:
    ans = L"UCEERR_COMMANDTRANSPORTDENIED";
    break;
  case 0x88980419:
    ans = L"UCEERR_GRAPHICSSTREAMUNAVAILABLE";
    break;
  case 0x88980420:
    ans = L"UCEERR_GRAPHICSSTREAMALREADYOPEN";
    break;
  case 0x88980421:
    ans = L"UCEERR_TRANSPORTDISCONNECTED";
    break;
  case 0x88980422:
    ans = L"UCEERR_TRANSPORTOVERLOADED";
    break;
  case 0x88980423:
    ans = L"UCEERR_PARTITION_ZOMBIED";
    break;
  case 0x88980500:
    ans = L"MILAVERR_NOCLOCK";
    break;
  case 0x88980501:
    ans = L"MILAVERR_NOMEDIATYPE";
    break;
  case 0x88980502:
    ans = L"MILAVERR_NOVIDEOMIXER";
    break;
  case 0x88980503:
    ans = L"MILAVERR_NOVIDEOPRESENTER";
    break;
  case 0x88980504:
    ans = L"MILAVERR_NOREADYFRAMES";
    break;
  case 0x88980505:
    ans = L"MILAVERR_MODULENOTLOADED";
    break;
  case 0x88980506:
    ans = L"MILAVERR_WMPFACTORYNOTREGISTERED";
    break;
  case 0x88980507:
    ans = L"MILAVERR_INVALIDWMPVERSION";
    break;
  case 0x88980508:
    ans = L"MILAVERR_INSUFFICIENTVIDEORESOURCES";
    break;
  case 0x88980509:
    ans = L"MILAVERR_VIDEOACCELERATIONNOTAVAILABLE";
    break;
  case 0x8898050A:
    ans = L"MILAVERR_REQUESTEDTEXTURETOOBIG";
    break;
  case 0x8898050B:
    ans = L"MILAVERR_SEEKFAILED";
    break;
  case 0x8898050C:
    ans = L"MILAVERR_UNEXPECTEDWMPFAILURE";
    break;
  case 0x8898050D:
    ans = L"MILAVERR_MEDIAPLAYERCLOSED";
    break;
  case 0x8898050E:
    ans = L"MILAVERR_UNKNOWNHARDWAREERROR";
    break;
  case 0x8898060E:
    ans = L"MILEFFECTSERR_UNKNOWNPROPERTY";
    break;
  case 0x8898060F:
    ans = L"MILEFFECTSERR_EFFECTNOTPARTOFGROUP";
    break;
  case 0x88980610:
    ans = L"MILEFFECTSERR_NOINPUTSOURCEATTACHED";
    break;
  case 0x88980611:
    ans = L"MILEFFECTSERR_CONNECTORNOTCONNECTED";
    break;
  case 0x88980612:
    ans = L"MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT";
    break;
  case 0x88980613:
    ans = L"MILEFFECTSERR_RESERVED";
    break;
  case 0x88980614:
    ans = L"MILEFFECTSERR_CYCLEDETECTED";
    break;
  case 0x88980615:
    ans = L"MILEFFECTSERR_EFFECTINMORETHANONEGRAPH";
    break;
  case 0x88980616:
    ans = L"MILEFFECTSERR_EFFECTALREADYINAGRAPH";
    break;
  case 0x88980617:
    ans = L"MILEFFECTSERR_EFFECTHASNOCHILDREN";
    break;
  case 0x88980618:
    ans = L"MILEFFECTSERR_ALREADYATTACHEDTOLISTENER";
    break;
  case 0x88980619:
    ans = L"MILEFFECTSERR_NOTAFFINETRANSFORM";
    break;
  case 0x8898061A:
    ans = L"MILEFFECTSERR_EMPTYBOUNDS";
    break;
  case 0x8898061B:
    ans = L"MILEFFECTSERR_OUTPUTSIZETOOLARGE";
    break;
  case 0x88980700:
    ans = L"DWMERR_STATE_TRANSITION_FAILED";
    break;
  case 0x88980701:
    ans = L"DWMERR_THEME_FAILED";
    break;
  case 0x88980702:
    ans = L"DWMERR_CATASTROPHIC_FAILURE";
    break;
  case 0x88980800:
    ans = L"DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED";
    break;
  case 0x88980801:
    ans = L"DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED";
    break;
  case 0x88980802:
    ans = L"DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED";
    break;
  case 0x80860001:
    ans = L"ONL_E_INVALID_AUTHENTICATION_TARGET";
    break;
  case 0x80860002:
    ans = L"ONL_E_ACCESS_DENIED_BY_TOU";
    break;
  case 0x80860003:
    ans = L"ONL_E_INVALID_APPLICATION";
    break;
  case 0x80860004:
    ans = L"ONL_E_PASSWORD_UPDATE_REQUIRED";
    break;
  case 0x80860005:
    ans = L"ONL_E_ACCOUNT_UPDATE_REQUIRED";
    break;
  case 0x80860006:
    ans = L"ONL_E_FORCESIGNIN";
    break;
  case 0x80860007:
    ans = L"ONL_E_ACCOUNT_LOCKED";
    break;
  case 0x80860008:
    ans = L"ONL_E_PARENTAL_CONSENT_REQUIRED";
    break;
  case 0x80860009:
    ans = L"ONL_E_EMAIL_VERIFICATION_REQUIRED";
    break;
  case 0x8086000A:
    ans = L"ONL_E_ACCOUNT_SUSPENDED_COMPROIMISE";
    break;
  case 0x8086000B:
    ans = L"ONL_E_ACCOUNT_SUSPENDED_ABUSE";
    break;
  case 0x8086000C:
    ans = L"ONL_E_ACTION_REQUIRED";
    break;
  case 0x8086000D:
    ans = L"ONL_CONNECTION_COUNT_LIMIT";
    break;
  case 0x8086000E:
    ans = L"ONL_E_CONNECTED_ACCOUNT_CAN_NOT_SIGNOUT";
    break;
  case 0x8086000F:
    ans = L"ONL_E_USER_AUTHENTICATION_REQUIRED";
    break;
  case 0x80860010:
    ans = L"ONL_E_REQUEST_THROTTLED";
    break;
  case 0x80270220:
    ans = L"FA_E_MAX_PERSISTED_ITEMS_REACHED";
    break;
  case 0x80270222:
    ans = L"FA_E_HOMEGROUP_NOT_AVAILABLE";
    break;
  case 0x80270250:
    ans = L"E_MONITOR_RESOLUTION_TOO_LOW";
    break;
  case 0x80270251:
    ans = L"E_ELEVATED_ACTIVATION_NOT_SUPPORTED";
    break;
  case 0x80270252:
    ans = L"E_UAC_DISABLED";
    break;
  case 0x80270253:
    ans = L"E_FULL_ADMIN_NOT_SUPPORTED";
    break;
  case 0x80270254:
    ans = L"E_APPLICATION_NOT_REGISTERED";
    break;
  case 0x80270255:
    ans = L"E_MULTIPLE_EXTENSIONS_FOR_APPLICATION";
    break;
  case 0x80270256:
    ans = L"E_MULTIPLE_PACKAGES_FOR_FAMILY";
    break;
  case 0x80270257:
    ans = L"E_APPLICATION_MANAGER_NOT_RUNNING";
    break;
  case 0x00270258:
    ans = L"S_STORE_LAUNCHED_FOR_REMEDIATION";
    break;
  case 0x00270259:
    ans = L"S_APPLICATION_ACTIVATION_ERROR_HANDLED_BY_DIALOG";
    break;
  case 0x8027025A:
    ans = L"E_APPLICATION_ACTIVATION_TIMED_OUT";
    break;
  case 0x8027025B:
    ans = L"E_APPLICATION_ACTIVATION_EXEC_FAILURE";
    break;
  case 0x8027025C:
    ans = L"E_APPLICATION_TEMPORARY_LICENSE_ERROR";
    break;
  case 0x8027025D:
    ans = L"E_APPLICATION_TRIAL_LICENSE_EXPIRED";
    break;
  case 0x80270260:
    ans = L"E_SKYDRIVE_ROOT_TARGET_FILE_SYSTEM_NOT_SUPPORTED";
    break;
  case 0x80270261:
    ans = L"E_SKYDRIVE_ROOT_TARGET_OVERLAP";
    break;
  case 0x80270262:
    ans = L"E_SKYDRIVE_ROOT_TARGET_CANNOT_INDEX";
    break;
  case 0x80270263:
    ans = L"E_SKYDRIVE_FILE_NOT_UPLOADED";
    break;
  case 0x80270264:
    ans = L"E_SKYDRIVE_UPDATE_AVAILABILITY_FAIL";
    break;
  case 0x80270265:
    ans = L"E_SKYDRIVE_ROOT_TARGET_VOLUME_ROOT_NOT_SUPPORTED";
    break;
  case 0x8802B001:
    ans = L"E_SYNCENGINE_FILE_SIZE_OVER_LIMIT";
    break;
  case 0x8802B002:
    ans = L"E_SYNCENGINE_FILE_SIZE_EXCEEDS_REMAINING_QUOTA";
    break;
  case 0x8802B003:
    ans = L"E_SYNCENGINE_UNSUPPORTED_FILE_NAME";
    break;
  case 0x8802B004:
    ans = L"E_SYNCENGINE_FOLDER_ITEM_COUNT_LIMIT_EXCEEDED";
    break;
  case 0x8802B005:
    ans = L"E_SYNCENGINE_FILE_SYNC_PARTNER_ERROR";
    break;
  case 0x8802B006:
    ans = L"E_SYNCENGINE_SYNC_PAUSED_BY_SERVICE";
    break;
  case 0x8802C002:
    ans = L"E_SYNCENGINE_FILE_IDENTIFIER_UNKNOWN";
    break;
  case 0x8802C003:
    ans = L"E_SYNCENGINE_SERVICE_AUTHENTICATION_FAILED";
    break;
  case 0x8802C004:
    ans = L"E_SYNCENGINE_UNKNOWN_SERVICE_ERROR";
    break;
  case 0x8802C005:
    ans = L"E_SYNCENGINE_SERVICE_RETURNED_UNEXPECTED_SIZE";
    break;
  case 0x8802C006:
    ans = L"E_SYNCENGINE_REQUEST_BLOCKED_BY_SERVICE";
    break;
  case 0x8802C007:
    ans = L"E_SYNCENGINE_REQUEST_BLOCKED_DUE_TO_CLIENT_ERROR";
    break;
  case 0x8802D001:
    ans = L"E_SYNCENGINE_FOLDER_INACCESSIBLE";
    break;
  case 0x8802D002:
    ans = L"E_SYNCENGINE_UNSUPPORTED_FOLDER_NAME";
    break;
  case 0x8802D003:
    ans = L"E_SYNCENGINE_UNSUPPORTED_MARKET";
    break;
  case 0x8802D004:
    ans = L"E_SYNCENGINE_PATH_LENGTH_LIMIT_EXCEEDED";
    break;
  case 0x8802D005:
    ans = L"E_SYNCENGINE_REMOTE_PATH_LENGTH_LIMIT_EXCEEDED";
    break;
  case 0x8802D006:
    ans = L"E_SYNCENGINE_CLIENT_UPDATE_NEEDED";
    break;
  case 0x8802D007:
    ans = L"E_SYNCENGINE_PROXY_AUTHENTICATION_REQUIRED";
    break;
  case 0x8802D008:
    ans = L"E_SYNCENGINE_STORAGE_SERVICE_PROVISIONING_FAILED";
    break;
  case 0x8802D009:
    ans = L"E_SYNCENGINE_UNSUPPORTED_REPARSE_POINT";
    break;
  case 0x8802D00A:
    ans = L"E_SYNCENGINE_STORAGE_SERVICE_BLOCKED";
    break;
  case 0x8802D00B:
    ans = L"E_SYNCENGINE_FOLDER_IN_REDIRECTION";
    break;
  case 0x80550001:
    ans = L"EAS_E_POLICY_NOT_MANAGED_BY_OS";
    break;
  case 0x80550002:
    ans = L"EAS_E_POLICY_COMPLIANT_WITH_ACTIONS";
    break;
  case 0x80550003:
    ans = L"EAS_E_REQUESTED_POLICY_NOT_ENFORCEABLE";
    break;
  case 0x80550004:
    ans = L"EAS_E_CURRENT_USER_HAS_BLANK_PASSWORD";
    break;
  case 0x80550005:
    ans = L"EAS_E_REQUESTED_POLICY_PASSWORD_EXPIRATION_INCOMPATIBLE";
    break;
  case 0x80550006:
    ans = L"EAS_E_USER_CANNOT_CHANGE_PASSWORD";
    break;
  case 0x80550007:
    ans = L"EAS_E_ADMINS_HAVE_BLANK_PASSWORD";
    break;
  case 0x80550008:
    ans = L"EAS_E_ADMINS_CANNOT_CHANGE_PASSWORD";
    break;
  case 0x80550009:
    ans = L"EAS_E_LOCAL_CONTROLLED_USERS_CANNOT_CHANGE_PASSWORD";
    break;
  case 0x8055000A:
    ans = L"EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CONNECTED_ADMINS";
    break;
  case 0x8055000B:
    ans = L"EAS_E_CONNECTED_ADMINS_NEED_TO_CHANGE_PASSWORD";
    break;
  case 0x8055000C:
    ans = L"EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CURRENT_CONNECTED_USER";
    break;
  case 0x8055000D:
    ans = L"EAS_E_CURRENT_CONNECTED_USER_NEED_TO_CHANGE_PASSWORD";
    break;
  case 0x83750001:
    ans = L"WEB_E_UNSUPPORTED_FORMAT";
    break;
  case 0x83750002:
    ans = L"WEB_E_INVALID_XML";
    break;
  case 0x83750003:
    ans = L"WEB_E_MISSING_REQUIRED_ELEMENT";
    break;
  case 0x83750004:
    ans = L"WEB_E_MISSING_REQUIRED_ATTRIBUTE";
    break;
  case 0x83750005:
    ans = L"WEB_E_UNEXPECTED_CONTENT";
    break;
  case 0x83750006:
    ans = L"WEB_E_RESOURCE_TOO_LARGE";
    break;
  case 0x83750007:
    ans = L"WEB_E_INVALID_JSON_STRING";
    break;
  case 0x83750008:
    ans = L"WEB_E_INVALID_JSON_NUMBER";
    break;
  case 0x83750009:
    ans = L"WEB_E_JSON_VALUE_NOT_FOUND";
    break;
  case 0x80190001:
    ans = L"HTTP_E_STATUS_UNEXPECTED";
    break;
  case 0x80190003:
    ans = L"HTTP_E_STATUS_UNEXPECTED_REDIRECTION";
    break;
  case 0x80190004:
    ans = L"HTTP_E_STATUS_UNEXPECTED_CLIENT_ERROR";
    break;
  case 0x80190005:
    ans = L"HTTP_E_STATUS_UNEXPECTED_SERVER_ERROR";
    break;
  case 0x8019012C:
    ans = L"HTTP_E_STATUS_AMBIGUOUS";
    break;
  case 0x8019012D:
    ans = L"HTTP_E_STATUS_MOVED";
    break;
  case 0x8019012E:
    ans = L"HTTP_E_STATUS_REDIRECT";
    break;
  case 0x8019012F:
    ans = L"HTTP_E_STATUS_REDIRECT_METHOD";
    break;
  case 0x80190130:
    ans = L"HTTP_E_STATUS_NOT_MODIFIED";
    break;
  case 0x80190131:
    ans = L"HTTP_E_STATUS_USE_PROXY";
    break;
  case 0x80190133:
    ans = L"HTTP_E_STATUS_REDIRECT_KEEP_VERB";
    break;
  case 0x80190190:
    ans = L"HTTP_E_STATUS_BAD_REQUEST";
    break;
  case 0x80190191:
    ans = L"HTTP_E_STATUS_DENIED";
    break;
  case 0x80190192:
    ans = L"HTTP_E_STATUS_PAYMENT_REQ";
    break;
  case 0x80190193:
    ans = L"HTTP_E_STATUS_FORBIDDEN";
    break;
  case 0x80190194:
    ans = L"HTTP_E_STATUS_NOT_FOUND";
    break;
  case 0x80190195:
    ans = L"HTTP_E_STATUS_BAD_METHOD";
    break;
  case 0x80190196:
    ans = L"HTTP_E_STATUS_NONE_ACCEPTABLE";
    break;
  case 0x80190197:
    ans = L"HTTP_E_STATUS_PROXY_AUTH_REQ";
    break;
  case 0x80190198:
    ans = L"HTTP_E_STATUS_REQUEST_TIMEOUT";
    break;
  case 0x80190199:
    ans = L"HTTP_E_STATUS_CONFLICT";
    break;
  case 0x8019019A:
    ans = L"HTTP_E_STATUS_GONE";
    break;
  case 0x8019019B:
    ans = L"HTTP_E_STATUS_LENGTH_REQUIRED";
    break;
  case 0x8019019C:
    ans = L"HTTP_E_STATUS_PRECOND_FAILED";
    break;
  case 0x8019019D:
    ans = L"HTTP_E_STATUS_REQUEST_TOO_LARGE";
    break;
  case 0x8019019E:
    ans = L"HTTP_E_STATUS_URI_TOO_LONG";
    break;
  case 0x8019019F:
    ans = L"HTTP_E_STATUS_UNSUPPORTED_MEDIA";
    break;
  case 0x801901A0:
    ans = L"HTTP_E_STATUS_RANGE_NOT_SATISFIABLE";
    break;
  case 0x801901A1:
    ans = L"HTTP_E_STATUS_EXPECTATION_FAILED";
    break;
  case 0x801901F4:
    ans = L"HTTP_E_STATUS_SERVER_ERROR";
    break;
  case 0x801901F5:
    ans = L"HTTP_E_STATUS_NOT_SUPPORTED";
    break;
  case 0x801901F6:
    ans = L"HTTP_E_STATUS_BAD_GATEWAY";
    break;
  case 0x801901F7:
    ans = L"HTTP_E_STATUS_SERVICE_UNAVAIL";
    break;
  case 0x801901F8:
    ans = L"HTTP_E_STATUS_GATEWAY_TIMEOUT";
    break;
  case 0x801901F9:
    ans = L"HTTP_E_STATUS_VERSION_NOT_SUP";
    break;
  case 0x83760001:
    ans = L"E_INVALID_PROTOCOL_OPERATION";
    break;
  case 0x83760002:
    ans = L"E_INVALID_PROTOCOL_FORMAT";
    break;
  case 0x83760003:
    ans = L"E_PROTOCOL_EXTENSIONS_NOT_SUPPORTED";
    break;
  case 0x83760004:
    ans = L"E_SUBPROTOCOL_NOT_SUPPORTED";
    break;
  case 0x83760005:
    ans = L"E_PROTOCOL_VERSION_NOT_SUPPORTED";
    break;
  case 0x80400000:
    ans = L"INPUT_E_OUT_OF_ORDER";
    break;
  case 0x80400001:
    ans = L"INPUT_E_REENTRANCY";
    break;
  case 0x80400002:
    ans = L"INPUT_E_MULTIMODAL";
    break;
  case 0x80400003:
    ans = L"INPUT_E_PACKET";
    break;
  case 0x80400004:
    ans = L"INPUT_E_FRAME";
    break;
  case 0x80400005:
    ans = L"INPUT_E_HISTORY";
    break;
  case 0x80400006:
    ans = L"INPUT_E_DEVICE_INFO";
    break;
  case 0x80400007:
    ans = L"INPUT_E_TRANSFORM";
    break;
  case 0x80400008:
    ans = L"INPUT_E_DEVICE_PROPERTY";
    break;
  case 0x800C0002:
    ans = L"INET_E_INVALID_URL";
    break;
  case 0x800C0003:
    ans = L"INET_E_NO_SESSION";
    break;
  case 0x800C0004:
    ans = L"INET_E_CANNOT_CONNECT";
    break;
  case 0x800C0005:
    ans = L"INET_E_RESOURCE_NOT_FOUND";
    break;
  case 0x800C0006:
    ans = L"INET_E_OBJECT_NOT_FOUND";
    break;
  case 0x800C0007:
    ans = L"INET_E_DATA_NOT_AVAILABLE";
    break;
  case 0x800C0008:
    ans = L"INET_E_DOWNLOAD_FAILURE";
    break;
  case 0x800C0009:
    ans = L"INET_E_AUTHENTICATION_REQUIRED";
    break;
  case 0x800C000A:
    ans = L"INET_E_NO_VALID_MEDIA";
    break;
  case 0x800C000B:
    ans = L"INET_E_CONNECTION_TIMEOUT";
    break;
  case 0x800C000C:
    ans = L"INET_E_INVALID_REQUEST";
    break;
  case 0x800C000D:
    ans = L"INET_E_UNKNOWN_PROTOCOL";
    break;
  case 0x800C000E:
    ans = L"INET_E_SECURITY_PROBLEM";
    break;
  case 0x800C000F:
    ans = L"INET_E_CANNOT_LOAD_DATA";
    break;
  case 0x800C0010:
    ans = L"INET_E_CANNOT_INSTANTIATE_OBJECT";
    break;
  case 0x800C0019:
    ans = L"INET_E_INVALID_CERTIFICATE";
    break;
  case 0x800C0014:
    ans = L"INET_E_REDIRECT_FAILED";
    break;
  case 0x800C0015:
    ans = L"INET_E_REDIRECT_TO_DIR";
    break;
  case 0x80B00001:
    ans = L"ERROR_DBG_CREATE_PROCESS_FAILURE_LOCKDOWN";
    break;
  case 0x80B00002:
    ans = L"ERROR_DBG_ATTACH_PROCESS_FAILURE_LOCKDOWN";
    break;
  case 0x80B00003:
    ans = L"ERROR_DBG_CONNECT_SERVER_FAILURE_LOCKDOWN";
    break;
  case 0x80B00004:
    ans = L"ERROR_DBG_START_SERVER_FAILURE_LOCKDOWN";
    break;
  case 0x89010001:
    ans = L"ERROR_IO_PREEMPTED";
    break;
  case 0x89020001:
    ans = L"JSCRIPT_E_CANTEXECUTE";
    break;
  case 0x88010001:
    ans = L"WEP_E_NOT_PROVISIONED_ON_ALL_VOLUMES";
    break;
  case 0x88010002:
    ans = L"WEP_E_FIXED_DATA_NOT_SUPPORTED";
    break;
  case 0x88010003:
    ans = L"WEP_E_HARDWARE_NOT_COMPLIANT";
    break;
  case 0x88010004:
    ans = L"WEP_E_LOCK_NOT_CONFIGURED";
    break;
  case 0x88010005:
    ans = L"WEP_E_PROTECTION_SUSPENDED";
    break;
  case 0x88010006:
    ans = L"WEP_E_NO_LICENSE";
    break;
  case 0x88010007:
    ans = L"WEP_E_OS_NOT_PROTECTED";
    break;
  case 0x88010008:
    ans = L"WEP_E_UNEXPECTED_FAIL";
    break;
  case 0x88010009:
    ans = L"WEP_E_BUFFER_TOO_LARGE";
    break;
  case 0xC05C0000:
    ans = L"ERROR_SVHDX_ERROR_STORED";
    break;
  case 0xC05CFF00:
    ans = L"ERROR_SVHDX_ERROR_NOT_AVAILABLE";
    break;
  case 0xC05CFF01:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_AVAILABLE";
    break;
  case 0xC05CFF02:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED";
    break;
  case 0xC05CFF03:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED";
    break;
  case 0xC05CFF04:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED";
    break;
  case 0xC05CFF05:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED";
    break;
  case 0xC05CFF06:
    ans = L"ERROR_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED";
    break;
  case 0xC05CFF07:
    ans = L"ERROR_SVHDX_RESERVATION_CONFLICT";
    break;
  case 0xC05CFF08:
    ans = L"ERROR_SVHDX_WRONG_FILE_TYPE";
    break;
  case 0xC05CFF09:
    ans = L"ERROR_SVHDX_VERSION_MISMATCH";
    break;
  case 0xC05CFF0A:
    ans = L"ERROR_VHD_SHARED";
    break;
  case 0xC05CFF0B:
    ans = L"ERROR_SVHDX_NO_INITIATOR";
    break;
  case 0xC05CFF0C:
    ans = L"ERROR_VHDSET_BACKING_STORAGE_NOT_FOUND";
    break;
  case 0xC05D0000:
    ans = L"ERROR_SMB_NO_PREAUTH_INTEGRITY_HASH_OVERLAP";
    break;
  case 0xC05D0001:
    ans = L"ERROR_SMB_BAD_CLUSTER_DIALECT";
    break;
  case 0x80072EE1:
    ans = L"WININET_E_OUT_OF_HANDLES";
    break;
  case 0x80072EE2:
    ans = L"WININET_E_TIMEOUT";
    break;
  case 0x80072EE3:
    ans = L"WININET_E_EXTENDED_ERROR";
    break;
  case 0x80072EE4:
    ans = L"WININET_E_INTERNAL_ERROR";
    break;
  case 0x80072EE5:
    ans = L"WININET_E_INVALID_URL";
    break;
  case 0x80072EE6:
    ans = L"WININET_E_UNRECOGNIZED_SCHEME";
    break;
  case 0x80072EE7:
    ans = L"WININET_E_NAME_NOT_RESOLVED";
    break;
  case 0x80072EE8:
    ans = L"WININET_E_PROTOCOL_NOT_FOUND";
    break;
  case 0x80072EE9:
    ans = L"WININET_E_INVALID_OPTION";
    break;
  case 0x80072EEA:
    ans = L"WININET_E_BAD_OPTION_LENGTH";
    break;
  case 0x80072EEB:
    ans = L"WININET_E_OPTION_NOT_SETTABLE";
    break;
  case 0x80072EEC:
    ans = L"WININET_E_SHUTDOWN";
    break;
  case 0x80072EED:
    ans = L"WININET_E_INCORRECT_USER_NAME";
    break;
  case 0x80072EEE:
    ans = L"WININET_E_INCORRECT_PASSWORD";
    break;
  case 0x80072EEF:
    ans = L"WININET_E_LOGIN_FAILURE";
    break;
  case 0x80072EF0:
    ans = L"WININET_E_INVALID_OPERATION";
    break;
  case 0x80072EF1:
    ans = L"WININET_E_OPERATION_CANCELLED";
    break;
  case 0x80072EF2:
    ans = L"WININET_E_INCORRECT_HANDLE_TYPE";
    break;
  case 0x80072EF3:
    ans = L"WININET_E_INCORRECT_HANDLE_STATE";
    break;
  case 0x80072EF4:
    ans = L"WININET_E_NOT_PROXY_REQUEST";
    break;
  case 0x80072EF5:
    ans = L"WININET_E_REGISTRY_VALUE_NOT_FOUND";
    break;
  case 0x80072EF6:
    ans = L"WININET_E_BAD_REGISTRY_PARAMETER";
    break;
  case 0x80072EF7:
    ans = L"WININET_E_NO_DIRECT_ACCESS";
    break;
  case 0x80072EF8:
    ans = L"WININET_E_NO_CONTEXT";
    break;
  case 0x80072EF9:
    ans = L"WININET_E_NO_CALLBACK";
    break;
  case 0x80072EFA:
    ans = L"WININET_E_REQUEST_PENDING";
    break;
  case 0x80072EFB:
    ans = L"WININET_E_INCORRECT_FORMAT";
    break;
  case 0x80072EFC:
    ans = L"WININET_E_ITEM_NOT_FOUND";
    break;
  case 0x80072EFD:
    ans = L"WININET_E_CANNOT_CONNECT";
    break;
  case 0x80072EFE:
    ans = L"WININET_E_CONNECTION_ABORTED";
    break;
  case 0x80072EFF:
    ans = L"WININET_E_CONNECTION_RESET";
    break;
  case 0x80072F00:
    ans = L"WININET_E_FORCE_RETRY";
    break;
  case 0x80072F01:
    ans = L"WININET_E_INVALID_PROXY_REQUEST";
    break;
  case 0x80072F02:
    ans = L"WININET_E_NEED_UI";
    break;
  case 0x80072F04:
    ans = L"WININET_E_HANDLE_EXISTS";
    break;
  case 0x80072F05:
    ans = L"WININET_E_SEC_CERT_DATE_INVALID";
    break;
  case 0x80072F06:
    ans = L"WININET_E_SEC_CERT_CN_INVALID";
    break;
  case 0x80072F07:
    ans = L"WININET_E_HTTP_TO_HTTPS_ON_REDIR";
    break;
  case 0x80072F08:
    ans = L"WININET_E_HTTPS_TO_HTTP_ON_REDIR";
    break;
  case 0x80072F09:
    ans = L"WININET_E_MIXED_SECURITY";
    break;
  case 0x80072F0A:
    ans = L"WININET_E_CHG_POST_IS_NON_SECURE";
    break;
  case 0x80072F0B:
    ans = L"WININET_E_POST_IS_NON_SECURE";
    break;
  case 0x80072F0C:
    ans = L"WININET_E_CLIENT_AUTH_CERT_NEEDED";
    break;
  case 0x80072F0D:
    ans = L"WININET_E_INVALID_CA";
    break;
  case 0x80072F0E:
    ans = L"WININET_E_CLIENT_AUTH_NOT_SETUP";
    break;
  case 0x80072F0F:
    ans = L"WININET_E_ASYNC_THREAD_FAILED";
    break;
  case 0x80072F10:
    ans = L"WININET_E_REDIRECT_SCHEME_CHANGE";
    break;
  case 0x80072F11:
    ans = L"WININET_E_DIALOG_PENDING";
    break;
  case 0x80072F12:
    ans = L"WININET_E_RETRY_DIALOG";
    break;
  case 0x80072F13:
    ans = L"WININET_E_NO_NEW_CONTAINERS";
    break;
  case 0x80072F14:
    ans = L"WININET_E_HTTPS_HTTP_SUBMIT_REDIR";
    break;
  case 0x80072F17:
    ans = L"WININET_E_SEC_CERT_ERRORS";
    break;
  case 0x80072F19:
    ans = L"WININET_E_SEC_CERT_REV_FAILED";
    break;
  case 0x80072F76:
    ans = L"WININET_E_HEADER_NOT_FOUND";
    break;
  case 0x80072F77:
    ans = L"WININET_E_DOWNLEVEL_SERVER";
    break;
  case 0x80072F78:
    ans = L"WININET_E_INVALID_SERVER_RESPONSE";
    break;
  case 0x80072F79:
    ans = L"WININET_E_INVALID_HEADER";
    break;
  case 0x80072F7A:
    ans = L"WININET_E_INVALID_QUERY_REQUEST";
    break;
  case 0x80072F7B:
    ans = L"WININET_E_HEADER_ALREADY_EXISTS";
    break;
  case 0x80072F7C:
    ans = L"WININET_E_REDIRECT_FAILED";
    break;
  case 0x80072F7D:
    ans = L"WININET_E_SECURITY_CHANNEL_ERROR";
    break;
  case 0x80072F7E:
    ans = L"WININET_E_UNABLE_TO_CACHE_FILE";
    break;
  case 0x80072F7F:
    ans = L"WININET_E_TCPIP_NOT_INSTALLED";
    break;
  case 0x80072F83:
    ans = L"WININET_E_DISCONNECTED";
    break;
  case 0x80072F84:
    ans = L"WININET_E_SERVER_UNREACHABLE";
    break;
  case 0x80072F85:
    ans = L"WININET_E_PROXY_SERVER_UNREACHABLE";
    break;
  case 0x80072F86:
    ans = L"WININET_E_BAD_AUTO_PROXY_SCRIPT";
    break;
  case 0x80072F87:
    ans = L"WININET_E_UNABLE_TO_DOWNLOAD_SCRIPT";
    break;
  case 0x80072F89:
    ans = L"WININET_E_SEC_INVALID_CERT";
    break;
  case 0x80072F8A:
    ans = L"WININET_E_SEC_CERT_REVOKED";
    break;
  case 0x80072F8B:
    ans = L"WININET_E_FAILED_DUETOSECURITYCHECK";
    break;
  case 0x80072F8C:
    ans = L"WININET_E_NOT_INITIALIZED";
    break;
  case 0x80072F8E:
    ans = L"WININET_E_LOGIN_FAILURE_DISPLAY_ENTITY_BODY";
    break;
  case 0x80072F8F:
    ans = L"WININET_E_DECODING_FAILED";
    break;
  case 0x80072F80:
    ans = L"WININET_E_NOT_REDIRECTED";
    break;
  case 0x80072F81:
    ans = L"WININET_E_COOKIE_NEEDS_CONFIRMATION";
    break;
  case 0x80072F82:
    ans = L"WININET_E_COOKIE_DECLINED";
    break;
  case 0x80072F88:
    ans = L"WININET_E_REDIRECT_NEEDS_CONFIRMATION";
    break;
  case 0x87AF0001:
    ans = L"SQLITE_E_ERROR";
    break;
  case 0x87AF0002:
    ans = L"SQLITE_E_INTERNAL";
    break;
  case 0x87AF0003:
    ans = L"SQLITE_E_PERM";
    break;
  case 0x87AF0004:
    ans = L"SQLITE_E_ABORT";
    break;
  case 0x87AF0005:
    ans = L"SQLITE_E_BUSY";
    break;
  case 0x87AF0006:
    ans = L"SQLITE_E_LOCKED";
    break;
  case 0x87AF0007:
    ans = L"SQLITE_E_NOMEM";
    break;
  case 0x87AF0008:
    ans = L"SQLITE_E_READONLY";
    break;
  case 0x87AF0009:
    ans = L"SQLITE_E_INTERRUPT";
    break;
  case 0x87AF000A:
    ans = L"SQLITE_E_IOERR";
    break;
  case 0x87AF000B:
    ans = L"SQLITE_E_CORRUPT";
    break;
  case 0x87AF000C:
    ans = L"SQLITE_E_NOTFOUND";
    break;
  case 0x87AF000D:
    ans = L"SQLITE_E_FULL";
    break;
  case 0x87AF000E:
    ans = L"SQLITE_E_CANTOPEN";
    break;
  case 0x87AF000F:
    ans = L"SQLITE_E_PROTOCOL";
    break;
  case 0x87AF0010:
    ans = L"SQLITE_E_EMPTY";
    break;
  case 0x87AF0011:
    ans = L"SQLITE_E_SCHEMA";
    break;
  case 0x87AF0012:
    ans = L"SQLITE_E_TOOBIG";
    break;
  case 0x87AF0013:
    ans = L"SQLITE_E_CONSTRAINT";
    break;
  case 0x87AF0014:
    ans = L"SQLITE_E_MISMATCH";
    break;
  case 0x87AF0015:
    ans = L"SQLITE_E_MISUSE";
    break;
  case 0x87AF0016:
    ans = L"SQLITE_E_NOLFS";
    break;
  case 0x87AF0017:
    ans = L"SQLITE_E_AUTH";
    break;
  case 0x87AF0018:
    ans = L"SQLITE_E_FORMAT";
    break;
  case 0x87AF0019:
    ans = L"SQLITE_E_RANGE";
    break;
  case 0x87AF001A:
    ans = L"SQLITE_E_NOTADB";
    break;
  case 0x87AF001B:
    ans = L"SQLITE_E_NOTICE";
    break;
  case 0x87AF001C:
    ans = L"SQLITE_E_WARNING";
    break;
  case 0x87AF0064:
    ans = L"SQLITE_E_ROW";
    break;
  case 0x87AF0065:
    ans = L"SQLITE_E_DONE";
    break;
  case 0x87AF010A:
    ans = L"SQLITE_E_IOERR_READ";
    break;
  case 0x87AF020A:
    ans = L"SQLITE_E_IOERR_SHORT_READ";
    break;
  case 0x87AF030A:
    ans = L"SQLITE_E_IOERR_WRITE";
    break;
  case 0x87AF040A:
    ans = L"SQLITE_E_IOERR_FSYNC";
    break;
  case 0x87AF050A:
    ans = L"SQLITE_E_IOERR_DIR_FSYNC";
    break;
  case 0x87AF060A:
    ans = L"SQLITE_E_IOERR_TRUNCATE";
    break;
  case 0x87AF070A:
    ans = L"SQLITE_E_IOERR_FSTAT";
    break;
  case 0x87AF080A:
    ans = L"SQLITE_E_IOERR_UNLOCK";
    break;
  case 0x87AF090A:
    ans = L"SQLITE_E_IOERR_RDLOCK";
    break;
  case 0x87AF0A0A:
    ans = L"SQLITE_E_IOERR_DELETE";
    break;
  case 0x87AF0B0A:
    ans = L"SQLITE_E_IOERR_BLOCKED";
    break;
  case 0x87AF0C0A:
    ans = L"SQLITE_E_IOERR_NOMEM";
    break;
  case 0x87AF0D0A:
    ans = L"SQLITE_E_IOERR_ACCESS";
    break;
  case 0x87AF0E0A:
    ans = L"SQLITE_E_IOERR_CHECKRESERVEDLOCK";
    break;
  case 0x87AF0F0A:
    ans = L"SQLITE_E_IOERR_LOCK";
    break;
  case 0x87AF100A:
    ans = L"SQLITE_E_IOERR_CLOSE";
    break;
  case 0x87AF110A:
    ans = L"SQLITE_E_IOERR_DIR_CLOSE";
    break;
  case 0x87AF120A:
    ans = L"SQLITE_E_IOERR_SHMOPEN";
    break;
  case 0x87AF130A:
    ans = L"SQLITE_E_IOERR_SHMSIZE";
    break;
  case 0x87AF140A:
    ans = L"SQLITE_E_IOERR_SHMLOCK";
    break;
  case 0x87AF150A:
    ans = L"SQLITE_E_IOERR_SHMMAP";
    break;
  case 0x87AF160A:
    ans = L"SQLITE_E_IOERR_SEEK";
    break;
  case 0x87AF170A:
    ans = L"SQLITE_E_IOERR_DELETE_NOENT";
    break;
  case 0x87AF180A:
    ans = L"SQLITE_E_IOERR_MMAP";
    break;
  case 0x87AF190A:
    ans = L"SQLITE_E_IOERR_GETTEMPPATH";
    break;
  case 0x87AF1A0A:
    ans = L"SQLITE_E_IOERR_CONVPATH";
    break;
  case 0x87AF1A02:
    ans = L"SQLITE_E_IOERR_VNODE";
    break;
  case 0x87AF1A03:
    ans = L"SQLITE_E_IOERR_AUTH";
    break;
  case 0x87AF0106:
    ans = L"SQLITE_E_LOCKED_SHAREDCACHE";
    break;
  case 0x87AF0105:
    ans = L"SQLITE_E_BUSY_RECOVERY";
    break;
  case 0x87AF0205:
    ans = L"SQLITE_E_BUSY_SNAPSHOT";
    break;
  case 0x87AF010E:
    ans = L"SQLITE_E_CANTOPEN_NOTEMPDIR";
    break;
  case 0x87AF020E:
    ans = L"SQLITE_E_CANTOPEN_ISDIR";
    break;
  case 0x87AF030E:
    ans = L"SQLITE_E_CANTOPEN_FULLPATH";
    break;
  case 0x87AF040E:
    ans = L"SQLITE_E_CANTOPEN_CONVPATH";
    break;
  case 0x87AF010B:
    ans = L"SQLITE_E_CORRUPT_VTAB";
    break;
  case 0x87AF0108:
    ans = L"SQLITE_E_READONLY_RECOVERY";
    break;
  case 0x87AF0208:
    ans = L"SQLITE_E_READONLY_CANTLOCK";
    break;
  case 0x87AF0308:
    ans = L"SQLITE_E_READONLY_ROLLBACK";
    break;
  case 0x87AF0408:
    ans = L"SQLITE_E_READONLY_DBMOVED";
    break;
  case 0x87AF0204:
    ans = L"SQLITE_E_ABORT_ROLLBACK";
    break;
  case 0x87AF0113:
    ans = L"SQLITE_E_CONSTRAINT_CHECK";
    break;
  case 0x87AF0213:
    ans = L"SQLITE_E_CONSTRAINT_COMMITHOOK";
    break;
  case 0x87AF0313:
    ans = L"SQLITE_E_CONSTRAINT_FOREIGNKEY";
    break;
  case 0x87AF0413:
    ans = L"SQLITE_E_CONSTRAINT_FUNCTION";
    break;
  case 0x87AF0513:
    ans = L"SQLITE_E_CONSTRAINT_NOTNULL";
    break;
  case 0x87AF0613:
    ans = L"SQLITE_E_CONSTRAINT_PRIMARYKEY";
    break;
  case 0x87AF0713:
    ans = L"SQLITE_E_CONSTRAINT_TRIGGER";
    break;
  case 0x87AF0813:
    ans = L"SQLITE_E_CONSTRAINT_UNIQUE";
    break;
  case 0x87AF0913:
    ans = L"SQLITE_E_CONSTRAINT_VTAB";
    break;
  case 0x87AF0A13:
    ans = L"SQLITE_E_CONSTRAINT_ROWID";
    break;
  case 0x87AF011B:
    ans = L"SQLITE_E_NOTICE_RECOVER_WAL";
    break;
  case 0x87AF021B:
    ans = L"SQLITE_E_NOTICE_RECOVER_ROLLBACK";
    break;
  case 0x87AF011C:
    ans = L"SQLITE_E_WARNING_AUTOINDEX";
    break;
  case 0x87C51001:
    ans = L"UTC_E_TOGGLE_TRACE_STARTED";
    break;
  case 0x87C51002:
    ans = L"UTC_E_ALTERNATIVE_TRACE_CANNOT_PREEMPT";
    break;
  case 0x87C51003:
    ans = L"UTC_E_AOT_NOT_RUNNING";
    break;
  case 0x87C51004:
    ans = L"UTC_E_SCRIPT_TYPE_INVALID";
    break;
  case 0x87C51005:
    ans = L"UTC_E_SCENARIODEF_NOT_FOUND";
    break;
  case 0x87C51006:
    ans = L"UTC_E_TRACEPROFILE_NOT_FOUND";
    break;
  case 0x87C51007:
    ans = L"UTC_E_FORWARDER_ALREADY_ENABLED";
    break;
  case 0x87C51008:
    ans = L"UTC_E_FORWARDER_ALREADY_DISABLED";
    break;
  case 0x87C51009:
    ans = L"UTC_E_EVENTLOG_ENTRY_MALFORMED";
    break;
  case 0x87C5100A:
    ans = L"UTC_E_DIAGRULES_SCHEMAVERSION_MISMATCH";
    break;
  case 0x87C5100B:
    ans = L"UTC_E_SCRIPT_TERMINATED";
    break;
  case 0x87C5100C:
    ans = L"UTC_E_INVALID_CUSTOM_FILTER";
    break;
  case 0x87C5100D:
    ans = L"UTC_E_TRACE_NOT_RUNNING";
    break;
  case 0x87C5100E:
    ans = L"UTC_E_REESCALATED_TOO_QUICKLY";
    break;
  case 0x87C5100F:
    ans = L"UTC_E_ESCALATION_ALREADY_RUNNING";
    break;
  case 0x87C51010:
    ans = L"UTC_E_PERFTRACK_ALREADY_TRACING";
    break;
  case 0x87C51011:
    ans = L"UTC_E_REACHED_MAX_ESCALATIONS";
    break;
  case 0x87C51012:
    ans = L"UTC_E_FORWARDER_PRODUCER_MISMATCH";
    break;
  case 0x87C51013:
    ans = L"UTC_E_INTENTIONAL_SCRIPT_FAILURE";
    break;
  case 0x87C51014:
    ans = L"UTC_E_SQM_INIT_FAILED";
    break;
  case 0x87C51015:
    ans = L"UTC_E_NO_WER_LOGGER_SUPPORTED";
    break;
  case 0x87C51016:
    ans = L"UTC_E_TRACERS_DONT_EXIST";
    break;
  case 0x87C51017:
    ans = L"UTC_E_WINRT_INIT_FAILED";
    break;
  case 0x87C51018:
    ans = L"UTC_E_SCENARIODEF_SCHEMAVERSION_MISMATCH";
    break;
  case 0x87C51019:
    ans = L"UTC_E_INVALID_FILTER";
    break;
  case 0x87C5101A:
    ans = L"UTC_E_EXE_TERMINATED";
    break;
  case 0x87C5101B:
    ans = L"UTC_E_ESCALATION_NOT_AUTHORIZED";
    break;
  case 0x87C5101C:
    ans = L"UTC_E_SETUP_NOT_AUTHORIZED";
    break;
  case 0x87C5101D:
    ans = L"UTC_E_CHILD_PROCESS_FAILED";
    break;
  case 0x87C5101E:
    ans = L"UTC_E_COMMAND_LINE_NOT_AUTHORIZED";
    break;
  case 0x87C5101F:
    ans = L"UTC_E_CANNOT_LOAD_SCENARIO_EDITOR_XML";
    break;
  case 0x87C51020:
    ans = L"UTC_E_ESCALATION_TIMED_OUT";
    break;
  case 0x87C51021:
    ans = L"UTC_E_SETUP_TIMED_OUT";
    break;
  case 0x87C51022:
    ans = L"UTC_E_TRIGGER_MISMATCH";
    break;
  case 0x87C51023:
    ans = L"UTC_E_TRIGGER_NOT_FOUND";
    break;
  case 0x87C51024:
    ans = L"UTC_E_SIF_NOT_SUPPORTED";
    break;
  case 0x87C51025:
    ans = L"UTC_E_DELAY_TERMINATED";
    break;
  case 0x87C51026:
    ans = L"UTC_E_DEVICE_TICKET_ERROR";
    break;
  case 0x87C51027:
    ans = L"UTC_E_TRACE_BUFFER_LIMIT_EXCEEDED";
    break;
  case 0x87C51028:
    ans = L"UTC_E_API_RESULT_UNAVAILABLE";
    break;
  case 0x87C51029:
    ans = L"UTC_E_RPC_TIMEOUT";
    break;
  case 0x87C5102A:
    ans = L"UTC_E_RPC_WAIT_FAILED";
    break;
  case 0x87C5102B:
    ans = L"UTC_E_API_BUSY";
    break;
  case 0x87C5102C:
    ans = L"UTC_E_TRACE_MIN_DURATION_REQUIREMENT_NOT_MET";
    break;
  case 0x87C5102D:
    ans = L"UTC_E_EXCLUSIVITY_NOT_AVAILABLE";
    break;
  case 0x87C5102E:
    ans = L"UTC_E_GETFILE_FILE_PATH_NOT_APPROVED";
    break;
  case 0x87C5102F:
    ans = L"UTC_E_ESCALATION_DIRECTORY_ALREADY_EXISTS";
    break;
  case 0x87C51030:
    ans = L"UTC_E_TIME_TRIGGER_ON_START_INVALID";
    break;
  case 0x87C51031:
    ans = L"UTC_E_TIME_TRIGGER_ONLY_VALID_ON_SINGLE_TRANSITION";
    break;
  case 0x87C51032:
    ans = L"UTC_E_TIME_TRIGGER_INVALID_TIME_RANGE";
    break;
  case 0x87C51033:
    ans = L"UTC_E_MULTIPLE_TIME_TRIGGER_ON_SINGLE_STATE";
    break;
  case 0x87C51034:
    ans = L"UTC_E_BINARY_MISSING";
    break;
  case 0x87C51035:
    ans = L"UTC_E_NETWORK_CAPTURE_NOT_ALLOWED";
    break;
  case 0x87C51036:
    ans = L"UTC_E_FAILED_TO_RESOLVE_CONTAINER_ID";
    break;
  case 0x87C51037:
    ans = L"UTC_E_UNABLE_TO_RESOLVE_SESSION";
    break;
  case 0x87C51038:
    ans = L"UTC_E_THROTTLED";
    break;
  case 0x87C51039:
    ans = L"UTC_E_UNAPPROVED_SCRIPT";
    break;
  case 0x87C5103A:
    ans = L"UTC_E_SCRIPT_MISSING";
    break;
  case 0x87C5103B:
    ans = L"UTC_E_SCENARIO_THROTTLED";
    break;
  case 0x87C5103C:
    ans = L"UTC_E_API_NOT_SUPPORTED";
    break;
  case 0x87C5103D:
    ans = L"UTC_E_GETFILE_EXTERNAL_PATH_NOT_APPROVED";
    break;
  case 0x87C5103E:
    ans = L"UTC_E_TRY_GET_SCENARIO_TIMEOUT_EXCEEDED";
    break;
  case 0x87C5103F:
    ans = L"UTC_E_CERT_REV_FAILED";
    break;
  case 0x87C51040:
    ans = L"UTC_E_FAILED_TO_START_NDISCAP";
    break;
  case 0x87C51041:
    ans = L"UTC_E_KERNELDUMP_LIMIT_REACHED";
    break;
  case 0x87C51042:
    ans = L"UTC_E_MISSING_AGGREGATE_EVENT_TAG";
    break;
  case 0x87C51043:
    ans = L"UTC_E_INVALID_AGGREGATION_STRUCT";
    break;
  case 0x87C51044:
    ans = L"UTC_E_ACTION_NOT_SUPPORTED_IN_DESTINATION";
    break;
  case 0x87C51045:
    ans = L"UTC_E_FILTER_MISSING_ATTRIBUTE";
    break;
  case 0x87C51046:
    ans = L"UTC_E_FILTER_INVALID_TYPE";
    break;
  case 0x87C51047:
    ans = L"UTC_E_FILTER_VARIABLE_NOT_FOUND";
    break;
  case 0x87C51048:
    ans = L"UTC_E_FILTER_FUNCTION_RESTRICTED";
    break;
  case 0x87C51049:
    ans = L"UTC_E_FILTER_VERSION_MISMATCH";
    break;
  case 0x87C51050:
    ans = L"UTC_E_FILTER_INVALID_FUNCTION";
    break;
  case 0x87C51051:
    ans = L"UTC_E_FILTER_INVALID_FUNCTION_PARAMS";
    break;
  case 0x87C51052:
    ans = L"UTC_E_FILTER_INVALID_COMMAND";
    break;
  case 0x87C51053:
    ans = L"UTC_E_FILTER_ILLEGAL_EVAL";
    break;
  case 0x87C51054:
    ans = L"UTC_E_TTTRACER_RETURNED_ERROR";
    break;
  case 0x87C51055:
    ans = L"UTC_E_AGENT_DIAGNOSTICS_TOO_LARGE";
    break;
  case 0x87C51056:
    ans = L"UTC_E_FAILED_TO_RECEIVE_AGENT_DIAGNOSTICS";
    break;
  case 0x87C51057:
    ans = L"UTC_E_SCENARIO_HAS_NO_ACTIONS";
    break;
  case 0x87C51058:
    ans = L"UTC_E_TTTRACER_STORAGE_FULL";
    break;
  case 0x87C51059:
    ans = L"UTC_E_INSUFFICIENT_SPACE_TO_START_TRACE";
    break;
  case 0x87C5105A:
    ans = L"UTC_E_ESCALATION_CANCELLED_AT_SHUTDOWN";
    break;
  case 0x87C5105B:
    ans = L"UTC_E_GETFILEINFOACTION_FILE_NOT_APPROVED";
    break;
  case 0x88900001:
    ans = L"WINML_ERR_INVALID_DEVICE";
    break;
  case 0x88900002:
    ans = L"WINML_ERR_INVALID_BINDING";
    break;
  case 0x88900003:
    ans = L"WINML_ERR_VALUE_NOTFOUND";
    break;
  case 0x88900004:
    ans = L"WINML_ERR_SIZE_MISMATCH";
    break;
  default:
    ans = L"Undefined Error Code";
    break;
  };
  return ans;
};


LPCWSTR get_ndstatus_symbol(HRESULT hr) {
  LPCWSTR ans;
  switch (hr) {
  case ND_SUCCESS:
    ans = L"ND_SUCCESS";
    break;
  case ND_TIMEOUT:
    ans = L"ND_TIMEOUT";
    break;
  case ND_PENDING:
    ans = L"ND_PENDING";
    break;
  case ND_BUFFER_OVERFLOW:
    ans = L"ND_BUFFER_OVERFLOW";
    break;
  case ND_DEVICE_BUSY:
    ans = L"ND_DEVICE_BUSY";
    break;
  case ND_NO_MORE_ENTRIES:
    ans = L"ND_NO_MORE_ENTRIES";
    break;
  case ND_UNSUCCESSFUL:
    ans = L"ND_UNSUCCESSFUL";
    break;
  case ND_ACCESS_VIOLATION:
    ans = L"ND_ACCESS_VIOLATION";
    break;
  case ND_INVALID_HANDLE:
    ans = L"ND_INVALID_HANDLE";
    break;
  case ND_INVALID_DEVICE_REQUEST:
    ans = L"ND_INVALID_DEVICE_REQUEST";
    break;
  case ND_INVALID_PARAMETER:
    ans = L"ND_INVALID_PARAMETER";
    break;
  case ND_NO_MEMORY:
    ans = L"ND_NO_MEMORY";
    break;
  case ND_INVALID_PARAMETER_MIX:
    ans = L"ND_INVALID_PARAMETER_MIX";
    break;
  case ND_DATA_OVERRUN:
    ans = L"ND_DATA_OVERRUN";
    break;
  case ND_SHARING_VIOLATION:
    ans = L"ND_SHARING_VIOLATION";
    break;
  case ND_INSUFFICIENT_RESOURCES:
    ans = L"ND_INSUFFICIENT_RESOURCES";
    break;
  case ND_DEVICE_NOT_READY:
    ans = L"ND_DEVICE_NOT_READY";
    break;
  case ND_IO_TIMEOUT:
    ans = L"ND_IO_TIMEOUT";
    break;
  case ND_NOT_SUPPORTED:
    ans = L"ND_NOT_SUPPORTED";
    break;
  case ND_INTERNAL_ERROR:
    ans = L"ND_INTERNAL_ERROR";
    break;
  case ND_INVALID_PARAMETER_1:
    ans = L"ND_INVALID_PARAMETER_1";
    break;
  case ND_INVALID_PARAMETER_2:
    ans = L"ND_INVALID_PARAMETER_2";
    break;
  case ND_INVALID_PARAMETER_3:
    ans = L"ND_INVALID_PARAMETER_3";
    break;
  case ND_INVALID_PARAMETER_4:
    ans = L"ND_INVALID_PARAMETER_4";
    break;
  case ND_INVALID_PARAMETER_5:
    ans = L"ND_INVALID_PARAMETER_5";
    break;
  case ND_INVALID_PARAMETER_6:
    ans = L"ND_INVALID_PARAMETER_6";
    break;
  case ND_INVALID_PARAMETER_7:
    ans = L"ND_INVALID_PARAMETER_7";
    break;
  case ND_INVALID_PARAMETER_8:
    ans = L"ND_INVALID_PARAMETER_8";
    break;
  case ND_INVALID_PARAMETER_9:
    ans = L"ND_INVALID_PARAMETER_9";
    break;
  case ND_INVALID_PARAMETER_10:
    ans = L"ND_INVALID_PARAMETER_10";
    break;
  case ND_CANCELED:
    ans = L"ND_CANCELED";
    break;
  case ND_REMOTE_ERROR:
    ans = L"ND_REMOTE_ERROR";
    break;
  case ND_INVALID_ADDRESS:
    ans = L"ND_INVALID_ADDRESS";
    break;
  case ND_INVALID_DEVICE_STATE:
    ans = L"ND_INVALID_DEVICE_STATE";
    break;
  case ND_INVALID_BUFFER_SIZE:
    ans = L"ND_INVALID_BUFFER_SIZE";
    break;
  case ND_TOO_MANY_ADDRESSES:
    ans = L"ND_TOO_MANY_ADDRESSES";
    break;
  case ND_ADDRESS_ALREADY_EXISTS:
    ans = L"ND_ADDRESS_ALREADY_EXISTS";
    break;
  case ND_CONNECTION_REFUSED:
    ans = L"ND_CONNECTION_REFUSED";
    break;
  case ND_CONNECTION_INVALID:
    ans = L"ND_CONNECTION_INVALID";
    break;
  case ND_CONNECTION_ACTIVE:
    ans = L"ND_CONNECTION_ACTIVE";
    break;
  case ND_NETWORK_UNREACHABLE:
    ans = L"ND_NETWORK_UNREACHABLE";
    break;
  case ND_HOST_UNREACHABLE:
    ans = L"ND_HOST_UNREACHABLE";
    break;
  case ND_CONNECTION_ABORTED:
    ans = L"ND_CONNECTION_ABORTED";
    break;
  case ND_DEVICE_REMOVED:
    ans = L"ND_DEVICE_REMOVED";
    break;
  default:
    ans = 0;
    break;
  };
  return ans;
};
